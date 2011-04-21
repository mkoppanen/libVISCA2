/*
 * Command line interface to the VISCA(tm) Camera Control Library
 * based on the VISCA(tm) Camera Control Library Test Program
 * by Damien Douxchamps 
 * 
 * Copyright (C) 2003 Simon Bichler 
 * 
 * Written by Simon Bichler <bichlesi@in.tum.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/*
Commands without parameter:
===========================
set_zoom_tele            (set the zoom to maximum)
set_zoom_wide            (set the zoom to minimum)
set_zoom_stop            (stop zooming)
set_focus_far            (set the focus to far)
set_focus_near           (set the focus to near)
set_focus_stop           (stop focusing)
set_focus_one_push       (not for D30)
set_focus_infinity       (not for D30)
set_focus_autosense_high (not for D30)
set_focus_autosense_low  (not for D30)
set_whitebal_one_push    (push trigger for whitebalance in OnePush mode)
set_rgain_up             (not for D30)
set_rgain_down           (not for D30)
set_rgain_reset          (not for D30)
set_bgain_up             (not for D30)
set_bgain_down           (not for D30)
set_bgain_reset          (not for D30)
set_shutter_up           (increase the shutter speed, available only with 
                          shutter_priority or AE_Manual)
set_shutter_down         (decrease the shutter speed, available only with 
                          shutter_priority or AE_Manual)
set_shutter_reset        (reset the shutter speed, available only with 
                          shutter_priority or AE_Manual)
set_iris_up              (open up the iris, available only with 
                          iris_priority or AE_Manual)
set_iris_down            (close the iris, available only with 
                          iris_priority or AE_Manual)
set_iris_reset           (reset the iris, available only with 
                          iris_priority or AE_Manual)
set_gain_up              (increase the gain, available only with AE_Manual)
set_gain_down            (decrease the gain, available only with AE_Manual)
set_gain_reset           (reset the gain, available only with AE_Manual)
set_bright_up            (brighten the image, available only with bright_mode)
set_bright_down          (darken the image, available only with bright_mode)
set_bright_reset         (reset the image brightness, 
                          available only with bright_mode)
set_aperture_up          (not for D30)
set_aperture_down        (not for D30)
set_aperture_reset       (not for D30)
set_exp_comp_up          (not for D30)
set_exp_comp_down        (not for D30)
set_exp_comp_reset       (not for D30)
set_title_clear          (not for D30)
set_irreceive_on         (enable IR remote controller)
set_irreceive_off        (disable IR remote controller)
set_irreceive_onoff      (toggle IR remote controller)
set_pantilt_home         (set pan/tilt position to center)
set_pantilt_reset        (initialize pan/tilt motors)
set_pantilt_limit_downleft_clear (remove pan/tilt limits 
                                  for lower left position)
set_pantilt_limit_upright_clear (remove pan/tilt limits 
                                 for upper right position)
set_datascreen_on         (show data display)
set_datascreen_off        (hide data display)
set_datascreen_onoff      (toggle data display)

Commands with one boolean parameter (0|1):
==========================================
set_power             (set standby power state)
set_keylock           (set or release keylock)
set_dzoom             (not for D30)
set_focus_auto        (turn autofocus on or off)
set_exp_comp_power    (not for D30)
set_slow_shutter_auto (not for D30)
set_backlight_comp    (turn backlight compensation on or off)
set_zero_lux_shot     (not for D30)
set_ir_led            (not for D30)
set_mirror            (not for D30)
set_freeze            (not for D30)
set_display           (not for D30)
set_date_display      (not for D30)
set_time_display      (not for D30)
set_title_display     (not for D30)

Commands with one integer parameter:
====================================
set_zoom_tele_speed <speed>      (set the zoom to maximum with a speed 
                                  between 2 and 7)
set_zoom_wide_speed <speed>      (set the zoom to minimum with a speed 
                                  between 2 and 7)
set_zoom_value <zoom>            (set the zoom to the given value 
                                  between 0 and 1023)
set_focus_far_speed <speed>      (not for D30)
set_focus_near_speed <speed>     (not for D30)
set_focus_value <focus>          (set the focus to the given value 
                                  between 1000 and 40959)
set_focus_near_limit <limit>     (not for D30)
set_whitebal_mode <mode>         (set the whitebalance mode to 
                                  0: Auto, 1: Indoor, 2: Outdoor, 3: OnePush)
set_rgain_value <value>          (not for D30)
set_bgain_value <value>          (not for D30)
set_shutter_value <value>        (set the shutter value between 
                                  0: 1/60 and 27: 1/10000)
set_iris_value <value>           (set the iris opening to a value 
                                  between 0: closed and 17: F1.8)
set_gain_value <value>           (set the gain value between 
                                  1: 0dB and 7: +18dB)
set_bright_value <value>         (not for D30)
set_aperture_value <value>       (not for D30)
set_exp_comp_value <value>       (not for D30)
set_auto_exp_mode <mode>         (set the AE mode to 0: Full Auto, 3: Manual, 
                                  10: Shutter priority, 11: Iris priority, 
				  13: Bright Mode)
set_wide_mode <mode>             (not for D30)
set_picture_effect <mode>        (not for D30)
set_digital_effect <mode>        (not for D30)
set_digital_effect_level <level> (not for D30)
memory_set <channel>             (save the current position to channel 0 to 5)
memory_recall <channel>          (recall the current position from 
                                  channel 0 to 5)
memory_reset <channel>           (reset a channel 0 to 5)

Commands with two integer parameters:
=====================================
set_zoom_and_focus_value <zoom> <focus>             (not for D30, 
                                                     zoom 0 to 1023, 
						     focus 1000 to 40959)
set_pantilt_up <pan_speed> <tilt_speed>             (move up, 
                                                     pan_speed from 1 to 24, 
						     tilt speed from 1 to 20)
set_pantilt_down <pan_speed> <tilt_speed>           (move down,
                                                     pan_speed from 1 to 24, 
						     tilt speed from 1 to 20)
set_pantilt_left <pan_speed> <tilt_speed>           (move left,
                                                     pan_speed from 1 to 24, 
						     tilt speed from 1 to 20)
set_pantilt_right <pan_speed> <tilt_speed>          (move right, 
                                                     pan_speed from 1 to 24, 
						     tilt speed from 1 to 20)
set_pantilt_upleft <pan_speed> <tilt_speed>         (move up and left, 
                                                     pan_speed from 1 to 24, 
						     tilt speed from 1 to 20)
set_pantilt_upright <pan_speed> <tilt_speed>        (move up and right, 
                                                     pan_speed from 1 to 24, 
						     tilt speed from 1 to 20)
set_pantilt_downleft <pan_speed> <tilt_speed>       (move down and left, 
                                                     pan_speed from 1 to 24, 
						     tilt speed from 1 to 20)
set_pantilt_downright <pan_speed> <tilt_speed>      (move down and right, 
                                                     pan_speed from 1 to 24, 
						     tilt speed from 1 to 20)
set_pantilt_stop <pan_speed> <tilt_speed>           (stop moving, 
                                                     pan_speed from 1 to 24, 
						     tilt speed from 1 to 20)
set_pantilt_limit_upright <pan_limit> <tilt_limit>  (limit movement 
                                                     upper right corner, 
						     pan limit: -879 to 880, 
						     tilt limit: -299 to 300)
set_pantilt_limit_downleft <pan_limit> <tilt_limit> (limit movement 
                                                     lower left corner, 
						     pan limit: -879 to 880, 
						     tilt limit: -299 to 300)

Commands with four integer parameters:
======================================
set_pantilt_absolute_position <pan_speed> <tilt_speed>        
                              <pan_position> <tilt_position> (set position,
                                                     pan_speed from 1 to 24, 
						     tilt speed from 1 to 20,
						     pan_pos: -879 to 880, 
						     tilt_pos: -299 to 300)
set_pantilt_relative_position <pan_speed> <tilt_speed> 
                              <pan_position> <tilt_position> (set position,
                                                     pan_speed from 1 to 24, 
						     tilt speed from 1 to 20,
						     pan_pos: -879 to 880, 
						     tilt_pos: -299 to 300)
set_title_params <vposition> <hposition> <color> <blink> (not for D30, 
                                                          set title params)

Commands with five parameters:
==============================
set_date_time <year> <month> <day> <hour> <minute>       (not for D30, 
                                                          set date and time)
set_title <vposition> <hposition> <color> <blink> <text> (not for D30, 
                                                          set title params
                                                          and title text)

Commands that return one boolean value:
=======================================
get_power          (returns 1 if in standby mode, 0 otherwise)
get_dzoom          (not for D30)
get_focus_auto     (returns 1 if autofocus, 0 otherwise)
get_exp_comp_power (not for D30)
get_backlight_comp (returns 1 if backlight compensation is on, 0 otherwise)
get_zero_lux_shot  (not for D30)
get_ir_led         (not for D30)
get_mirror         (not for D30)
get_freeze         (not for D30)
get_display        (not for D30)
get_datascreen     (returns 1 if a datascreen is displayed, 0 otherwise)

Commands that return one integer value:
=======================================
get_zoom_value           (returns a value between 0 and 1023)
get_focus_value          (returns a value between 1000 and 40959)
get_focus_auto_sense     (not for D30)
get_focus_near_limit     (not for D30)
get_whitebal_mode        (returns the whitebalance mode: 
                          0: Auto, 1: Indoor, 2: Outdoor, 3: OnePush)
get_rgain_value          (not for D30)
get_bgain_value          (not for D30)
get_auto_exp_mode        (returns the auto exposure mode:
                           0: Full Auto, 3: Manual,
                          10: Shutter priority, 11: Iris priority, 
                          13: Bright Mode)
get_slow_shutter_auto    (not for D30)
get_shutter_value        (returns the shutter value between 
                          0: 1/60 and 27: 1/10000)
get_iris_value           (returns the iris value between 
                          0: closed and 17: F1.8
get_gain_value           (returns the gain value between 1: 0dB and 7: +18dB)
get_bright_value         (not for D30)
get_exp_comp_value       (not for D30)
get_aperture_value       (not for D30)
get_wide_mode            (not for D30)
get_picture_effect       (not for D30)
get_digital_effect       (not for D30)
get_digital_effect_level (not for D30)
get_memory               (returns the current memory preset position 0 to 5)
get_id                   (returns the camera id)
get_videosystem          (returns the video sytstem: 0 for NTSC, 1 for PAL)
get_pantilt_mode         (returns the pantilt status, what is this?)

Commands that return two integer values:
========================================
get_pantilt_maxspeed (returns max_pan_speed and max_tilt_speed)
get_pantilt_position (returns pan_position: -860..862
                      and tilt_position: -281..283)

==================================================
Commands not yet in libVISCA:
==================================================

Commands without parameter:
===========================
set_at_mode_onoff           (Target tracking mode On/Off)
set_at_ae_onoff             (Auto exposure for target tracking mode On/Off)
set_at_autozoom_onoff       (Auto zoom for target tracking mode On/Off)
set_atmd_framedisplay_onoff (Frame display for target tracking or 
                             motion detection mode On/Off)
set_at_frameoffset_onoff    (Frame offset control for 
                             target tracking mode On/Off)
set_atmd_startstop          (Start or stop target tracking or 
                             motion detection)
set_at_chase_next           (Select target tracking chase mode 1/2/3)
set_md_mode_onoff           (Motion detection mode On/Off)
set_md_frame                (Set detection area/size for motion detection)
set_md_detect               (Select detecting frame for motion detection, 
                             1, 2 or 1+2)
set_at_lostinfo             (returns when target is lost 
                             in target tracking mode)
set_md_lostinfo             (returns when motion is detected within frame 
                             in motion detection mode)
set_md_measure_mode1_onoff  (Set motion detection measure mode 1 On/Off)
set_md_measure_mode2_onoff  (Set motion detection measure mode 2 On/Off)

Commands with one boolean parameter (0|1):
==========================================
set_at_mode           (Target tracking mode On/Off)
set_at_ae             (Auto exposure for target tracking mode On/Off)
set_at_autozoom       (Auto zoom for target tracking mode On/Off)
set_atmd_framedisplay (Frame display for target tracking or 
                       motion detection mode On/Off)
set_at_frameoffset    (Frame offset control for target tracking mode On/Off)
set_md_mode           (Motion detection mode On/Off)
set_md_measure_mode1  (Set motion detection measure mode 1 On/Off)
set_md_measure_mode2  (Set motion detection measure mode 2 On/Off)

Commands with one integer parameter:
====================================
set_wide_con_lens <conversion> (AT compensation when a wide conversion lens 
                                is installed, 
				0: No conversion to 7: X0.6 conversion)
set_at_chase <chase_mode>      (Select target tracking chase mode 0, 1 or 2)
set_at_entry <entry>           (Select target study mode for target tracking
                                available modes: 0 to 3)
set_md_adjust_ylevel <level>   (adjust level of detection from 0 to 15)
set_md_adjust_huelevel <level> (adjust level of detection from 0 to 15)
set_md_adjust_size <level>     (adjust level of detection from 0 to 15)
set_md_adjust_disptime <level> (adjust level of detection from 0 to 15)
set_md_adjust_refmode <mode>   (set refreshmode from 0 to 2)
set_md_adjust_reftime <time>   (set refreshtime from 0 to 15)

Commands that return one boolean value:
=======================================
get_keylock (returns 1 if keylock is set, 0 otherwise)

Commands that return one integer value:
=======================================
get_wide_con_lens     (returns which wide conversion lens is installed, 
                       0: No conversion to 7: X0.6 conversion)
get_atmd_mode         (returns the current AT or MD mode: 
                       0: Normal mode, 1: AT mode, 2: MD mode)
get_at_mode           (returns the AT status, 
                       see D30/31 Command List for details
get_at_entry          (returns the AT entry: 0 to 3)
get_md_mode           (returns the MD status, 
                       see D30/31 Command List for details)
get_md_ylevel         (returns level of detection from 0 to 15)
get_md_huelevel       (returns level of detection from 0 to 15)
get_md_size           (returns level of detection from 0 to 15)
get_md_disptime       (returns level of detection from 0 to 15)
get_md_refmode        (returns refreshmode from 0 to 2)
get_md_reftime        (returns refreshtime from 0 to 15)

Commands that return three integer values:
==========================================
get_at_obj_pos (returns the center position of the detection frame divided
                by 48x30 pixels and a status: 0=Setting, 1=Tracking, 2=Lost)
get_md_obj_pos (returns the center position of the detection frame divided
                by 48x30 pixels and a status: 1=UnDetect, 2=Detected)
*/

