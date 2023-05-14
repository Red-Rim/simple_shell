#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <>

/*Red-Rim & Fatimazahraker*/

int _putchar(char c);
int _putstr(char *str);
int _strlen(char *s);
char *gettoks(char *str);
int main(int argc, char *argv[]);

#endif
