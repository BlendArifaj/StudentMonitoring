/*****************************************************************************
 * Copyright (C) 2019 BSc. Blend Arifaj. All rights reserved
 * Str. Agim Ramadani, Prishtine, Republic of Kosovo. blendarifaj@hotmail.com
 *
 * @file  functions.c
 *
 * @brief Implements the functions that will be used to complete the projet
 * 
 * @author (IS) BSc. Blend Arifaj (blendarifaj@hotmail.com)
 * @date   $Date: Fri May 17, 15:42:59 2019 $
 *****************************************************************************/
#include "functions.h"
#include <stdio.h>
#include <string.h>

/** *********************************************************************
 * @brief Add new student in the file
 * 
 * First we read the numbers of students, than we check if we have reach 
 * limits, if so than we print a message and return 0, else we get the 
 * current position of coursor in the file. Than we move with function 
 * fseek, to the end of the file. Than we write the new student's data 
 * in the file.
 *
 * @param[in,out] - file
 * @param[in] - std - the new student that will be add in the file
 *
 * @retval 0 in case an error was occured
 * @retval 1 in case if we add the new student successully on the file
 *************************************************************************/
int addNewStudent(FILE *file,const struct student *std){
	struct studentsData *stdData = (struct studentsData *)malloc(sizeof(struct studentsData));
	if(!stdData){
		printf("Error while allocation memory to variable stdData\n");
		return 0;	
	}	
	fseek(file,0,SEEK_SET);
	if(readStudentsData(file,stdData)==0){
		printf("Error while reading students data from file\n");
		free(stdData);
	}
	if(stdData->studentsLimitNumber > stdData->studentsNumber){
		if(appendStudent(file,std)==0){
			printf("Error while appending a new student into file \n");
			return 0;
			free(stdData);
		}else{
			fseek(file,0,SEEK_SET);
			if(incrementStudentsNumber(file)==0){
				printf("Gabim gjate update\n");	
				free(stdData);			
				return 0;
			}
		}
		free(stdData);
		return 1;
	}else{
		printf("Students number has reached limit number %d\n",stdData->studentsNumber);
		free(stdData);
		return 0;
	}
}

/** *********************************************************************
 * @brief Update the student's data with new one
 *
 * First we allocate memory on the temp variable, that we will use to
 * read students from file. Than we check if the students is on the
 * file, if it is than we update the old data with new one. If the can't
 * find the student one the file, we will return an error.Also, we 
 * dealocate the memory for the temp variable, on the end of the function
 *
 * @param[in,out] - file
 * @param[in] - oldStudentData, newStudentData
 *
 * @retval 0 in case an error was occured
 * @retval 1 in case if we update student's data successully on the file
 *************************************************************************/
int updateStudent(FILE *file,const struct student *oldStudentData, const struct student *newStudentData){
	int found = 0;
	struct student *temp_std = (struct student *)malloc(sizeof(struct student));
	if(!temp_std){
		printf("Error while allocation temp memory!");
		return 0;
	} 
	while(fread(temp_std,sizeof(struct student),1,file) != 0){
		if ( strcmp(temp_std->ID,oldStudentData->ID) == 0){
			found = 1;
			int currPos = ftell(file);
			fseek(file,currPos-sizeof(struct student),SEEK_CUR);
			if( (fwrite(newStudentData,sizeof(struct student), 1,file)) == 0){
				printf("Error while updating student on the file");
				free(temp_std);
				return 0;	
			}
			free(temp_std);
			return 1;
		}
	}
	if(!found){
		printf("No student found with the requested ID: %s\n",oldStudentData->ID);
		free(temp_std);		
		return 0;
	}
	return 1;
}


/** *********************************************************************
 * @brief Get all students from file
 *
 * First we allocate memory to the temp student variable, that we will use
 * to read students from file. Than we read the number of students in the 
 * file. Than we print all the students in the console. In the end we 
 * dealocate the alocated memory for temp variable
 *
 * @param[in,out] - file
 * @param[in] - none
 *
 * @retval 0 in case an error was occured
 * @retval 1 in case if we get all students from file
 *************************************************************************/
int getAllStudents(FILE *file){
	int n=0;
	struct studentsData *stdData = (struct studentsData *)malloc(sizeof(struct studentsData));
	if(!stdData){
		printf("Error while allocation memory to variable stdData\n");
		return 0;	
	}
	if(readStudentsData(file,stdData)==0){
		printf("Error while reading students data from file\n");
	}
	printf("Student current number: %d\nStudents Limit Number: %d\n",stdData->studentsNumber,stdData->studentsLimitNumber);
	printf("\tStudent      \tID\tAge\tAddress\t\n");
	for(n=1;n<(int)stdData->studentsNumber+1;n++){
		struct student *std = (struct student *)malloc(sizeof(struct student));
		if(!std){
			printf("Error while allocation memory to variable std\n");
			return 0;	
		}
		if(readStudent(file,std)==0){
			printf("Error while reading students.\n");
			free(stdData);
			free(std);
			return 0;
		}		
		printStudent(n,std);
		free(std);
	}
	free(stdData);
	return 1;

}

