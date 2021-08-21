#include "libvisca.h"

#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

typedef struct _VISCA_serial_ctx {
	HANDLE port_fd;
} VISCA_serial_ctx_t;

static int visca_serial_cb_write(VISCAInterface_t *iface, const void *buf, int length)
{
	VISCA_serial_ctx_t *ctx = iface->ctx;
	DWORD iBytesWritten;
	WriteFile(ctx->port_fd, buf, length, &iBytesWritten, NULL);
	return (int)iBytesWritten;
}

static void visca_serial_cb_clear_error(VISCAInterface_t *iface)
{
	VISCA_serial_ctx_t *ctx = iface->ctx;
	DWORD errors;
	COMSTAT stat;
	ClearCommError(ctx->port_fd, &errors, &stat);
}

static int visca_serial_cb_read(VISCAInterface_t *iface, void *buf, int length)
{
	VISCA_serial_ctx_t *ctx = iface->ctx;
	DWORD iBytesRead;
	BOOL rc = ReadFile(ctx->port_fd, iface->ibuf, 1, &iBytesRead, NULL);
	if (!rc)
		return -1;
	return (int)iBytesRead;
}

static int visca_serial_cb_close(VISCAInterface_t *iface)
{
	if (!iface || !iface->ctx)
		return VISCA_FAILURE;
	VISCA_serial_ctx_t *ctx = iface->ctx;

	if (ctx->port_fd != NULL) {
		CloseHandle(ctx->port_fd);
		free(ctx);
		return VISCA_SUCCESS;
	} else
		return VISCA_FAILURE;
}

static VISCA_callback_t visca_serial_cb = {
	.write = visca_serial_cb_write,
	.read = visca_serial_cb_read,
	.clear_error = visca_serial_cb_clear_error,
	.close = visca_serial_cb_close,
};

uint32_t VISCA_open_serial(VISCAInterface_t *iface, const char *device_name)
{
	BOOL m_bPortReady;
	HANDLE m_hCom;
	DCB m_dcb;
	COMMTIMEOUTS cto;
	VISCA_serial_ctx_t *ctx = calloc(1, sizeof(VISCA_serial_ctx_t));

	m_hCom = CreateFile(device_name, GENERIC_READ | GENERIC_WRITE,
			    0,    // exclusive access
			    NULL, // no security
			    OPEN_EXISTING,
			    0,     // no overlapped I/O
			    NULL); // null template

	// Check the returned handle for INVALID_HANDLE_VALUE and then set the buffer sizes.
	if (m_hCom == INVALID_HANDLE_VALUE) {
		_RPTF1(_CRT_WARN, "cannot open serial device %s\n", device_name);
		iface->ctx = NULL;
		free(ctx);
		return VISCA_FAILURE;
	}

	m_bPortReady = SetupComm(m_hCom, 4, 4); // set buffer sizes

	// Port settings are specified in a Data Communication Block (DCB). The easiest way to initialize a DCB is to call GetCommState to fill in its default values, override the values that you want to change and then call SetCommState to set the values.
	m_bPortReady = GetCommState(m_hCom, &m_dcb);
	m_dcb.BaudRate = 9600;
	m_dcb.ByteSize = 8;
	m_dcb.Parity = NOPARITY;
	m_dcb.StopBits = ONESTOPBIT;
	m_dcb.fAbortOnError = TRUE;

	// =========================================
	// (jd) added to get a complete setup...
	m_dcb.fOutxCtsFlow = FALSE;              // Disable CTS monitoring
	m_dcb.fOutxDsrFlow = FALSE;              // Disable DSR monitoring
	m_dcb.fDtrControl = DTR_CONTROL_DISABLE; // Disable DTR monitoring
	m_dcb.fOutX = FALSE;                     // Disable XON/XOFF for transmission
	m_dcb.fInX = FALSE;                      // Disable XON/XOFF for receiving
	m_dcb.fRtsControl = RTS_CONTROL_DISABLE; // Disable RTS (Ready To Send)
	m_dcb.fBinary = TRUE;                    // muss immer "TRUE" sein!
	m_dcb.fErrorChar = FALSE;
	m_dcb.fNull = FALSE;
	// =========================================

	m_bPortReady = SetCommState(m_hCom, &m_dcb);

	// =========================================
	// (jd) set timeout
	if (!GetCommTimeouts(m_hCom, &cto)) {
		// Obtain the error code
		//m_lLastError = ::GetLastError();
		_RPTF0(_CRT_WARN, "unable to obtain timeout information\n");
		CloseHandle(m_hCom);
		iface->ctx = NULL;
		free(ctx);
		return VISCA_FAILURE;
	}
	cto.ReadIntervalTimeout = 100;       /* 20ms would be good, but 100 are for usb-rs232 */
	cto.ReadTotalTimeoutConstant = 2000; /* 2s  */
	cto.ReadTotalTimeoutMultiplier = 50; /* 50ms for each char */
	cto.WriteTotalTimeoutMultiplier = 500;
	cto.WriteTotalTimeoutConstant = 1000;
	if (!SetCommTimeouts(m_hCom, &cto)) {
		// Obtain the error code
		//m_lLastError = ::GetLastError();
		_RPTF0(_CRT_WARN, "unable to setup timeout information\n");
		CloseHandle(m_hCom);
		iface->ctx = NULL;
		free(ctx);
		return VISCA_FAILURE;
	}
	// =========================================

	// If all of these API's were successful then the port is ready for use.
	ctx->port_fd = m_hCom;
	iface->address = 0;
	iface->ctx = ctx;

	return VISCA_SUCCESS;
}
