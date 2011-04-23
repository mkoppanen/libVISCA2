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


#include <string.h>
#include <errno.h>

#include "config.h"
#include "system.h"
#include "v24.h"
#include "debugging.h"
#include "libvisca.h"


uint32_t
_VISCA_write_packet_data(VISCAInterface_t *iface, VISCACamera_t *camera, VISCAPacket_t *packet)
{
    int i;

    for ( i=0; i<packet->length; ++i )
    {
	v24Putc(iface->port_fd, packet->bytes[i]);
    }
    return VISCA_SUCCESS;
}



uint32_t
_VISCA_send_packet(VISCAInterface_t *iface, VISCACamera_t *camera, VISCAPacket_t *packet)
{
    // check data:
    if ((iface->address>7)||(camera->address>7)||(iface->broadcast>1))
    {
#ifdef DEBUG
	dbg_ReportStrP(PSTR("_VISCA_send_packet: bad header parms\n"));
#endif
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

    return _VISCA_write_packet_data(iface,camera,packet);
}


uint32_t
_VISCA_get_packet(VISCAInterface_t *iface)
{
    int pos=0;
    int curr;

    // get octets one by one
    curr = v24Getc(iface->port_fd);
    if ( curr<0 )
    {
#ifdef DEBUG
	dbg_ReportStrP(PSTR("_VISCA_get_packet: timeout\n"));
#endif	
	return VISCA_FAILURE;
    }
    iface->ibuf[pos]=(BYTE)curr;
    while ( iface->ibuf[pos]!=VISCA_TERMINATOR )
    {
	if ( ++pos >= VISCA_INPUT_BUFFER_SIZE )
	{
#ifdef DEBUG
	    dbg_ReportStrP(PSTR("_VISCA_get_packet: overflow\n"));
#endif	
	    return VISCA_FAILURE;
	}
	curr = v24Getc(iface->port_fd);
	if ( curr<0 )
	{
#ifdef DEBUG
	    dbg_ReportStrP(PSTR("_VISCA_get_packet: timeout\n"));
#endif	
	    return VISCA_FAILURE;
	}
	iface->ibuf[pos]=(BYTE)curr;
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
    /* Hey, this is a microcontroller. We don't have UART device names. ;-)
     *
     * The used already opened
     */
    if ( !iface || !device_name )
    {
#ifdef DEBUG
	dbg_ReportStrP(PSTR("VISCA_open_serial: bad parms\n"));
#endif
	return VISCA_FAILURE;
    }

    iface->port_fd = UART_VISCA;
    iface->address=0;

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
    if ( !iface )
    {
#ifdef DEBUG
	dbg_ReportStrP(PSTR("_VISCA_close_serial: bad header parms\n"));
#endif
	return VISCA_FAILURE;
    }
    if (iface->port_fd!=0xFF)
    {

	/* Hey, this is a microcontroller. The port must be closed outside this
	 * function call.
	 */
	iface->port_fd = 0xFF;
	return VISCA_SUCCESS;
    }
    else
	return VISCA_FAILURE;
}

uint32_t
VISCA_usleep(uint32_t useconds)
{
  return (uint32_t) usleep(useconds);
}

