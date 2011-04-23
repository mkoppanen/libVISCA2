/*
 * VISCA(tm) Camera Control Library Test Program
 * Copyright (C) 2002 Damien Douxchamps 
 *
 * Written by Damien Douxchamps <douxchamps@ieee.org>
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

#include "../visca/libvisca.h"
#include <stdlib.h>
#include <stdio.h>

#include <fcntl.h> /* File control definitions */
#include <errno.h> /* Error number definitions */

#define EVI_D30

int main(int argc, char **argv)
{

  VISCAInterface_t iface;
  VISCACamera_t camera;


  int camera_num;
  uint8_t value;
  uint16_t zoom;
  int pan_pos, tilt_pos;

  if (argc<2)
    {
      fprintf(stderr,"%s usage: %s <serial port device>\n",argv[0],argv[0]);
      exit(1);
    }

  if (VISCA_open_serial(&iface, argv[1])!=VISCA_SUCCESS)
    {
      fprintf(stderr,"%s: unable to open serial device %s\n",argv[0],argv[1]);
      exit(1);
    }

  iface.broadcast=0;
  VISCA_set_address(&iface, &camera_num);
  camera.address=1;
  VISCA_clear(&iface, &camera);

  VISCA_get_camera_info(&iface, &camera);
  fprintf(stderr,"Some camera info:\n------------------\n");
  fprintf(stderr,"vendor: 0x%04x\n model: 0x%04x\n ROM version: 0x%04x\n socket number: 0x%02x\n",
	  camera.vendor, camera.model, camera.rom_version, camera.socket_num);

  VISCA_usleep(500000);

  if (VISCA_set_zoom_value(&iface, &camera, 0x0000)!=VISCA_SUCCESS)
    fprintf(stderr,"error setting zoom\n");

  VISCA_usleep(500000);

  if (VISCA_set_zoom_value(&iface, &camera, 0x4000)!=VISCA_SUCCESS)
    fprintf(stderr,"error setting zoom\n");

  VISCA_usleep(500000);

  if (VISCA_set_zoom_value(&iface, &camera, 0x1234)!=VISCA_SUCCESS)
    fprintf(stderr,"error setting zoom\n");

  if (VISCA_get_zoom_value(&iface, &camera, &zoom)!=VISCA_SUCCESS)
    fprintf(stderr,"error getting zoom\n");
  else
    fprintf(stderr,"Zoom value: 0x%04x\n",zoom);

  VISCA_usleep(500000);

  if (VISCA_set_zoom_value(&iface, &camera, 0x0000)!=VISCA_SUCCESS)
    fprintf(stderr,"error setting zoom\n");


  if (VISCA_get_power(&iface, &camera, &value)!=VISCA_SUCCESS)
    fprintf(stderr,"error getting power\n");
  else
    fprintf(stderr,"power status: 0x%02x\n",value);


#ifdef EVI_D30
  if (VISCA_set_pantilt_reset(&iface, &camera)!=VISCA_SUCCESS)
    fprintf(stderr,"error setting pan tilt home\n");
  else
    fprintf(stderr,"Setting pan tilt home\n");

  if (VISCA_set_pantilt_absolute_position(&iface, &camera,5,5,-500,-200)!=VISCA_SUCCESS)
    fprintf(stderr,"error setting pan tilt absolute position with negative position\n");
  else
    fprintf(stderr,"Setting pan tilt absolute position\n");

  
  if (VISCA_get_pantilt_position(&iface, &camera, &pan_pos, &tilt_pos)!=VISCA_SUCCESS)
    fprintf(stderr,"error getting pan tilt absolute position\n");
  else
    fprintf(stderr,"Absolute position, Pan value: %d, Tilt value: %d\n",pan_pos,tilt_pos);


  if (VISCA_set_pantilt_absolute_position(&iface, &camera,18,14,500,200)!=VISCA_SUCCESS)
    fprintf(stderr,"error setting pan tilt absolute position with positive position\n");
  else
    fprintf(stderr,"Setting pan tilt absolute position\n");

  if (VISCA_get_pantilt_position(&iface, &camera, &pan_pos, &tilt_pos)!=VISCA_SUCCESS)
    fprintf(stderr,"error getting pan tilt absolute position\n");
  else
    fprintf(stderr,"Absolute position, Pan value: %d, Tilt value: %d\n",pan_pos,tilt_pos);


  if (VISCA_set_pantilt_home(&iface, &camera)!=VISCA_SUCCESS)
    fprintf(stderr,"error setting pan tilt home\n");
  else
    fprintf(stderr,"Setting pan tilt home\n");

#endif

  //if (VISCA_set_power(&iface, &camera, VISCA_ON)!=VISCA_SUCCESS)
  //  fprintf(stderr,"error setting power\n");

  // read the rest of the data: (should be empty)

  VISCA_set_zoom_value(&iface, &camera, 0x0D00);
  VISCA_set_shutter_value(&iface, &camera, 0x0D00);

  {
    unsigned char packet[3000];
    uint32_t buffer_size = 3000;
    if (VISCA_unread_bytes(&iface, packet, &buffer_size)!=VISCA_SUCCESS)
    {
      uint32_t i;
      fprintf(stderr, "ERROR: %u bytes not processed", buffer_size);
      for (i=0;i<buffer_size;i++)
        fprintf(stderr,"%2x ",packet[i]);
      fprintf(stderr,"\n");
    }
  }
  VISCA_close_serial(&iface);
  exit(0);
}
