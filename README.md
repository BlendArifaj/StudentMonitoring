# StudentMonitoring
Student Monitoring using Binary Files in C Programming

This program will menage the students for specific course. In the file will be stored students, with limited number, with data: firstname, lastname, id, age and address. 

With this program you can add a new student, read students from the file, change the students limit number to the file and many other stuff that will help you to manage the student's data right.

First to make the program useable you have to make the exe file, writing in this directirium: 
make all.

To Generate the documentation for the functions you have to write, in this directirium, make dox.

After making the exe file, to execute the program you write: ./output/exe/exe -help (-h, --h or --help), and this will show the allowed arguments and their functionality.

The mandatory argument is -f followed by file name (./output/exe/exe -f filename), if the file does not exist than new file will be created with 0 students and the maximum student number 40, otherwise nothing will happen, because you did not specify what to do.

If you want to list all students that are stored in the file you type: ./output/exe/exe -f filename -l. If the file does not exist than new file will be created with 0 students and the maximum students number 40, else the program will show all the students stored on the file.

If you want to list all students that are stored in the file and than append a new student you type: ./output/exe/exe -f filename -l -a. If the file does not exist than new file will be created with 0 students and the maximum students number 40, else the program will show all the students stored on the file than request data for new student to store in the file.

To add a new student in the file you type: ./output/exe/exe -f filename -a. If the file does not exist than new file will be created with 0 students and the maximum students number 40, else the program will required from you to type student's data.

To add a new student in the file and to list all students after you type: ./output/exe/exe -f filename -a -l. If the file does not exist than new file will be created with 0 students and the maximum students number 40, else the program will required from you to type student's data to store in the file and after will show all students that are stored in the file.

To change the student's total number you type: ./output/exe/exe -f filename -cl num. If the file does not exist than new file will be created with 0 students and the maximum students number 40, else the program will change the limit of students to num.

To start the interactive mode you type: ./output/exe/exe -f filename -i. If the file does not exist than new file will be created with 0 students and the maximum students number 40, else the program will start the interactive mode. In interactive mode you can type: append, list, help, quit and chlimit.
If you type, in interactive mode,:
	append - than the program will required from you to type new student's data, to store them in the file
	list - program will be list all students that are stored in the file
	help - will show how to use interactive mode
	quit - will quit the program
	chlimit - program will required from you new limit number, than change the limit for the student's number

In case if program is blocked or something else, you can terminate program using CTRL+C.
