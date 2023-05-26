#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include <errno.h>
#include <limits.h>

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
char *_strcpy(char *dest, char *src);
char *cmnd_path(char *command);
void _env(char **cmd, char *buffer, char *path, int a);
char *_strdup(char *str);
char *getlinebuffer(void);
int _setenv(const char *name, const char *value);
int _unsetenv(const char *name);
void _eexit(char **cmd, char *buffer, char *path, int a);
void argc(int argc, char *argv[]);
int _isstrdigit(char *str);
int _isdigit(int a);
int _cd(const char *path);
char *_getenv(const char *name);

#endif
