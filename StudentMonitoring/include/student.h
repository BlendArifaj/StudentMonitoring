/*****************************************************************************
 * Copyright (C) 2019 BSc. Blend Arifaj. All rights reserved
 * Str. Agim Ramadani, Prishtine, Republic of Kosovo. blendarifaj@hotmail.com
 *
 * @file  student.h
 *
 * @brief Dclare funtions, structurs and functions that will be used by student
 * 
 * @author (IS) BSc. Blend Arifaj (blendarifaj@hotmail.com)
 * @date   $Date: Fri May 17, 15:39:59 2019 $
 *****************************************************************************/

/*Declaration of needed constants*/
#define _POSIX_SOURCE
#define FILE_ARG "-f"
#define APPEND_ARG "-a"
#define INTERACTIVE_MODE_ARG "-i"
#define LIST_ALL_STUDENT_ARG "-l"
#define DELETE_STUDENT_ARG "-d"
#define CHANGE_LIMIT_STUDENT_NUM_ARG "-cl"
#define HELP_FORM_1 "-h"
#define HELP_FORM_2 "--h"
#define HELP_FORM_3 "-help"
#define HELP_FORM_4 "--help"
#define OPEN_FILE_MODE "rb+"
#define CREATE_FILE_MODE "wb"
#define INTERACTIVE_MODE 1
#define NON_INTERACTIVE_MODE 0
#define INTERACTIVE_MODE 1
#define NON_INTERACTIVE_MODE 0
#define MAX_STD_NUM 40

/*Including needed files*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "signal_handler.h"
#include "interactive_part.h"
#include "help.h"

/*Student struct*/
struct student{
	char firstname[50];
	char lastname[50];
	char ID[50];
	int age;
	char address[50];
};

/*Student's Data struct*/
struct studentsData{
	int studentsNumber;
	int studentsLimitNumber;
};

int help_check(const char *command);
