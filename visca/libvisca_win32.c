/*
 * VISCA(tm) Camera Control Library
 * Copyright (C) 2002 Damien Douxchamps 
 *
 * Written by Damien Douxchamps <ddouxchamps@users.sf.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "libvisca.h"

#include <windows.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

/* implemented in libvisca.c
 */
void _VISCA_append_byte(VISCAPacket_t *packet, unsigned char byte);
void _VISCA_init_packet(VISCAPacket_t *packet);
unsigned int _VISCA_get_reply(VISCAInterface_t *iface, VISCACamera_t *camera);
unsigned int _VISCA_send_packet_with_reply(VISCAInterface_t *iface, VISCACamera_t *camera, VISCAPacket_t *packet);

/* Implementation of the platform specific code. The following functions must
 * be implemented here:
 *
 * unsigned int _VISCA_write_packet_data(VISCAInterface_t *iface, VISCACamera_t *camera, VISCAPacket_t *packet);
 * unsigned int _VISCA_send_packet(VISCAInterface_t *iface, VISCACamera_t *camera, VISCAPacket_t *packet);
 * unsigned int _VISCA_get_packet(VISCAInterface_t *iface);
 * unsigned int VISCA_open_serial(VISCAInterface_t *iface, const char *device_name);
 * unsigned int VISCA_close_serial(VISCAInterface_t *iface);
 * 
 */

uint32_t _VISCA_write_packet_data(VISCAInterface_t *iface, VISCACamera_t *camera, VISCAPacket_t *packet)
{
	DWORD iBytesWritten = iface->callback->write(iface, packet->bytes, packet->length);
	if (iBytesWritten < packet->length)
		return VISCA_FAILURE;
	else
		return VISCA_SUCCESS;
}

uint32_t _VISCA_send_packet(VISCAInterface_t *iface, VISCACamera_t *camera, VISCAPacket_t *packet)
{
	DWORD iBytesWritten;
	static long bytesTogether = 0;
	int nTrials;

	// check data:
	if ((iface->address > 7) || (camera->address > 7) || (iface->broadcast > 1)) {
		_RPTF3(_CRT_WARN, "Invalid header parameters %d %d %d\n", iface->address, camera->address,
		       iface->broadcast);
		return VISCA_FAILURE;
	}

	// build header:
	packet->bytes[0] = 0x80;
	packet->bytes[0] |= (iface->address << 4);
	if (iface->broadcast > 0) {
		packet->bytes[0] |= (iface->broadcast << 3);
		packet->bytes[0] &= 0xF8;
	} else
		packet->bytes[0] |= camera->address;

	// append footer
	_VISCA_append_byte(packet, VISCA_TERMINATOR);

	for (nTrials = 0; nTrials < 3 && iBytesWritten != packet->length; nTrials++) {
		if (nTrials > 0 && iface->callback->clear_error)
			iface->callback->clear_error(iface);
		iBytesWritten = iface->callback->write(iface, &packet->bytes, packet->length);
	}

	if (iBytesWritten < packet->length) {
		DWORD lastError = GetLastError();
		return VISCA_FAILURE;
	} else {
		bytesTogether += iBytesWritten;
		return VISCA_SUCCESS;
	}
}

uint32_t _VISCA_get_packet(VISCAInterface_t *iface)
{
	int pos = 0;
	int iBytesRead;

	// wait for message
	iBytesRead = iface->callback->read(iface, iface->ibuf, 1);
	if (iBytesRead <= 0) {
		// Obtain the error code
		//m_lLastError = ::GetLastError();
		_RPTF0(_CRT_WARN, "ReadFile failed.\n");
		return VISCA_FAILURE;
	}
	while (iface->ibuf[pos] != VISCA_TERMINATOR) {
		if (++pos >= VISCA_INPUT_BUFFER_SIZE) {
			// Obtain the error code
			//m_lLastError = ::GetLastError();
			_RPTF0(_CRT_WARN, "illegal reply packet.\n");
			return VISCA_FAILURE;
		}
		iBytesRead = iface->callback->read(iface, iface->ibuf + pos, 1);
		if (iBytesRead <= 0) {
			// Obtain the error code
			//m_lLastError = ::GetLastError();
			_RPTF0(_CRT_WARN, "ReadFile failed.\n");
			return VISCA_FAILURE;
		}
	}
	iface->bytes = pos + 1;

	return VISCA_SUCCESS;
}

/***********************************/
/*       SYSTEM  FUNCTIONS         */
/***********************************/

uint32_t VISCA_usleep(uint32_t useconds)
{
	uint32_t microsecs = useconds / 1000;
	Sleep(microsecs);
	return 0;
}
