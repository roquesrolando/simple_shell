# 0X16.C-SIMPLE SHELL

Written by Caroline Del Carmen and Rolando Roques
as part of our **Simple Shell** Holberton School Project.

Project Description/Restrictions:  
  
List of allowed functions and system calls  

    access (man 2 access)  
	chdir (man 2 chdir)  
	close (man 2 close)  
	closedir (man 3 closedir)  
	execve (man 2 execve)  
	exit (man 3 exit)  
	_exit (man 2 _exit)  
	fflush (man 3 fflush)  
	fork (man 2 fork)  
	free (man 3 free)  
	getcwd (man 3 getcwd)  
	getline (man 3 getline)  
	getpid (man 2 getpid)  
	isatty (man 3 isatty)  
	kill (man 2 kill)  
	malloc (man 3 malloc)  
	open (man 2 open)  
	opendir (man 3 opendir)  
	perror (man 3 perror)  
	read (man 2 read)  
	readdir (man 3 readdir)  
	signal (man 2 signal)  
	stat (__xstat) (man 2 stat)  
	lstat (__lxstat) (man 2 lstat)  
	fstat (__fxstat) (man 2 fstat)  
	strtok (man 3 strtok)  
	wait (man 2 wait)  
	waitpid (man 2 waitpid)  
	wait3 (man 2 wait3)  
	wait4 (man 2 wait4)  
	write (man 2 write)  

	Our project is to write a simple UNIX command interpreter. Our shell can only use functions from the allowed list below.
	Further down we list examples of how our Shell output should look like, and what it can handle.


**Compiled with**  

gcc -Wall -Werror -Wextra -pedantic *.c *.h -o myshell  
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./myshell  

I. File List
------------
- shell_header.h  
  - Header file. Contains libraries & prototypes.  
- main.c  
  - Contains main function. It finds the enviroment PATH and calls other functions until user enters "exit".  
- path.c  
  - Contains our get_path function that splits the PATH into a 2D array.
- input.c  
  - Contains functions that handle the user input and convert it into an array.  
- stringConcat.c  
  - Contains functions that concatenate char arrays.  
- getFullPath.c  
  - Contains function that checks the PATH for the specified executuble.  
- execute.c
  - Contains function that duplicates process and executes commands.  
- freePointers.c
  - Contains funtion that frees double pointers.  
- lengths.c
  -contains functions that work with our input file to trim any extra spaces off the input and allow executables to be entered in as input.

II. Design
----------
The program is designed to mimic the abilities of a simple shell. It is capable of handling
simple commands with arguments. For example "ls -l". It can also handle the PATH as an argument, for example 
"/bin/ls". It works also in nonteractive mode, for example "echo "/bin/ls" | ./myshell". Below are some examples:

Example:  
**$ ls**  
main.c	path.c	execute.c	stringConcat.c  

**$ /bin/ls**  
main.c	path.c	execute.c	stringConcat.c  

**$ ls | ./myshell**  
main.c	path.c	execute.c	stringConcat.c  

**$ pwd**  
/home/vagrant/shell/simple_shell  

**/bin/pwd**  
/home/vagrant/shell/simple_shell  

III. File Descriptions
----------------------
A. **shell_header.h**  

This is our header file. It contains the libraries used in our code:  
  
#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <string.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <sys/wait.h>  
#include <fcntl.h>  
#include <dirent.h>  
  
The prototypes for all functions are also listed here.  

B. **main.c**  

Contains:  
int main(int ac, char **av, char **env)  
Function uses the int main(int ac, char **av, char **env) declaration in order to take in values
for main before running our simple shell program and get the enviroment variables in order to 
find the PATH.  

C. **path.c**  

Contains:  
char **get_path(char **env)  
Function parses through the enviroment variables and returns the PATH array.  

D. **input.c**  

Contains:  
char **input(void)  
char **getArray(char *usrinput)  
 int _strcmp(char *s1, char *s2)  

First user input is acquired in input function. The input from user is set to the getArray function,
that converts the input into a 2D array. The compare function is used to validate commands like "exit"  

E. **stringConcat.c**  

Contains:  
char *strConcat(char *s1, char *s2)  
The user's input and the directory returned by getFullPath are pass to this function that concatenates
both string into a single string and returns it to main.  

F. **getFullPath.c**  

Contains:  
char *getFullPath(char **patharray, char **commandLineArgs)  

Functions recieves the PATH array found by get_path and opens every directory and goes throught all the files
in the directories comparing it with the user's input until it finds the folder for the command. Once found
it returns the directore with the folder that contains the binary code to run the command.  

G.**execute.c**  

Contains:  
void executeCommand(char *fullPath, char **commandLineArgs)  

The function recieves the concatenated string made by strConcat and the input from the user and runs both
variables with the exceve command to run the command.  

H.**freePointers.c**  

Contains:  
void freeDoublePointers(char **pointer)  

This function frees any memory allocated for a pointer.  
