/*****************************************************************************
 * Copyright (C) 2019 BSc. Blend Arifaj. All rights reserved
 * Str. Agim Ramadani, Prishtine, Republic of Kosovo. blendarifaj@hotmail.com
 *
 * @file  signal_handler.h
 *
 * @brief Declare the contant and functions that will be used by signal handler
 * 
 * @author (IS) BSc. Blend Arifaj (blendarifaj@hotmail.com)
 * @date   $Date: Fri May 17, 16:38:03 2019 $
 *****************************************************************************/
#define _POSIX_SOURCE
#include<signal.h>
#include <stdio.h>
void signal_handler_int(int signo);
void terminate_program();
