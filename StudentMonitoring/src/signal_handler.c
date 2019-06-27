/*****************************************************************************
 * Copyright (C) 2019 BSc. Blend Arifaj. All rights reserved
 * Str. Agim Ramadani, Prishtine, Republic of Kosovo. blendarifaj@hotmail.com
 *
 * @file  signal_handler.c
 *
 * @brief Implements functions that will handle signals
 * 
 * @author (IS) BSc. Blend Arifaj (blendarifaj@hotmail.com)
 * @date   $Date: Fri May 17, 16:39:12 2019 $
 *****************************************************************************/
#include "signal_handler.h"
#include <stdlib.h>

/************************************************************************
 * @brief Terminate program using CTRL+C
 *
 * After the user press CTRL+C the program will print a text that has been terminated
 * 
 * @param[in,out] - none
 * @param[in] - singo
 *
 * @void program, so there will be no return value
 *************************************************************************/
void terminate_program(){
	struct sigaction signal_handler;
	void signal_handler_int(int);
	signal_handler.sa_handler = signal_handler_int;
	sigfillset(&(signal_handler.sa_mask));
	sigaction(SIGINT, &signal_handler, NULL);
}

/************************************************************************
 * @brief What to do when press CTRL+C
 *
 * This function tells the program what to do when the user press CTRL+C
 * 
 * @param[in,out] - none
 * @param[in] - signo
 *
 * @void program, so there will be no return value
 ************************************************************************/
void signal_handler_int(int signo){
	printf("Program has been successfully terminated\n");
	exit(0);
}
