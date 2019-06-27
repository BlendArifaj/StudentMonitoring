/*****************************************************************************
 * Copyright (C) 2019 BSc. Blend Arifaj. All rights reserved
 * Str. Agim Ramadani, Prishtine, Republic of Kosovo. blendarifaj@hotmail.com
 *
 * @file  interactive_part.h
 *
 * @brief Declar the functions and Constans that will be used by interactive part
 * 
 * @author (IS) BSc. Blend Arifaj (blendarifaj@hotmail.com)
 * @date   $Date: Fri May 17, 16:11:02 2019 $
 *****************************************************************************/
#include<stdio.h>
#include<string.h>
#define APPEND "append"
#define LIST "list"
#define DELETE "delete"
#define QUIT "quit"
#define CHANGE_LIMIT "chlimit"
#define HELP "help"


void interactive_part(FILE *file,const int work_mode);
void take_action(FILE *file,const char command[128]);
int append_action(FILE *file);
int list_action(FILE *file);
void delete_action(FILE *file);
void quit_action();
int change_limit(FILE *file);
void interactive_help();
