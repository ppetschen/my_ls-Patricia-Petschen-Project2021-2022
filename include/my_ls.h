/*
** EPITECH PROJECT, 2021
** my_ls.h
** File description:
** It declares all needed functions and headers
*/

#ifndef MY_LS_H_
    #define MY_LS_H_

    //Delete before push
    #include <stdio.h>

    //Opendir
    #include <sys/types.h>
    #include <dirent.h>

    //Malloc
    #include <stdlib.h>

    //Stat
    #include <sys/stat.h>
    #include <unistd.h>

    //Pw
    #include <pwd.h>
    #include <grp.h>

    //Time
    #include <time.h>

typedef struct flag {
    char type;
    int checked;
} flag_t;

typedef struct l_format {
    char *permission;
    int nb;
    char *user;
    char *name;
    int nb2;
    char *date;
    char *file_name;
} l_format_t;


//my_ls.c
flag_t *detect_flags(int ac, char **av, flag_t *flags);
int is_folder(char *str);
void print_folder(char *arg, flag_t *flags);
int is_file(char *str);

//flags.c
void l_format(struct dirent *, int *, char *);

//initialize_struct.c
flag_t *initialize_flags(void);

//flags.c
void flags_list(struct dirent *, flag_t *, int *, char *);

#endif /* !MY_LS_H_ */
