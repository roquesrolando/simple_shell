#ifndef SHELL_HEADER_H
#define SHELL_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>

char **input(void);
int numberOfElementsInArray(char *usrinput);
int moveIndex(char *usrinput);
char *strConcat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
char **getArray(char *usrinput);
char **get_path(char **env);
char *getFullPath(char **path, char **command);
void freeDoublePointers(char **pointer);
void printDoubleArray(char **pointer);
void executeCommand(char *fullPath, char **commandLineArgs);
char *pathInput(char *usrInput);
int moveIndex(char *usrinput);
char *_strdup(char *str);
int _putchar(char c);
int _strcmp2(char *s1, char *s2);

#endif
