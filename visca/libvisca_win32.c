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

uint32_t
_VISCA_write_packet_data(VISCAInterface_t *iface, VISCACamera_t *camera, VISCAPacket_t *packet)
{
  DWORD iBytesWritten;
  WriteFile(iface->port_fd, packet->bytes, packet->length, &iBytesWritten, NULL);
  if ( iBytesWritten < packet->length )
      return VISCA_FAILURE;
  else
      return VISCA_SUCCESS;
}



uint32_t
_VISCA_send_packet(VISCAInterface_t *iface, VISCACamera_t *camera, VISCAPacket_t *packet)
{
  DWORD iBytesWritten;
  static long bytesTogether = 0;
  BOOL rVal = 0;
  DWORD errors;
  COMSTAT stat;
  int nTrials;

  // check data:
  if ((iface->address>7)||(camera->address>7)||(iface->broadcast>1))
    {
	  _RPTF3(_CRT_WARN,"Invalid header parameters %d %d %d\n",iface->address,camera->address,iface->broadcast);
	  return VISCA_FAILURE;
    }

  // build header:
  packet->bytes[0]=0x80;
  packet->bytes[0]|=(iface->address << 4);
  if (iface->broadcast>0)
    {
      packet->bytes[0]|=(iface->broadcast << 3);
      packet->bytes[0]&=0xF8;
    }
  else
    packet->bytes[0]|=camera->address;
    
  // append footer
  _VISCA_append_byte(packet,VISCA_TERMINATOR);

  for (nTrials = 0; nTrials < 3 && rVal == 0; nTrials++) {
    if (nTrials > 0)
      ClearCommError(iface->port_fd, &errors, &stat);
	rVal = WriteFile(iface->port_fd, &packet->bytes, packet->length, &iBytesWritten, NULL);
  }

  if ( iBytesWritten < packet->length )
    {
      DWORD lastError = GetLastError();
      return VISCA_FAILURE;
    }
  else {
    bytesTogether += iBytesWritten;
    return VISCA_SUCCESS;
  }
}


uint32_t
_VISCA_get_packet(VISCAInterface_t *iface)
{
  int pos=0;
  BOOL  rc;
  DWORD iBytesRead;

  // wait for message
  rc=ReadFile(iface->port_fd, iface->ibuf, 1, &iBytesRead, NULL);
  if ( !rc || iBytesRead==0 )
  {
      // Obtain the error code
      //m_lLastError = ::GetLastError();
	  _RPTF0(_CRT_WARN,"ReadFile failed.\n");
      return VISCA_FAILURE;
  }
  while (iface->ibuf[pos]!=VISCA_TERMINATOR) {
    if ( ++pos >= VISCA_INPUT_BUFFER_SIZE )
	{
        // Obtain the error code
        //m_lLastError = ::GetLastError();
  	    _RPTF0(_CRT_WARN,"illegal reply packet.\n");
        return VISCA_FAILURE;
    }
    rc=ReadFile(iface->port_fd, iface->ibuf + pos, 1, &iBytesRead, NULL);
	if ( !rc || iBytesRead==0 )
	{
        // Obtain the error code
        //m_lLastError = ::GetLastError();
	  _RPTF0(_CRT_WARN,"ReadFile failed.\n");
        return VISCA_FAILURE;
    }
  }
  iface->bytes=pos+1;

  return VISCA_SUCCESS;
}



/***********************************/
/*       SYSTEM  FUNCTIONS         */
/***********************************/

uint32_t
VISCA_open_serial(VISCAInterface_t *iface, const char *device_name)
{
  BOOL     m_bPortReady;
  HANDLE   m_hCom;
  DCB      m_dcb;
  COMMTIMEOUTS cto;
  
  m_hCom = CreateFile(device_name, 
		      GENERIC_READ | GENERIC_WRITE,
		      0, // exclusive access
		      NULL, // no security
		      OPEN_EXISTING,
		      0, // no overlapped I/O
		      NULL); // null template
  
  // Check the returned handle for INVALID_HANDLE_VALUE and then set the buffer sizes.
  if (m_hCom == INVALID_HANDLE_VALUE) 
  {
	_RPTF1(_CRT_WARN,"cannot open serial device %s\n",device_name);
	iface->port_fd = NULL;
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
  m_dcb.fOutxCtsFlow = FALSE;		     // Disable CTS monitoring
  m_dcb.fOutxDsrFlow = FALSE;		     // Disable DSR monitoring
  m_dcb.fDtrControl = DTR_CONTROL_DISABLE;   // Disable DTR monitoring
  m_dcb.fOutX = FALSE;			     // Disable XON/XOFF for transmission
  m_dcb.fInX = FALSE;			     // Disable XON/XOFF for receiving
  m_dcb.fRtsControl = RTS_CONTROL_DISABLE;   // Disable RTS (Ready To Send)
  m_dcb.fBinary = TRUE;			     // muss immer "TRUE" sein!
  m_dcb.fErrorChar = FALSE;
  m_dcb.fNull = FALSE;
  // =========================================
 
  m_bPortReady = SetCommState(m_hCom, &m_dcb);
  

  // =========================================
  // (jd) set timeout 
  if (!GetCommTimeouts(m_hCom,&cto))
  {
      // Obtain the error code
      //m_lLastError = ::GetLastError();
      _RPTF0(_CRT_WARN,"unable to obtain timeout information\n");
      CloseHandle(m_hCom);
      return VISCA_FAILURE;
  }
  cto.ReadIntervalTimeout = 100;		     /* 20ms would be good, but 100 are for usb-rs232 */
  cto.ReadTotalTimeoutConstant = 2000;	     /* 2s  */
  cto.ReadTotalTimeoutMultiplier = 50;	     /* 50ms for each char */
  cto.WriteTotalTimeoutMultiplier = 500;
  cto.WriteTotalTimeoutConstant = 1000;
  if (!SetCommTimeouts(m_hCom,&cto))
  {
      // Obtain the error code
      //m_lLastError = ::GetLastError();
      _RPTF0(_CRT_WARN,"unable to setup timeout information\n");
      CloseHandle(m_hCom);
      return VISCA_FAILURE;
  }
  // =========================================

  // If all of these API's were successful then the port is ready for use.
  iface->port_fd = m_hCom;
  iface->address = 0;

  return VISCA_SUCCESS;
}

uint32_t
VISCA_unread_bytes(VISCAInterface_t *iface, unsigned char *buffer, uint32_t *buffer_size)
{
  // TODO
  *buffer_size = 0;
  return VISCA_SUCCESS;
}

uint32_t
VISCA_close_serial(VISCAInterface_t *iface)
{
  if (iface->port_fd != NULL)
    {
      CloseHandle(iface->port_fd);
      iface->port_fd = NULL;
      return VISCA_SUCCESS;
    }
  else
    return VISCA_FAILURE;
}

uint32_t
VISCA_usleep(uint32_t useconds)
{
  uint32_t microsecs = useconds / 1000;
  Sleep (microsecs);
  return 0;
}