/** *********************************************************************
 * @brief Write student data in the file (number of students)
 *
 * We try to write the number of students in the file. If we write it we
 * return positive results, otherwise we return an error.
 *
 * @param[in,out] - file
 * @param[in] - stdData
 *
 * @retval 0 in case an error was occured
 * @retval 1 in case if we write data successfully in the file
 *************************************************************************/
int writeStudentsData(FILE *file,const struct studentsData *stdData){
	fseek(file,0,SEEK_SET);
	if(fwrite(stdData, sizeof(struct studentsData), 1, file) == 0){
		printf("Error while writing the number of students \n");
		return 0;	
	}
	return 1;
}

/** *********************************************************************
 * @brief Write student into a file
 *
 * We try to store a student into  file, if we write it successfully we 
 * return 1, otherwise we return 0;
 *
 * @param[in,out] - file
 * @param[in] - std
 *
 * @retval 0 in case an error was occured
 * @retval 1 in case if we write data successfully in the file
 *************************************************************************/
int writeStudent(FILE *file,const struct student *std){
	if(fwrite(std, sizeof(struct student), 1, file) == 0){
		return 0;	
	}
	return 1;
}

/** *********************************************************************
 * @brief Append a new student into a file
 *
 * We move a cursor position in the end of the file, than we try to write 
 * a new student into a file. After that we increment the total students number
 * in file.
 *
 * @param[in,out] - file
 * @param[in] - std
 *
 * @retval 0 in case an error was occured
 * @retval 1 in case if we write data successfully in the file
 *************************************************************************/
int appendStudent(FILE *file,const struct student *std){
	fseek(file,0,SEEK_END);
	if(writeStudent(file,std)==0){
		return 0;
	}
	return 1;
}


/** *********************************************************************
 * @brief Update the number of students on the file
 *
 * First we get the current position of coursor in the file. Than we move
 * the position on the beginning of the file. We oweride the number of 
 * students with the new number.
 *
 * @param[in,out] - file
 * @param[in] - stdData 
 *
 * @retval 0 in case an error was occured
 * @retval 1 in case if update the number of students successfully
 *************************************************************************/
int updateStudentsData(FILE *file,const struct studentsData *stdData){
	fseek(file,0,SEEK_SET);
	if(fwrite(stdData, sizeof(struct studentsData), 1, file) == 0){
		printf("Error while updating the number of students \n");
		return 0;	
	}
	printf("Total numbers of students is now updated to %d\n",stdData->studentsNumber);
	return 1;
}

/** *********************************************************************
 * @brief Update the number of students on the file
 *
 * First we get the current position of coursor in the file. Than we move
 * the position on the beginning of the file. We oweride the number of 
 * students with the new number.
 *
 * @param[in,out] - file
 * @param[in] - stdData 
 *
 * @retval 0 in case an error was occured
 * @retval 1 in case if update the number of students successfully
 *************************************************************************/
int changeStudentsLimitNumber(FILE *file,const int newLimit){
	struct studentsData *stdData = (struct studentsData *)malloc(sizeof(struct studentsData));	 

	if(!stdData){
		printf("Error while allocation memory to variable stdData\n");
		return 0;	
	}
	fseek(file,0,SEEK_SET);
	if(readStudentsData(file,stdData)==0){
		printf("Error while reading students data from file\n");
		free(stdData);
		return 0;
	}
	stdData->studentsLimitNumber = newLimit;
	fseek(file,0,SEEK_SET);
	if(writeStudentsData(file,stdData)==0){
		printf("Error while writing students data in file\n");
		free(stdData);
		return 0;
	}
	printf("Limit of students number is changed to: %d\n",stdData->studentsLimitNumber);
	free(stdData);	
	return 1;
}

/** *********************************************************************
 * @brief Get total number of students
 *
 * We try to read the total number from file. If we can read than we
 * return 1, otherwise we return an error.
 *
 * @param[in,out] - file,stdData
 * @param[in] - none
 *
 * @retval 0 in case an error was occured
 * @retval 1 in case if we get the total number of students from file
 *************************************************************************/
int readStudentsData(FILE *file,struct studentsData *stdData){
	if((int)fread(stdData,sizeof(struct studentsData),1,file) == 0){
		printf("Error while reading the number of students \n");
		return 0;
	}
	return 1;
}

/** *********************************************************************
 * @brief Read student data from file
 *
 * We try to read student's data from file. If we can read than we
 * return 1, otherwise we return 0.
 *
 * @param[in,out] - file,std
 * @param[in] - none
 *
 * @retval 0 in case an error was occured
 * @retval 1 in case if we get the total number of students from file
 *************************************************************************/
int readStudent(FILE *file,struct student *std){
	if((int)fread(std,sizeof(struct student),1,file) == 0){
		printf("Error while reading the number of students \n");
		return 0;
	}
	return 1;
}


/** *********************************************************************
 * @brief Increment total students number for one
 *
 * First we read the total number of the students, than we increment it 
 * and try to save in file.
 *
 * @param[in,out] - file
 * @param[in] - none
 *
 * @retval 0 in case an error was occured
 * @retval 1 in case if increment total students number for one
 *************************************************************************/