#include <stdlib.h>
#include <stdio.h>
#include "visca/libvisca.h"
#ifdef WIN
#include <Windows.h>
#include <crtdbg.h>
#else
#include <unistd.h> /* UNIX standard function definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <sys/ioctl.h>
#include <stdint.h>
#endif

#include <fcntl.h> /* File control definitions */
#include <errno.h> /* Error number definitions */
#include <string.h>

#define DEBUG 0

#define D30ONLY 0

/*The device the camera is attached to*/
/*The default device the camera is attached to*/
#ifdef WIN
char *ttydev = "COM1:";
#else
 char *ttydev = "/dev/ttyS0";
#endif

/*Structures needed for the VISCA library*/
VISCAInterface_t iface;
VISCACamera_t camera;

/*print usage message and exit*/
void print_usage() {
  fprintf(stderr,"Usage: visca-cli [-d <serial port device>] command\n");
  fprintf(stderr,"  default serial port device: %s\n",ttydev);      
  fprintf(stderr,"  for available commands see sourcecode...\n");
  exit(1);  
}

/* This routine find the device the camera is attached to (if specified)
 * It concatenates the rest of the commandline and returnes that string
 */
char *process_commandline(int argc, char **argv) {
  /*loop counter*/
  int i;

  /*temporarily used to hold the length of a string*/
  int length = 0;
  
  /*used to hold the commandline that is returned*/
  char *commandline;
  
  /*at least a command has to be specified*/
  if (argc < 2) {
    print_usage();
  }

  /*Find the ttydev if specified*/
  if (strncmp(argv[1], "-d", 2) == 0) {
    /*after the -d and the device name at least one command has to follow*/
    if (argc < 4) {
      print_usage();
    } else {
      ttydev = argv[2];
      /*we have used up two arguments*/
      argv += 2;
      argc -= 2;
    }
  }
  
  /*concatenate command string*/

  /*find total length of commandline*/
  length = 0;
  for (i=1; i < argc; i++) {
    length += strlen(argv[i])+1;
  }
  
  /*allocate memory for commandline*/
  commandline = (char *)malloc(sizeof(char) * length);
  
  /*copy the first argument to the commandline*/
  strcpy(commandline, argv[1]);

  /*add the rest of the arguments, seperated by blanks*/
  for (i=2; i < argc; i++) {
    strcat(commandline, " ");
    strcat(commandline, argv[i]);
  }
  
  return commandline;  
}

