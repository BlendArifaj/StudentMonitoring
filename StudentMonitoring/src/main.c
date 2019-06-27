/*****************************************************************************
 * Copyright (C) 2019 BSc. Blend Arifaj. All rights reserved
 * Str. Agim Ramadani, Prishtine, Republic of Kosovo. blendarifaj@hotmail.com
 *
 * @file  main.c
 *
 * @brief Implements the main function
 * 
 * @author (IS) BSc. Blend Arifaj (blendarifaj@hotmail.com)
 * @date   $Date: Fri May 17, 15:39:59 2019 $
 *****************************************************************************/
#include "functions.h"
#include <unistd.h>
int work_mode = 0;

int main (int argc, const char *argv [])
{
/* we are going to store files in src folders, so we change the directirium to output */
	if(chdir("output/")==-1){
		printf("Error while changing directirium\n");
	}
/*Terminate code for the program // CTRL+C */
	terminate_program();	
	/*File name*/
	FILE *file;
	/*First we controll if function is called with 2 parameters, and if second parameter is called for help form.
	 If we call the program with only one parameter, than we have an error.*/	
	if(argc==2 && help_check(argv[1])==1){
		work_mode = NON_INTERACTIVE_MODE;
		help_form();
		return 0;
	/*When user didn't call the function right */
	}else if(argc<2 || strcmp(argv[1],FILE_ARG) !=0){
		printf("Error on calling the function ... \n\n");
		help_form();
		return 0;
	}else{
		/* If user didn't specify the file */
		if(argv[2] == NULL){
			printf("The file option (-f f_name) has to be defined\n\n");
			help_form();
			return 0;
		}
		/*Try to open file*/
		if( (file = fopen(argv[2],OPEN_FILE_MODE)) == 0){
			printf("File not found ...\n We are creating a new file named: %s\n",argv[2]);
			/*If we can't open file than we create new one*/
			if( createNewFile(&file,argv[2]) == 0){
				fclose(file);				
				return 0;
			}else{
				printf("File %s is created successfully!\n",argv[2]);
				fclose(file);
				return 0;
			}
		}else{
			/* If the file is empty than we initialize it */
			if(checkIfEmpytyFile(file)==0){
				printf("Errow while initializing the file ...\n");
				return 0;
			};
		}
	}
	/* We check for many arguments */
	if(argc == 4 || argc==5){
		/*Call for interactive mode*/
		if( argv[4] == NULL && strcmp(argv[3],INTERACTIVE_MODE_ARG)==0 ){
			work_mode = INTERACTIVE_MODE;			
			interactive_part(file,work_mode);
			fclose(file);
			return 0;
		/*Call for List (and Append)*/
		}else if(strcmp(argv[3],LIST_ALL_STUDENT_ARG)==0){
			work_mode = NON_INTERACTIVE_MODE;
			if(argv[4] !=NULL){
				if(strcmp(argv[4],APPEND_ARG)==0 ){
					if(list_action(file)==0){
						printf("Error while listing student from file\n");
						fclose(file);
						return 0;
					}
					if(append_action(file)==0){
						printf("Error while appending student in file\n");
						fclose(file);
						return 0;
					}
					fclose(file);
					return 1;
				}else{
					printf("Error on calling the function ... \n\n");
					help_form();
					fclose(file);
					return 0;
				}
			}
			if(list_action(file)==0){
				printf("Error while listing student from file\n");
				fclose(file);
				return 0;
			}			
			fclose(file);
			return 0;		
		/*Call for Append (and List)*/	
		}else if(strcmp(argv[3],APPEND_ARG)==0){
			work_mode = NON_INTERACTIVE_MODE;
			if(argv[4] !=NULL){
				if(strcmp(argv[4],LIST_ALL_STUDENT_ARG)==0 ){
					if(append_action(file)==0){
						printf("Error while appending student in file\n");
						fclose(file);
						return 0;
					}
					if(list_action(file)==0){
						printf("Error while listing student from file\n");
						fclose(file);
						return 0;
					}
					fclose(file);
					return 0;			
				}else{
					printf("Error on calling the function ... \n\n");
					help_form();
					fclose(file);
					return 0;
				}
			}			
			if(append_action(file)==0){
				printf("Error while appending student in file\n");
				fclose(file);
				return 0;
			}
			fclose(file);
			return 0;
		/*Call for Chlimit*/
		}else if(strcmp(argv[3],CHANGE_LIMIT_STUDENT_NUM_ARG)==0 && argv[4] != NULL){
			work_mode = NON_INTERACTIVE_MODE;
			if(changeStudentsLimitNumber(file,atoi(argv[4]))==0){
				printf("Error while updating the limit number\n");
				fclose(file);
				return 0;
			}
			fclose(file);
			return 1;
		}else{
			printf("Error on calling the function ... \n\n");
			help_form();
			fclose(file);
			return 0;
		}
	/*Wrong call*/
	}else if(argc>5){
		printf("Error on calling the function ... \n\n");
		help_form();
		fclose(file);
		return 0;
	}
	fclose(file);
	return 1;
}