int incrementStudentsNumber(FILE *file){
	struct studentsData *stdData = (struct studentsData *)malloc(sizeof(struct studentsData));
	if(!stdData){
		printf("Error while allocation memory to variable stdData\n");
		return 0;	
	}
	fseek(file,0,SEEK_SET);
	if(readStudentsData(file,stdData)==0){
		printf("Error while reading students data into file");
		free(stdData);	
		return 0;
	}
	stdData->studentsNumber = stdData->studentsNumber + 1;
	fseek(file,0,SEEK_SET);
	if(writeStudentsData(file,stdData)==0){
		printf("Error while writing students data into file");
		free(stdData);
		return 0;
	}
	fseek(file,0,SEEK_SET);	
	free(stdData);
	return 1;

	/*
	fseek(file,0,SEEK_SET);
	struct studentsData *stdData = (struct studentsData *)malloc(sizeof(struct studentsData));
	if(readStudentsData(file,stdData)==0){
		printf("Error while reading students data\n");
		free(stdData);
		return 0;
	}
	printf("Student's current number %d\n",stdData->studentsNumber);
	stdData->studentsNumber = stdData->studentsNumber + 1;
	printf("Student's after number %d\n",stdData->studentsNumber);
	fseek(file,0,SEEK_SET);
	if(fwrite(stdData, sizeof(struct studentsData), 1, file) == 0){
		printf("Error while writing the number of students \n");
		return 0;	
	}else{
		printf("SS\n");
	}
	free(stdData);
	return 1;*/
}

/** *********************************************************************
 * @brief Decrement total students number for one
 *
 * First we read the total number of the students, than we increment it 
 * and try to save in file.
 *
 * @param[in,out] - file
 * @param[in] - none
 *
 * @retval 0 in case an error was occured
 * @retval 1 in case if increment total students number for one
 *************************************************************************/
int decrementStudentsNumber(FILE *file){
	fseek(file,0,SEEK_SET);
	struct studentsData *stdData = (struct studentsData *)malloc(sizeof(struct studentsData));
	if(!stdData){
		printf("Error while allocation memory to variable stdData\n");
		return 0;	
	}
	if(readStudentsData(file,stdData)==0){
		printf("Error while reading students data\n");
		free(stdData);
		return 0;
	}
	stdData->studentsNumber = stdData->studentsNumber - 1;
	fseek(file,0,SEEK_SET);
	if(writeStudentsData(file,stdData)==0){
		printf("Error while writing students data in file\n");
		free(stdData);
		return 0;
	}
	free(stdData);
	return 1;
}

/** *********************************************************************
 * @brief Print student data in console
 *
 * We just print student's data in console
 *
 * @param[in,out] - none
 * @param[in] - std
 *
 * @retval none - void has not return value
 *************************************************************************/
void printStudent(int n,const struct student *tmp_std){
	printf("%d     %s %s %s %d %s\n",n,tmp_std->firstname,tmp_std->lastname,tmp_std->ID,tmp_std->age,tmp_std->address);
}

/** *********************************************************************
 * @brief Initialize the file
 *
 * We try to initilize the file, to write student's data into file
 *
 * @param[in,out] - file
 * @param[in] - none
 *
 * @retval 0 in case if we fail to initialize the file
 * @retval 1 in case when we initialize the file successfully
 *************************************************************************/
int initiateFile(FILE *file){
	struct studentsData *stdData = (struct studentsData *)malloc(sizeof(struct studentsData));
	if(!stdData){
		printf("Error while allocation memory to variable stdData\n");
		return 0;	
	}
	stdData->studentsNumber = 0;
	stdData->studentsLimitNumber = 40;
	fseek(file, 0, SEEK_END);
	if(writeStudentsData(file,stdData)==0){
		printf("Error while initializing new file ...\n");
		free(stdData);
		return 0;
	}
	free(stdData);
	return 1;
}

/** *********************************************************************
 * @brief Check if the file is emptry
 *
 * First we check if the file is empty, if it so than we fullfill with the
 * needed data
 *
 * @param[in,out] - file
 * @param[in] - none
 *
 * @retval 0 in case if we fail to initialize the file
 * @retval 1 in case when we initialize the file successfully or its not empty
 *************************************************************************/
int checkIfEmpytyFile(FILE *file){
	fseek(file, 0, SEEK_END);
    	unsigned long len = (unsigned long)ftell(file);
	if (len == 0) { 
		if(initiateFile(file)==0){
			return 0;
		}
	}
	return 1;
}

/** *********************************************************************
 * @brief Create new file
 *
 * We try to open a new file in CREATE mode, if we create it successfully 
 * than we initialize it.
 *
 * @param[in,out] - file
 * @param[in] - newFileName
 *
 * @retval 0 in case if we fail create a new file
 * @retval 1 in case when we successfully create a new file
 *************************************************************************/
int createNewFile(FILE **file,const char *newFileName){
	if( (*file=fopen(newFileName,"wb")) ==0){
		printf("Error while creating a new file\n");
		return 0;
	}
	if(initiateFile(*file)==0){
		return 0;
	}
	return 1;

}