void open_interface() {
  int camera_num;
  if (VISCA_open_serial(&iface, ttydev)!=VISCA_SUCCESS) {
    fprintf(stderr,"visca-cli: unable to open serial device %s\n",ttydev);
    exit(1);
  }

  iface.broadcast=0;
  VISCA_set_address(&iface, &camera_num);
  if(VISCA_set_address(&iface, &camera_num)!=VISCA_SUCCESS) {
#ifdef WIN
    _RPTF0(_CRT_WARN,"unable to set address\n");
#endif
    fprintf(stderr,"visca-cli: unable to set address\n");
    VISCA_close_serial(&iface);
    exit(1);
  }

  camera.address=1;


  if(VISCA_clear(&iface, &camera)!=VISCA_SUCCESS) {
#ifdef WIN
    _RPTF0(_CRT_WARN,"unable to clear interface\n");
#endif
    fprintf(stderr,"visca-cli: unable to clear interface\n");
    VISCA_close_serial(&iface);
    exit(1);
  }
  if(VISCA_get_camera_info(&iface, &camera)!=VISCA_SUCCESS) {
#ifdef WIN
    _RPTF0(_CRT_WARN,"unable to oget camera infos\n");
#endif
    fprintf(stderr,"visca-cli: unable to oget camera infos\n");
    VISCA_close_serial(&iface);
    exit(1);
  }

#if DEBUG 
  fprintf(stderr,"Camera initialisation successful.\n");
#endif
}

void close_interface()
{
#ifdef WIN
  Sleep(2000);
#else
  // read the rest of the data: (should be empty)
  unsigned char packet[3000];
  int i, bytes;

  ioctl(iface.port_fd, FIONREAD, &bytes);
  if (bytes>0) {
    fprintf(stderr, "ERROR: %d bytes not processed: ", bytes);
    read(iface.port_fd, &packet, bytes);
    for (i=0;i<bytes;i++) {
      fprintf(stderr,"%2x ",packet[i]);
    }
    fprintf(stderr,"\n");
  }
#endif
  VISCA_close_serial(&iface);
}

/* This subroutine tries to execute the commandline given in char *commandline
 * 
 * One of the following codes is returned:
 *
 * Success:
 * 10: command successfully executed
 * 11: command successfully executed, return value in ret1
 * 12: command successfully executed, return values in ret1 and ret2
 * 13: command successfully executed, return values in ret1, ret2 and ret3
 *
 * Error:
 * 40: command unknow
 * 41: missing or unknown arg1
 * 42: missing or unknown arg2
 * 43: missing or unknown arg3
 * 44: missing or unknown arg4
 * 45: missing or unknown arg5
 * 46: camera returned an error  
 */
