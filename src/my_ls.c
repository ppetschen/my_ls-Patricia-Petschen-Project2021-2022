/*
** EPITECH PROJECT, 2021
** my_ls.c
** File description:
** It's the command ls of the terminal
*/

#include "../include/my_ls.h"
#include "../include/lib.h"

flag_t *is_flag(char *arg, flag_t *flags)
{
    int i = 1;
    int f = 0;

    while (arg[i] != '\0') {
        while (f < 5) {
            if (arg[i] == flags[f].type) {
                flags[f].checked = 1;
            }
            f++;
        }
        f = 0;
        i++;
    }
    return flags;
}

flag_t *detect_flags(int ac, char **av, flag_t *flags)
{
    int i = 1;

    while (i < ac) {
        if (av[i][0] == '-') {
            flags = is_flag(av[i], flags);
        }
        i++;
    }
    return flags;
}

int is_file(char *str)
{
    struct stat *fileinfo;

    return stat(str, fileinfo);
}

int is_folder(char *str)
{
    DIR *dir;

    dir = opendir(str);
    if (dir == NULL) {
        return 0;
    } else {
        return 1;
    }
}

void print_folder(char *arg, flag_t *flags)
{
    DIR *dir = opendir(arg);
    struct dirent *entry = readdir(dir);
    int next_line = 0;

    while (entry != 0) {
        if (entry->d_name[0] != '.') {
            flags_list(entry, flags, &next_line, arg);
        }
        entry = readdir(dir);
    }
    if (next_line == 1) {
        my_putchar('\n');
    }
}
