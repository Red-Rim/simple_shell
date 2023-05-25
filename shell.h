#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX 9

extern char **environ;

/*Red-Rim & Fatimazahraker*/

int _putchar(char c);
int _putstr(char *str);
int _strlen(char *s);
char **gettoks(char *str, char *deliminer);
int _strncmp(const char *s1, const char *s2, size_t n);
size_t _strcspn(const char *s1, const char *s2);
void freetoken(char **tok);
int _execve(char **comnd, char *path);
char *_getenv(char *name);
char *_strcpy(char *dest, char *src);
char *cmnd_path(char *command);
int _env(char **cmd, char *buffer);
char *_strdup(char *str);
char *getlinebuffer(void);
int _setenv(const char *name, const char *value);
int _unsetenv(const char *name);
void _eexit(char **cmd, char *buffer, int a);
void argc(int argc, char *argv[]);
int _isstrdigit(char *str);
int _isdigit(int a);

#endif
