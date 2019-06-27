/*****************************************************************************
 * Copyright (C) 2019 BSc. Blend Arifaj. All rights reserved
 * Str. Agim Ramadani, Prishtine, Republic of Kosovo. blendarifaj@hotmail.com
 *
 * @file  help.c
 *
 * @brief Implement the help function
 * 
 * @author (IS) BSc. Blend Arifaj (blendarifaj@hotmail.com)
 * @date   $Date: Fri May 17, 15:59:12 2019 $
 *****************************************************************************/
#include "help.h"
#include <stdio.h>

/************************************************************************
 * @brief Help for users
 *
 * We will print help form for the user. Also if the user is requiring help
 * for the interactive mode, than we will print something else.
 * 
 * @param[in,out] - none
 * @param[in] - work_mode
 *
 * @void program, so there will be no return value
 *************************************************************************/
void help_form(){
	printf("exc - The first exercise in the sys prog lecture\n\n");
	printf("SYNOPSIS\n");
	printf("\texc [OPTION] ... \n");
	printf("\t-f arg, (mandatory) the file name\n");
	printf("\t-a,     (optional) append a string to the file\n");
	printf("\t-i,	(optional) start the interactive mode\n");
	printf("\t-l,	(optional) list all students stored in the file\n");
	printf("\t-cl n   (optional) change limit number of students\n");
}


