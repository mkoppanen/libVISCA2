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
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/ioctl.h>

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
    int err;

    err = write(iface->port_fd, packet->bytes, packet->length);
    if ( err < packet->length )
	return VISCA_FAILURE;
    else
	return VISCA_SUCCESS;
}



uint32_t
_VISCA_send_packet(VISCAInterface_t *iface, VISCACamera_t *camera, VISCAPacket_t *packet)
{
    // check data:
    if ((iface->address>7)||(camera->address>7)||(iface->broadcast>1))
    {
#if DEBUG
	fprintf(stderr,"(%s): Invalid header parameters\n",__FILE__);
	fprintf(stderr," %d %d %d   \n",iface->address,camera->address,iface->broadcast);
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
    int pos = 0;
    int timeout_counter = 0;
    int bytes_read;

    // wait for message
    do
    {
        ioctl(iface->port_fd, FIONREAD, &(iface->bytes));
        usleep(0);
        if (timeout_counter++ > 20000) {
            return VISCA_FAILURE;
        }
    } while (iface->bytes == 0);

    // get octets one by one
    bytes_read = read(iface->port_fd, iface->ibuf, 1);
    while (iface->ibuf[pos] != VISCA_TERMINATOR)
    {
        if (++pos >= VISCA_INPUT_BUFFER_SIZE) {
            return VISCA_FAILURE;
        }
        bytes_read = read(iface->port_fd, &iface->ibuf[pos], 1);
        usleep(0);
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
  int fd;
  fd = open(device_name, O_RDWR | O_NDELAY | O_NOCTTY);

  if (fd == -1)
    {
#if DEBUG
      fprintf(stderr,"(%s): cannot open serial device %s\n",__FILE__,device_name);
#endif
      iface->port_fd=-1;
      return VISCA_FAILURE;
    }	
  else
    {
      fcntl(fd, F_SETFL,0);
      /* Setting port parameters */
      tcgetattr(fd, &iface->options);

      /* control flags */
      cfsetispeed(&iface->options,B9600);    /* 9600 Bds   */
      iface->options.c_cflag &= ~PARENB;     /* No parity  */
      iface->options.c_cflag &= ~CSTOPB;     /*            */
      iface->options.c_cflag &= ~CSIZE;      /* 8bit       */
      iface->options.c_cflag |= CS8;         /*            */
      iface->options.c_cflag &= ~CRTSCTS;    /* No hdw ctl */

      /* local flags */
      iface->options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); /* raw input */

      /* input flags */
      /*
      iface->options.c_iflag &= ~(INPCK | ISTRIP); // no parity
      iface->options.c_iflag &= ~(IXON | IXOFF | IXANY); // no soft ctl
      */
      /* patch: bpflegin: set to 0 in order to avoid invalid pan/tilt return values */
      iface->options.c_iflag = 0;

      /* output flags */
      iface->options.c_oflag &= ~OPOST; /* raw output */

      tcsetattr(fd, TCSANOW, &iface->options);

    }
  iface->port_fd = fd;
  iface->address=0;

  return VISCA_SUCCESS;
}

uint32_t
VISCA_unread_bytes(VISCAInterface_t *iface, unsigned char *buffer, uint32_t *buffer_size)
{
  uint32_t bytes = 0;
  *buffer_size = 0;

  ioctl(iface->port_fd, FIONREAD, &bytes);
  if (bytes>0)
    {
      bytes = (bytes>*buffer_size) ? *buffer_size : bytes;
      read(iface->port_fd, &buffer, bytes);
      *buffer_size = bytes;
      return VISCA_FAILURE;
    }
  return VISCA_SUCCESS;
}

uint32_t
VISCA_close_serial(VISCAInterface_t *iface)
{
  if (iface->port_fd!=-1)
    {
      close(iface->port_fd);
      iface->port_fd = -1;
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
