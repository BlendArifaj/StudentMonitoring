/*****************************************************************************
 * Copyright (C) 2019 BSc. Blend Arifaj. All rights reserved
 * Str. Agim Ramadani, Prishtine, Republic of Kosovo. blendarifaj@hotmail.com
 *
 * @file  student.c
 *
 * @brief Implements functions that will help to complete the project
 * 
 * @author (IS) BSc. Blend Arifaj (blendarifaj@hotmail.com)
 * @date   $Date: Fri May 17, 15:39:59 2019 $
 *****************************************************************************/
#include "student.h"

/************************************************************************
 * @brief Check if the user requiring help function
 *
 * We compare all posible help form that user can require for help.
 * 
 * @param[in,out] - none
 * @param[in] - command
 *
 * @retval 1 if user required help
 * @retval 0 if user didn't required help
 *************************************************************************/
int help_check(const char *command){
	if( (strcmp(command,HELP_FORM_1)==0) ||
	    (strcmp(command,HELP_FORM_2)==0) ||
            (strcmp(command,HELP_FORM_3)==0) ||
            (strcmp(command,HELP_FORM_4)==0)){
		return 1;
	}
	return 0;
}