int doCommand(char *commandline, int *ret1, int *ret2, int *ret3) {
  /*Variables for the user specified command and arguments*/
  char *command;
  char *arg1;
  char *arg2;
  char *arg3;
  char *arg4;
  char *arg5;
  int intarg1=0;
  int intarg2=0;
  int intarg3=0;
  int intarg4=0;
  int intarg5=0;
  int boolarg;
  VISCATitleData_t *temptitle;
  
  /*Variables that hold return values from VISCA routines*/
  uint8_t value8, value8b, value8c;
  uint16_t value16;
  
  /*tokenize the commandline*/
  command = strtok(commandline, " ");
  arg1 = strtok(NULL, " ");
  arg2 = strtok(NULL, " ");
  arg3 = strtok(NULL, " ");
  arg4 = strtok(NULL, " ");
  arg5 = strtok(NULL, " ");
  
  /*Try to convert the arguments to integers*/
  if (arg1 != NULL) {
    intarg1 = atoi(arg1);
  }
  if (arg2 != NULL) {
    intarg2 = atoi(arg2);
  }
  if (arg3 != NULL) {
    intarg3 = atoi(arg3);
  }
  if (arg4 != NULL) {
    intarg4 = atoi(arg4);
  }
  if (arg5 != NULL) {
    intarg5 = atoi(arg5);
  }
  
  /*Try to find a boolean value*/
  if ((arg1 != NULL) && (strcmp(arg1, "true") == 0)) {
    boolarg = 2;
  } else if ((arg1 != NULL) && (strcmp(arg1, "false") == 0)) {
    boolarg = 3;
  } else if ((arg1 != NULL) && (strcmp(arg1, "1") == 0)) {
    boolarg = 2;
  } else if ((arg1 != NULL) && (strcmp(arg1, "0") == 0)) {
    boolarg = 3;
  } else {
    boolarg = -1;
  }
  
#if DEBUG
  fprintf(stderr, "command: %s\n", command);
  fprintf(stderr, "arg1: %s\narg2: %s\narg3: %s\narg4: %s\narg5: %s\n", 
          arg1, arg2, arg3, arg4, arg5);
  fprintf(stderr, 
          "intarg1: %i\nintarg2: %i\nintarg3: %i\nintarg4:%i\nintarg5:%i\n", 
          intarg1, intarg2, intarg3, intarg4, intarg5);
  fprintf(stderr, "boolarg: %i\n", boolarg);
#endif

  if (strcmp(command, "set_zoom_tele") == 0) {
    if (VISCA_set_zoom_tele(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_zoom_wide") == 0) {
    if (VISCA_set_zoom_wide(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_zoom_stop") == 0) {
    if (VISCA_set_zoom_stop(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_focus_far") == 0) {
    if (VISCA_set_focus_far(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_focus_near") == 0) {
    if (VISCA_set_focus_near(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_focus_stop") == 0) {
    if (VISCA_set_focus_stop(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

#if !D30ONLY
  if (strcmp(command, "set_focus_one_push") == 0) {
    if (VISCA_set_focus_one_push(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_focus_infinity") == 0) {
    if (VISCA_set_focus_infinity(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_focus_autosense_high") == 0) {
    if (VISCA_set_focus_autosense_high(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_focus_autosense_low") == 0) {
    if (VISCA_set_focus_autosense_low(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

  if (strcmp(command, "set_whitebal_one_push") == 0) {
    if (VISCA_set_whitebal_one_push(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

#if !D30ONLY
  if (strcmp(command, "set_rgain_up") == 0) {
    if (VISCA_set_rgain_up(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_rgain_down") == 0) {
    if (VISCA_set_rgain_down(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_rgain_reset") == 0) {
    if (VISCA_set_rgain_reset(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_bgain_up") == 0) {
    if (VISCA_set_bgain_up(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_bgain_down") == 0) {
    if (VISCA_set_bgain_down(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_bgain_reset") == 0) {
    if (VISCA_set_bgain_reset(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

  if (strcmp(command, "set_shutter_up") == 0) {
    if (VISCA_set_shutter_up(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_shutter_down") == 0) {
    if (VISCA_set_shutter_down(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_shutter_reset") == 0) {
    if (VISCA_set_shutter_reset(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_iris_up") == 0) {
    if (VISCA_set_iris_up(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_iris_down") == 0) {
    if (VISCA_set_iris_down(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_iris_reset") == 0) {
    if (VISCA_set_iris_reset(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_gain_up") == 0) {
    if (VISCA_set_gain_up(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_gain_down") == 0) {
    if (VISCA_set_gain_down(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_gain_reset") == 0) {
    if (VISCA_set_gain_reset(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_bright_up") == 0) {
    if (VISCA_set_bright_up(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_bright_down") == 0) {
    if (VISCA_set_bright_down(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_bright_reset") == 0) {
    if (VISCA_set_bright_reset(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

#if !D30ONLY
  if (strcmp(command, "set_aperture_up") == 0) {
    if (VISCA_set_aperture_up(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_aperture_down") == 0) {
    if (VISCA_set_aperture_down(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_aperture_reset") == 0) {
    if (VISCA_set_aperture_reset(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_exp_comp_up") == 0) {
    if (VISCA_set_exp_comp_up(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_exp_comp_down") == 0) {
    if (VISCA_set_exp_comp_down(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_exp_comp_reset") == 0) {
    if (VISCA_set_exp_comp_reset(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_title_clear") == 0) {
    if (VISCA_set_title_clear(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

  if (strcmp(command, "set_irreceive_on") == 0) {
    if (VISCA_set_irreceive_on(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_irreceive_off") == 0) {
    if (VISCA_set_irreceive_off(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_irreceive_onoff") == 0) {
    if (VISCA_set_irreceive_onoff(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_pantilt_home") == 0) {
    if (VISCA_set_pantilt_home(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_pantilt_reset") == 0) {
    if (VISCA_set_pantilt_reset(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_pantilt_limit_downleft_clear") == 0) {
    if (VISCA_set_pantilt_limit_downleft_clear(&iface, &camera)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_pantilt_limit_upright_clear") == 0) {
    if (VISCA_set_pantilt_limit_upright_clear(&iface, &camera)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_datascreen_on") == 0) {
    if (VISCA_set_datascreen_on(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_datascreen_off") == 0) {
    if (VISCA_set_datascreen_off(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }  

  if (strcmp(command, "set_datascreen_onoff") == 0) {
    if (VISCA_set_datascreen_onoff(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
  
  if (strcmp(command, "set_power") == 0) {
    if ((arg1 == NULL) || (boolarg == -1)) {
      return 41;
    }
    if (VISCA_set_power(&iface, &camera, boolarg)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
  
  if (strcmp(command, "set_keylock") == 0) {
    if ((arg1 == NULL) || (boolarg == -1)) {
      return 41;
    }
    if (boolarg == 03) {
      boolarg = 0;
    }
    if (VISCA_set_keylock (&iface, &camera, boolarg)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

#if !D30ONLY
  if (strcmp(command, "set_dzoom") == 0) {
    if ((arg1 == NULL) || (boolarg == -1)) {
      return 41;
    }
    if (VISCA_set_dzoom (&iface, &camera, boolarg)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

  if (strcmp(command, "set_focus_auto") == 0) {
    if ((arg1 == NULL) || (boolarg == -1)) {
      return 41;
    }
    if (VISCA_set_focus_auto (&iface, &camera, boolarg)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

#if !D30ONLY
  if (strcmp(command, "set_exp_comp_power") == 0) {
    if ((arg1 == NULL) || (boolarg == -1)) {
      return 41;
    }
    if (VISCA_set_exp_comp_power (&iface, &camera, boolarg)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_slow_shutter_auto") == 0) {
    if ((arg1 == NULL) || (boolarg == -1)) {
      return 41;
    }
    if (VISCA_set_slow_shutter_auto (&iface, &camera, boolarg)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

  if (strcmp(command, "set_backlight_comp") == 0) {
    if ((arg1 == NULL) || (boolarg == -1)) {
      return 41;
    }
    if (VISCA_set_backlight_comp (&iface, &camera, boolarg)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

#if !D30ONLY
  if (strcmp(command, "set_zero_lux_shot") == 0) {
    if ((arg1 == NULL) || (boolarg == -1)) {
      return 41;
    }
    if (VISCA_set_zero_lux_shot (&iface, &camera, boolarg) 
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_ir_led") == 0) {
    if ((arg1 == NULL) || (boolarg == -1)) {
      return 41;
    }
    if (VISCA_set_ir_led (&iface, &camera, boolarg)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_mirror") == 0) {
    if ((arg1 == NULL) || (boolarg == -1)) {
      return 41;
    }
    if (VISCA_set_mirror (&iface, &camera, boolarg)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_freeze") == 0) {
    if ((arg1 == NULL) || (boolarg == -1)) {
      return 41;
    }
    if (VISCA_set_freeze (&iface, &camera, boolarg)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_display") == 0) {
    if ((arg1 == NULL) || (boolarg == -1)) {
      return 41;
    }
    if (VISCA_set_display (&iface, &camera, boolarg)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_date_display") == 0) {
    if ((arg1 == NULL) || (boolarg == -1)) {
      return 41;
    }
    if (VISCA_set_date_display (&iface, &camera, boolarg)!=VISCA_SUCCESS){
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_time_display") == 0) {
    if ((arg1 == NULL) || (boolarg == -1)) {
      return 41;
    }
    if (VISCA_set_time_display (&iface, &camera, boolarg)!=VISCA_SUCCESS){
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_title_display") == 0) {
    if ((arg1 == NULL) || (boolarg == -1)) {
      return 41;
    }
    if (VISCA_set_title_display (&iface, &camera, boolarg)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

  if (strcmp(command, "set_zoom_tele_speed") == 0) {
    if ((arg1 == NULL) || (intarg1 < 2) || (intarg1 > 7)) {
      return 41;
    }
    if (VISCA_set_zoom_tele_speed (&iface, &camera, intarg1)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_zoom_wide_speed") == 0) {
    if ((arg1 == NULL) || (intarg1 < 2) || (intarg1 > 7)) {
      return 41;
    }
    if (VISCA_set_zoom_wide_speed(&iface, &camera, intarg1)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_zoom_value") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 1023)) {
      return 41;
    }
    if (VISCA_set_zoom_value(&iface, &camera, intarg1)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

#if !D30ONLY
  if (strcmp(command, "set_focus_far_speed") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 1023)) {
      return 41;
    }
    if (VISCA_set_focus_far_speed(&iface, &camera, intarg1)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_focus_near_speed") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 1023)) {
      return 41;
    }
    if (VISCA_set_focus_near_speed(&iface, &camera, intarg1)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

  if (strcmp(command, "set_focus_value") == 0) {
    if ((arg1 == NULL) || (intarg1 < 1000) || (intarg1 > 40959)) {
      return 41;
    }
    if (VISCA_set_focus_value(&iface, &camera, intarg1)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

#if !D30ONLY
  if (strcmp(command, "set_focus_near_limit") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 1)) {
      return 41;
    }
    if (VISCA_set_focus_near_limit(&iface, &camera, intarg1) 
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

  if (strcmp(command, "set_whitebal_mode") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 3)) {
      return 41;
    }
    if (VISCA_set_whitebal_mode(&iface, &camera, intarg1)!=VISCA_SUCCESS){
      return 46;
    }
    return 10;
  }

#if !D30ONLY
  if (strcmp(command, "set_rgain_value") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 1)) {
      return 41;
    }
    if (VISCA_set_rgain_value(&iface, &camera, intarg1)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_bgain_value") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 1)) {
      return 41;
    }
    if (VISCA_set_bgain_value(&iface, &camera, intarg1)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

  if (strcmp(command, "set_shutter_value") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 27)) {
      return 41;
    }
    if (VISCA_set_shutter_value(&iface, &camera, intarg1)!=VISCA_SUCCESS){
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_iris_value") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 17)) {
      return 41;
    }
    if (VISCA_set_iris_value(&iface, &camera, intarg1)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_gain_value") == 0) {
    if ((arg1 == NULL) || (intarg1 < 1) || (intarg1 > 7)) {
      return 41;
    }
    if (VISCA_set_gain_value(&iface, &camera, intarg1)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

#if !D30ONLY
  if (strcmp(command, "set_bright_value") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 1)) {
      return 41;
    }
    if (VISCA_set_bright_value(&iface, &camera, intarg1)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_aperture_value") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 1)) {
      return 41;
    }
    if (VISCA_set_aperture_value(&iface, &camera, intarg1)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_exp_comp_value") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 1)) {
      return 41;
    }
    if (VISCA_set_exp_comp_value(&iface, &camera, intarg1)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

  if (strcmp(command, "set_auto_exp_mode") == 0) {
    if (arg1 == NULL) {
      return 41;
    }
    
    if (!((intarg1 == 0) || (intarg1 == 3) || 
          (intarg1 == 10) || (intarg1 == 11) || (intarg1 == 13))) {
      return 41;
    }

    if (VISCA_set_auto_exp_mode(&iface, &camera, intarg1)!=VISCA_SUCCESS){
      return 46;
    }
    return 10;
  }

#if !D30ONLY
  if (strcmp(command, "set_wide_mode") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 1)) {
      return 41;
    }
    if (VISCA_set_wide_mode(&iface, &camera, intarg1)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_picture_effect") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 1)) {
      return 41;
    }
    if (VISCA_set_picture_effect(&iface, &camera, intarg1)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_digital_effect") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 1)) {
      return 41;
    }
    if (VISCA_set_digital_effect(&iface, &camera, intarg1)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_digital_effect_level") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 1)) {
      return 41;
    }
    if (VISCA_set_digital_effect_level(&iface, &camera, intarg1)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

  if (strcmp(command, "memory_set") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 5)) {
      return 41;
    }
    if (VISCA_memory_set(&iface, &camera, intarg1)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "memory_recall") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 5)) {
      return 41;
    }
    if (VISCA_memory_recall(&iface, &camera, intarg1)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "memory_reset") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 5)) {
      return 41;
    }
    if (VISCA_memory_reset(&iface, &camera, intarg1)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

#if !D30ONLY
  if (strcmp(command, "set_zoom_and_focus_value") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 1023)) {
      return 41;
    }
    if ((arg2 == NULL) || (intarg2 < 1000) || (intarg2 > 40959)) {
      return 42;
    }
    if (VISCA_set_zoom_and_focus_value(&iface, &camera, intarg1, intarg2)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

  if (strcmp(command, "set_pantilt_up") == 0) {
    if ((arg1 == NULL) || (intarg1 < 1) || (intarg1 > 24)) {
      return 41;
    }
    if ((arg2 == NULL) || (intarg2 < 1) || (intarg2 > 20)) {
      return 42;
    }
    if (VISCA_set_pantilt_up(&iface, &camera, intarg1, intarg2)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_pantilt_down") == 0) {
    if ((arg1 == NULL) || (intarg1 < 1) || (intarg1 > 24)) {
      return 41;
    }
    if ((arg2 == NULL) || (intarg2 < 1) || (intarg2 > 20)) {
      return 42;
    }
    if (VISCA_set_pantilt_down(&iface, &camera, intarg1, intarg2)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_pantilt_left") == 0) {
    if ((arg1 == NULL) || (intarg1 < 1) || (intarg1 > 24)) {
      return 41;
    }
    if ((arg2 == NULL) || (intarg2 < 1) || (intarg2 > 20)) {
      return 42;
    }
    if (VISCA_set_pantilt_left(&iface, &camera, intarg1, intarg2)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_pantilt_right") == 0) {
    if ((arg1 == NULL) || (intarg1 < 1) || (intarg1 > 24)) {
      return 41;
    }
    if ((arg2 == NULL) || (intarg2 < 1) || (intarg2 > 20)) {
      return 42;
    }
    if (VISCA_set_pantilt_right(&iface, &camera, intarg1, intarg2)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_pantilt_upleft") == 0) {
    if ((arg1 == NULL) || (intarg1 < 1) || (intarg1 > 24)) {
      return 41;
    }
    if ((arg2 == NULL) || (intarg2 < 1) || (intarg2 > 20)) {
      return 42;
    }
    if (VISCA_set_pantilt_upleft(&iface, &camera, intarg1, intarg2)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_pantilt_upright") == 0) {
    if ((arg1 == NULL) || (intarg1 < 1) || (intarg1 > 24)) {
      return 41;
    }
    if ((arg2 == NULL) || (intarg2 < 1) || (intarg2 > 20)) {
      return 42;
    }
    if (VISCA_set_pantilt_upright(&iface, &camera, intarg1, intarg2)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_pantilt_downleft") == 0) {
    if ((arg1 == NULL) || (intarg1 < 1) || (intarg1 > 24)) {
      return 41;
    }
    if ((arg2 == NULL) || (intarg2 < 1) || (intarg2 > 20)) {
      return 42;
    }
    if (VISCA_set_pantilt_downleft(&iface, &camera, intarg1, intarg2)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_pantilt_downright") == 0) {
    if ((arg1 == NULL) || (intarg1 < 1) || (intarg1 > 24)) {
      return 41;
    }
    if ((arg2 == NULL) || (intarg2 < 1) || (intarg2 > 20)) {
      return 42;
    }
    if (VISCA_set_pantilt_downright(&iface, &camera, intarg1, intarg2)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_pantilt_stop") == 0) {
    if ((arg1 == NULL) || (intarg1 < 1) || (intarg1 > 24)) {
      return 41;
    }
    if ((arg2 == NULL) || (intarg2 < 1) || (intarg2 > 20)) {
      return 42;
    }
    if (VISCA_set_pantilt_stop(&iface, &camera, intarg1, intarg2)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_pantilt_limit_upright") == 0) {
    if ((arg1 == NULL) || (intarg1 < -879) || (intarg1 > 880)) {
      return 41;
    }
    if ((arg2 == NULL) || (intarg2 < -299) || (intarg2 > 300)) {
      return 42;
    }
    if (VISCA_set_pantilt_limit_upright(&iface, &camera, 
        intarg1, intarg2) != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_pantilt_limit_downleft") == 0) {
    if ((arg1 == NULL) || (intarg1 < -879) || (intarg1 > 880)) {
      return 41;
    }
    if ((arg2 == NULL) || (intarg2 < -299) || (intarg2 > 300)) {
      return 42;
    }
    if (VISCA_set_pantilt_limit_downleft(&iface, &camera, 
        intarg1, intarg2) != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_pantilt_absolute_position") == 0) {
    if ((arg1 == NULL) || (intarg1 < 1) || (intarg1 > 24)) {
      return 41;
    }
    if ((arg2 == NULL) || (intarg2 < 1) || (intarg2 > 20)) {
      return 42;
    }
    if ((arg3 == NULL) || (intarg3 < -879) || (intarg3 > 880)) {
      return 43;
    }
    if ((arg4 == NULL) || (intarg4 < -299) || (intarg4 > 300)) {
      return 44;
    }
    if (VISCA_set_pantilt_absolute_position(&iface, &camera, 
        intarg1, intarg2, intarg3, intarg4) != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_pantilt_relative_position") == 0) {
    if ((arg1 == NULL) || (intarg1 < 1) || (intarg1 > 24)) {
      return 41;
    }
    if ((arg2 == NULL) || (intarg2 < 1) || (intarg2 > 20)) {
      return 42;
    }
    if ((arg3 == NULL) || (intarg3 < -879) || (intarg3 > 880)) {
      return 43;
    }
    if ((arg4 == NULL) || (intarg4 < -299) || (intarg4 > 300)) {
      return 44;
    }
    if (VISCA_set_pantilt_relative_position(&iface, &camera, 
        intarg1, intarg2, intarg3, intarg4) != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

#if !D30ONLY
  if (strcmp(command, "set_title_params") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 600)) {
      return 41;
    }
    if ((arg2 == NULL) || (intarg2 < 0) || (intarg2 > 800)) {
      return 42;
    }
    if ((arg3 == NULL) || (intarg3 < 0) || (intarg3 > 32)) {
      return 43;
    }
    if ((arg4 == NULL) || (intarg4 < 0) || (intarg4 > 1)) {
      return 44;
    }
    temptitle = (VISCATitleData_t *)malloc((sizeof(unsigned int)*4)+
                                            sizeof(unsigned char*));
    temptitle->vposition=intarg1;
    temptitle->hposition=intarg2;
    temptitle->color=intarg3;
    temptitle->blink=intarg4;
    if (VISCA_set_title_params(&iface, &camera, temptitle) 
        != VISCA_SUCCESS) {
      free(temptitle);
      return 46;
    }
    free(temptitle);
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_date_time") == 0) {
    if ((arg1 == NULL) || (intarg1 < 1) || (intarg1 > 99)) {
      return 41;
    }
    if ((arg2 == NULL) || (intarg2 < 1) || (intarg2 > 12)) {
      return 42;
    }
    if ((arg3 == NULL) || (intarg3 < 1) || (intarg3 > 31)) {
      return 43;
    }
    if ((arg4 == NULL) || (intarg4 < 1) || (intarg4 > 23)) {
      return 44;
    }
    if ((arg5 == NULL) || (intarg5 < 1) || (intarg5 > 59)) {
      return 45;
    }
    if (VISCA_set_date_time(&iface, &camera, 
        intarg1, intarg2, intarg3, intarg4, intarg5) != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "set_title") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 600)) {
      return 41;
    }
    if ((arg2 == NULL) || (intarg2 < 0) || (intarg2 > 800)) {
      return 42;
    }
    if ((arg3 == NULL) || (intarg3 < 0) || (intarg3 > 32)) {
      return 43;
    }
    if ((arg4 == NULL) || (intarg4 < 0) || (intarg4 > 1)) {
      return 44;
    }
    if (arg5 == NULL) {
      return 45;
    }
    temptitle = (VISCATitleData_t *)malloc(sizeof(VISCATitleData_t));
    temptitle->vposition=intarg1;
    temptitle->hposition=intarg2;
    temptitle->color=intarg3;
    temptitle->blink=intarg4;
    strncpy((char*)temptitle->title, arg5, 19);
    if (VISCA_set_title_params(&iface, &camera, temptitle) 
        != VISCA_SUCCESS) {
      free(temptitle);
      return 46;
    }
    free(temptitle);
    return 10;
  }
#endif

  if (strcmp(command, "get_power") == 0) {
    if (VISCA_get_power(&iface, &camera, &value8)!=VISCA_SUCCESS) {
      return 46;
    }
    if (value8 == 2) {
      *ret1 = 0;
    } else if (value8 == 3) {
      *ret1 = 1;
    } else {
      return 47;
    }
    return 11;
  }

  if (strcmp(command, "get_power") == 0) {
    if (VISCA_get_power(&iface, &camera, &value8)!=VISCA_SUCCESS) {
      return 46;
    }
    if (value8 == 2) {
      *ret1 = 1;
    } else if (value8 == 3) {
      *ret1 = 0;
    } else {
      return 47;
    }
    return 11;
  }

#if !D30ONLY
  if (strcmp(command, "get_dzoom") == 0) {
    if (VISCA_get_dzoom(&iface, &camera, &value8)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value8;
    return 11;
  }
#endif

  if (strcmp(command, "get_focus_auto") == 0) {
    if (VISCA_get_focus_auto(&iface, &camera, &value8)!=VISCA_SUCCESS) {
      return 46;
    }
    if (value8 == 2) {
      *ret1 = 1;
    } else if (value8 == 3) {
      *ret1 = 0;
    } else {
      return 47;
    }
    return 11;
  }

#if !D30ONLY
  if (strcmp(command, "get_exp_comp_power") == 0) {
    if (VISCA_get_exp_comp_power(&iface, &camera, &value8)
        != VISCA_SUCCESS){
      return 46;
    }
    *ret1 = value8;
    return 11;
  }
#endif

  if (strcmp(command, "get_backlight_comp") == 0) {
    if (VISCA_get_backlight_comp(&iface, &camera, &value8)
        != VISCA_SUCCESS) {
      return 46;
    }
    if (value8 == 2) {
      *ret1 = 1;
    } else if (value8 == 3) {
      *ret1 = 0;
    } else {
      return 47;
    }
    return 11;
  }

#if !D30ONLY
  if (strcmp(command, "get_zero_lux_shot") == 0) {
    if (VISCA_get_zero_lux_shot(&iface, &camera, &value8)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value8;
    return 11;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "get_ir_led") == 0) {
    if (VISCA_get_ir_led(&iface, &camera, &value8)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value8;
    return 11;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "get_mirror") == 0) {
    if (VISCA_get_mirror(&iface, &camera, &value8)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value8;
    return 11;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "get_freeze") == 0) {
    if (VISCA_get_freeze(&iface, &camera, &value8)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value8;
    return 11;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "get_display") == 0) {
    if (VISCA_get_display(&iface, &camera, &value8)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value8;
    return 11;
  }
#endif

  if (strcmp(command, "get_datascreen") == 0) {
    if (VISCA_get_datascreen(&iface, &camera, &value8)!=VISCA_SUCCESS) {
      return 46;
    }
    if (value8 == 2) {
      *ret1 = 1;
    } else if (value8 == 3) {
      *ret1 = 0;
    } else {
      return 47;
    }
    return 11;
  }

  if (strcmp(command, "get_zoom_value") == 0) {
    if (VISCA_get_zoom_value(&iface, &camera, &value16)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value16;
    return 11;
  }

  if (strcmp(command, "get_focus_value") == 0) {
    if (VISCA_get_focus_value(&iface, &camera, &value16)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value16;
    return 11;
  }

#if !D30ONLY
  if (strcmp(command, "get_focus_auto_sense") == 0) {
    if (VISCA_get_focus_auto_sense(&iface, &camera, &value8)
        != VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value8;
    return 11;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "get_focus_near_limit") == 0) {
    if (VISCA_get_focus_near_limit(&iface, &camera, &value16)
        != VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value16;
    return 11;
  }
#endif

  if (strcmp(command, "get_whitebal_mode") == 0) {
    if (VISCA_get_whitebal_mode(&iface, &camera, &value8)!=VISCA_SUCCESS){
      return 46;
    }
    *ret1 = value8;
    return 11;
  }

#if !D30ONLY
  if (strcmp(command, "get_rgain_value") == 0) {
    if (VISCA_get_rgain_value(&iface, &camera, &value16)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value16;
    return 11;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "get_bgain_value") == 0) {
    if (VISCA_get_bgain_value(&iface, &camera, &value16)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value16;
    return 11;
  }
#endif

  if (strcmp(command, "get_auto_exp_mode") == 0) {
    if (VISCA_get_auto_exp_mode(&iface, &camera, &value8)!=VISCA_SUCCESS){
      return 46;
    }
    *ret1 = value8;
    return 11;
  }

#if !D30ONLY
  if (strcmp(command, "get_slow_shutter_auto") == 0) {
    if (VISCA_get_slow_shutter_auto(&iface, &camera, &value8)
        != VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value8;
    return 11;
  }
#endif

  if (strcmp(command, "get_shutter_value") == 0) {
    if (VISCA_get_shutter_value(&iface, &camera, &value16)
        != VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value16;
    return 11;
  }

  if (strcmp(command, "get_iris_value") == 0) {
    if (VISCA_get_iris_value(&iface, &camera, &value16)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value16;
    return 11;
  }

  if (strcmp(command, "get_gain_value") == 0) {
    if (VISCA_get_gain_value(&iface, &camera, &value16)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value16;
    return 11;
  }

#if !D30ONLY
  if (strcmp(command, "get_bright_value") == 0) {
    if (VISCA_get_bright_value(&iface, &camera, &value16)!=VISCA_SUCCESS){
      return 46;
    }
    *ret1 = value16;
    return 11;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "get_exp_comp_value") == 0) {
    if (VISCA_get_exp_comp_value(&iface, &camera, &value16)
        != VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value16;
    return 11;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "get_aperture_value") == 0) {
    if (VISCA_get_aperture_value(&iface, &camera, &value16)
        != VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value16;
    return 11;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "get_wide_mode") == 0) {
    if (VISCA_get_wide_mode(&iface, &camera, &value8)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value8;
    return 11;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "get_picture_effect") == 0) {
    if (VISCA_get_picture_effect(&iface, &camera, &value8)
        != VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value8;
    return 11;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "get_digital_effect") == 0) {
    if (VISCA_get_digital_effect(&iface, &camera, &value8)
        != VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value8;
    return 11;
  }
#endif

#if !D30ONLY
  if (strcmp(command, "get_digital_effect_level") == 0) {
    if (VISCA_get_digital_effect_level(&iface, &camera, &value16)
        != VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value16;
    return 11;
  }
#endif

  if (strcmp(command, "get_memory") == 0) {
    if (VISCA_get_memory(&iface, &camera, &value8)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value8;
    return 11;
  }

  if (strcmp(command, "get_id") == 0) {
    if (VISCA_get_id(&iface, &camera, &value16)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value16;
    return 11;
  }

  if (strcmp(command, "get_videosystem") == 0) {
    if (VISCA_get_videosystem(&iface, &camera, &value8)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value8;
    return 11;
  }

  if (strcmp(command, "get_pantilt_mode") == 0) {
    if (VISCA_get_pantilt_mode(&iface, &camera, &value16)!=VISCA_SUCCESS){
      return 46;
    }
    *ret1 = value16;
    return 11;
  }

  if (strcmp(command, "get_pantilt_maxspeed") == 0) {
    if (VISCA_get_pantilt_maxspeed(&iface, &camera, &value8, &value8b)
        != VISCA_SUCCESS){
      return 46;
    }
    *ret1 = value8;
    *ret2 = value8b;
    return 12;
  }

  if (strcmp(command, "get_pantilt_position") == 0) {
    if (VISCA_get_pantilt_position(&iface, &camera, ret1, ret2)
        != VISCA_SUCCESS){
      return 46;
    }
    return 12;
  }

  if (strcmp(command, "set_at_mode_onoff") == 0) {
    if (VISCA_set_at_mode_onoff(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_at_ae_onoff") == 0) {
    if (VISCA_set_at_ae_onoff(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_at_autozoom_onoff") == 0) {
    if (VISCA_set_at_autozoom_onoff(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_atmd_framedisplay_onoff") == 0) {
    if (VISCA_set_atmd_framedisplay_onoff(&iface, &camera)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_at_frameoffset_onoff") == 0) {
    if (VISCA_set_at_frameoffset_onoff(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_atmd_startstop") == 0) {
    if (VISCA_set_atmd_startstop(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_at_chase_next") == 0) {
    if (VISCA_set_at_chase_next(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_md_mode_onoff") == 0) {
    if (VISCA_set_md_mode_onoff(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_md_frame") == 0) {
    if (VISCA_set_md_frame(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_md_detect") == 0) {
    if (VISCA_set_md_detect(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_at_lostinfo") == 0) {
    if (VISCA_set_at_lostinfo(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_md_lostinfo") == 0) {
    if (VISCA_set_md_lostinfo(&iface, &camera)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_md_measure_mode1_onoff") == 0) {
    if (VISCA_set_md_measure_mode1_onoff(&iface, &camera)!=VISCA_SUCCESS){
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_md_measure_mode2_onoff") == 0) {
    if (VISCA_set_md_measure_mode2_onoff(&iface, &camera)!=VISCA_SUCCESS){
      return 46;
    }
    return 10;
  }
  
  if (strcmp(command, "set_focus_auto") == 0) {
    if ((arg1 == NULL) || (boolarg == -1)) {
      return 41;
    }
    if (VISCA_set_focus_auto (&iface, &camera, boolarg)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_at_mode") == 0) {
    if ((arg1 == NULL) || (boolarg == -1)) {
      return 41;
    }
    if (VISCA_set_at_mode(&iface, &camera, boolarg)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }


  if (strcmp(command, "set_at_ae") == 0) {
    if ((arg1 == NULL) || (boolarg == -1)) {
      return 41;
    }
    if (VISCA_set_at_ae(&iface, &camera, boolarg)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }


  if (strcmp(command, "set_at_autozoom") == 0) {
    if ((arg1 == NULL) || (boolarg == -1)) {
      return 41;
    }
    if (VISCA_set_at_autozoom(&iface, &camera, boolarg)!=VISCA_SUCCESS){
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_atmd_framedisplay") == 0) {
    if ((arg1 == NULL) || (boolarg == -1)) {
      return 41;
    }
    if (VISCA_set_atmd_framedisplay(&iface, &camera, boolarg)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_at_frameoffset") == 0) {
    if ((arg1 == NULL) || (boolarg == -1)) {
      return 41;
    }
    if (VISCA_set_at_frameoffset(&iface, &camera, boolarg)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_md_mode") == 0) {
    if ((arg1 == NULL) || (boolarg == -1)) {
      return 41;
    }
    if (VISCA_set_md_mode(&iface, &camera, boolarg)!=VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_md_measure_mode1") == 0) {
    if ((arg1 == NULL) || (boolarg == -1)) {
      return 41;
    }
    if (VISCA_set_md_measure_mode1(&iface, &camera, boolarg)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_md_measure_mode2") == 0) {
    if ((arg1 == NULL) || (boolarg == -1)) {
      return 41;
    }
    if (VISCA_set_md_measure_mode2(&iface, &camera, boolarg)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_wide_con_lens") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 7)) {
      return 41;
    }
    if (VISCA_set_wide_con_lens(&iface, &camera, intarg1)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_at_chase") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 2)) {
      return 41;
    }
    if (VISCA_set_at_chase(&iface, &camera, intarg1)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_at_entry") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 3)) {
      return 41;
    }
    if (VISCA_set_at_entry(&iface, &camera, intarg1)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_md_adjust_ylevel") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 15)) {
      return 41;
    }
    if (VISCA_set_md_adjust_ylevel(&iface, &camera, intarg1)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_md_adjust_huelevel") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 15)) {
      return 41;
    }
    if (VISCA_set_md_adjust_huelevel(&iface, &camera, intarg1)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_md_adjust_size") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 15)) {
      return 41;
    }
    if (VISCA_set_md_adjust_size(&iface, &camera, intarg1)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_md_adjust_disptime") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 15)) {
      return 41;
    }
    if (VISCA_set_md_adjust_disptime(&iface, &camera, intarg1)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_md_adjust_refmode") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 2)) {
      return 41;
    }
    if (VISCA_set_md_adjust_refmode(&iface, &camera, intarg1)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "set_md_adjust_reftime") == 0) {
    if ((arg1 == NULL) || (intarg1 < 0) || (intarg1 > 15)) {
      return 41;
    }
    if (VISCA_set_md_adjust_reftime(&iface, &camera, intarg1)
        != VISCA_SUCCESS) {
      return 46;
    }
    return 10;
  }

  if (strcmp(command, "get_keylock") == 0) {
    if (VISCA_get_keylock(&iface, &camera, &value8)!=VISCA_SUCCESS) {
      return 46;
    }
    if (value8 == 0) {
      *ret1 = 0;
    } else if (value8 == 2) {
      *ret1 = 1;
    } else {
      return 47;
    }
    return 11;
  }

  if (strcmp(command, "get_wide_con_lens") == 0) {
    if (VISCA_get_wide_con_lens(&iface, &camera, &value8)!=VISCA_SUCCESS){
      return 46;
    }
    *ret1 = value8;
    return 11;
  }

  if (strcmp(command, "get_atmd_mode") == 0) {
    if (VISCA_get_atmd_mode(&iface, &camera, &value8)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value8;
    return 11;
  }

  if (strcmp(command, "get_at_mode") == 0) {
    if (VISCA_get_at_mode(&iface, &camera, &value16)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value16;
    return 11;
  }

  if (strcmp(command, "get_at_entry") == 0) {
    if (VISCA_get_at_entry(&iface, &camera, &value8)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value8;
    return 11;
  }

  if (strcmp(command, "get_md_mode") == 0) {
    if (VISCA_get_md_mode(&iface, &camera, &value16)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value16;
    return 11;
  }

  if (strcmp(command, "get_md_ylevel") == 0) {
    if (VISCA_get_md_ylevel(&iface, &camera, &value8)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value8;
    return 11;
  }

  if (strcmp(command, "get_md_huelevel") == 0) {
    if (VISCA_get_md_huelevel(&iface, &camera, &value8)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value8;
    return 11;
  }

  if (strcmp(command, "get_md_size") == 0) {
    if (VISCA_get_md_size(&iface, &camera, &value8)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value8;
    return 11;
  }

  if (strcmp(command, "get_md_disptime") == 0) {
    if (VISCA_get_md_disptime(&iface, &camera, &value8)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value8;
    return 11;
  }

  if (strcmp(command, "get_md_refmode") == 0) {
    if (VISCA_get_md_refmode(&iface, &camera, &value8)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value8;
    return 11;
  }

  if (strcmp(command, "get_md_reftime") == 0) {
    if (VISCA_get_md_reftime(&iface, &camera, &value8)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value8;
    return 11;
  }

  if (strcmp(command, "get_at_obj_pos") == 0) {
    if (VISCA_get_at_obj_pos(&iface, &camera, &value8, &value8b, &value8c)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value8;
    *ret2 = value8b;
    *ret3 = value8c;
    return 13;
  }

  if (strcmp(command, "get_md_obj_pos") == 0) {
    if (VISCA_get_md_obj_pos(&iface, &camera, &value8, &value8b, &value8c)!=VISCA_SUCCESS) {
      return 46;
    }
    *ret1 = value8;
    *ret2 = value8b;
    *ret3 = value8c;
    return 13;
  }

  /* If we reach this point, the commandline matched 
   * none of the commands we know
   */
  return 40;
}

int main(int argc, char **argv) {
  char *commandline;
  int errorcode, ret1, ret2, ret3;

  commandline = process_commandline(argc, argv);
  
  open_interface();

  errorcode = doCommand(commandline, &ret1, &ret2, &ret3);
  switch(errorcode) {
    case 10:
      printf("10 OK - no return value\n");
      break;
    case 11:
      printf("11 OK - one return value\nRET1: %i\n", ret1);
      break;    
    case 12:
      printf("12 OK - two return values\nRET1: %i\nRET2: %i\n", ret1, ret2);
      break;
    case 13:
      printf("13 OK - three return values\nRET1: %i\nRET2: %i\nRET3: %i\n", 
             ret1, ret2, ret3);
      break;
    case 40:
      printf("40 ERROR - command not recognized\n");
      break;
    case 41:
      printf("41 ERROR - argument 1 not recognized\n");
      break;
    case 42:
      printf("42 ERROR - argument 2 not recognized\n");
      break;
    case 43:
      printf("43 ERROR - argument 3 not recognized\n");
      break;
    case 44:
      printf("44 ERROR - argument 4 not recognized\n");
      break;
    case 45:
      printf("45 ERROR - argument 5 not recognized\n");
      break;
    case 46:
      printf("46 ERROR - camera replied with an error\n");
      break;
    case 47:
      printf("47 ERROR - camera replied with an unknown return value\n");
      break;
    default:
      printf("unknown error code: %i\n", errorcode);
  }

  close_interface();
  exit(0);
}
