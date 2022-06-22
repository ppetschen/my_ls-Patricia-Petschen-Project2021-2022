/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** makefile
*/

#ifndef MY_LS_H_
#define MY_LS_H_

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>
#include <grp.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <utime.h>
#include <sys/time.h>

void my_putstr(char const *);
int my_put_nbr(int);
void my_putchar(char c);
void info(struct dirent *entry);
int no_flag(int nb);
void flag_one(char *);
char *my_int_to_str(int nbr);
char *my_strcat(char *dest, char *src);
int my_strlen(char *str);

#endif /* !MY_LS_H_ */
