/*****************************************************************************
 * Copyright (C) 2019 BSc. Blend Arifaj. All rights reserved
 * Str. Agim Ramadani, Prishtine, Republic of Kosovo. blendarifaj@hotmail.com
 *
 * @file  interactive_part.c
 *
 * @brief Implements the interactive parts of project
 * 
 * @author (IS) BSc. Blend Arifaj (blendarifaj@hotmail.com)
 * @date   $Date: Fri May 17, 16:12:02 2019 $
 *****************************************************************************/
#include "interactive_part.h"
#include "functions.h"
#include <stdlib.h>

/************************************************************************
 * @brief When the user is on intereactive mode
 *
 * User will be able to type commands in the command line. Based on what
 * he will type, we are going to take actions. Also, will change the mode
 * of the work to INTERACTIVE MODE.
 * 
 * @param[in,out] - file
 * @param[in] - work_mode
 *
 * @void program, so there will be no return value
 *************************************************************************/
void interactive_part(FILE *file,const int work_mode){
	printf("YOU ARE ON INTERACTIVE MODE NOW\n");
	printf("Mode interactive has code %d\n",work_mode);
	char command[128];
	while(strcmp(command,QUIT)!=0){
		printf("Type your command: ");
		scanf("%s",(char *)&command);
		take_action(file,command);
	}
}


/************************************************************************
 * @brief Take action on what user put on the interactive mode
 *
 * We will use IF-ELSE statement to take action, on what the user will type.
 * User can type: append (to append a new student), list (to list all the students), 
 * delete (to delete a student), quit (to quit the interactive mode). Otherwise
 * if he type something that we dont case, it will return an alert message.
 * 
 * @param[in,out] - file
 * @param[in] - command
 *
 * @void program, so there will be no return value
 *************************************************************************/
void take_action(FILE *file,const char command[128]){
	if( (strcmp(command,APPEND)) == 0){
		if(append_action(file)==0){
			printf("Error while adding a new student in the file..\n");
			printf("Please try again!\n");
		}
	}else if(!strcmp(command,LIST)){
		if(list_action(file)==0){
			printf("Error while listing all students from the file...\n");
			printf("Please try again!\n");
		}
	}else if(!strcmp(command,DELETE)){
		delete_action(file);
	}else if(!strcmp(command,QUIT)){
		quit_action();
	}else if(!strcmp(command,CHANGE_LIMIT)){
		if(change_limit(file)==0){
			printf("Error while changing the limit number for students...\n");
			printf("Please try again!\n");
		}
	}else if(!strcmp(command,HELP)){
		interactive_help();
	}else{
		printf("Error on typing command.\n No command found with %s\n",command);
		interactive_help();
	}

}

/************************************************************************
 * @brief Will handle append action
 *
 * We will create a new student, allocating the memory for it. Than we will
 * fill the data in interactive form. After we fill the field with data
 * we will save the new student in the file.
 * 
 * @param[in,out] - file
 * @param[in] - none
 *
 * @retval 0 - in case of an error occurs
 * @retval 1 - if we add successfully a new student
 *************************************************************************/
int append_action(FILE *file){
	struct student *newStudent = (struct student *)malloc(sizeof(struct student));
	if(!newStudent){
		printf("Error while allocation memory for new student");
		return 0;
	}else{
		printf("Type student firstname: ");
		scanf("%s",(char *)&newStudent->firstname);
		printf("Type student lastname: ");
		scanf("%s",(char *)&newStudent->lastname);
		printf("Type student ID: ");
		scanf("%s",(char *)&newStudent->ID);
		printf("Type student age: ");
		scanf("%d",(int *)&newStudent->age);
		printf("Type student address:");
		scanf("%s",(char *)&newStudent->address);
		

	}
	if(addNewStudent(file,newStudent)==0){
		free(newStudent);
		return 0;
	}
	
	printf("Student has been added successfull in the file\n");
	free(newStudent);
	return 1;



}

/************************************************************************
 * @brief Will handle list action
 *
 * We will print all students in the console from the file.
 *
 * @param[in,out] - file
 * @param[in] - none
 *
 * @retval 0 - in case of an error occurs 
 * @retval 1 - if we list all students successfully
 *************************************************************************/
int list_action(FILE *file){
	fseek(file,0,SEEK_SET);
	if(getAllStudents(file)==0){
		return 0;
	}
	return 1;
}	

/************************************************************************
 * @brief Will handle delete action
 *
 * We will delete the given student
 *
 * @param[in,out] - file
 * @param[in] - none
 *
 * @void program, so there will be no return value
 *************************************************************************/
void delete_action(FILE *file){

	printf("delete action...(Will be implemented soon.)\n");



}

/************************************************************************
 * @brief Will handle quit action
 *
 * We will give a message that the program has been terminate. Than we will
 * exit the program.
 *
 * @param[in,out] - none
 * @param[in] - none
 *
 * @void program, so there will be no return value
 *************************************************************************/
void quit_action(){
	printf("This program has been terminated\n");
}

/************************************************************************
 * @brief Change limit number of students
 *
 * We will change the limit numbers of student
 *
 * @param[in,out] - file
 * @param[in] - none
 *
 * @retval 1, if we update successfully the total number of students
 * @retval 0, if an errr occurs
  *************************************************************************/
int change_limit(FILE *file){
	char stdNewLimit[4];
	printf("Type the new limit number for students: ");
	scanf("%s",(char *)stdNewLimit);
	if(changeStudentsLimitNumber(file,atoi(stdNewLimit))==0){
		return 0;
	}
	return 1;


}

/************************************************************************
 * @brief Will show which commands should be used
 *
 * We will print a message to the user, to make him easy to use the interactive
 * form
 *
 * @param[in,out] - none
 * @param[in] - none
 *
 * @void program, so there will be no return value
 *************************************************************************/
void interactive_help(){
	printf("******************************************************\n");
	printf("* Allowed Commands: \n");
	printf("*\t%s - For Appending a new student on the file\n",APPEND);
	printf("*\t%s - For listing all students from file\n",LIST);
	printf("*\t%s - For quiting the interactive mode\n",QUIT);
	printf("*\t%s - For deleting specific student (soon...)\n",DELETE);
	printf("*\t%s - For changing the limit number for students\n",CHANGE_LIMIT);
	printf("******************************************************\n");
}
