/*****************************************************************************
 * Copyright (C) 2019 BSc. Blend Arifaj. All rights reserved
 * Str. Agim Ramadani, Prishtine, Republic of Kosovo. blendarifaj@hotmail.com
 *
 * @file  functions.h
 *
 * @brief Declare the functions and variables that will used by functions
 * 
 * @author (IS) BSc. Blend Arifaj (blendarifaj@hotmail.com)
 * @date   $Date: Fri May 17, 15:42:59 2019 $
 *****************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include "student.h"

int addNewStudent(FILE *file, const struct student *std);
int updateStudent(FILE *file,const struct student *oldStudentData, const struct student *newStudentData);
int deleteStudent(FILE *file,const struct student *std);
int getAllStudents(FILE *file);

int writeStudentsData(FILE *file,const struct studentsData *stdData);
int updateStudentsData(FILE *file,const struct studentsData *stdData);
int readStudentsData(FILE *file,struct studentsData *stdData);
int appendStudent(FILE *file,const struct student *std);
int writeStudent(FILE *file,const struct student *std);
int readStudent(FILE *file,struct student *std);

int incrementStudentsNumber(FILE *file);
int decrementStudentsNumber(FILE *file);
int changeStudentsLimitNumber(FILE *file,const int newLimit);

void printStudent(int n,const struct student *std);

int initiateFile(FILE *file);
int checkIfEmpytyFile(FILE *file);
int createNewFile(FILE **file,const char *newFileName);

