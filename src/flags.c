/*
** EPITECH PROJECT, 2021
** flags.c
** File description:
** It calls the checked flags
*/

#include "../include/my_ls.h"
#include "../include/lib.h"

void flags_list(struct dirent *entry, flag_t *flags, int *next_line, char *arg)
{
    int i = 0;
    int checked_flag_l = 0;

    while (i < 5) {
        if (flags[i].type == 'l' && flags[i].checked == 1) {
            l_format(entry, &checked_flag_l, arg);
        }
        i++;
    }
    if (checked_flag_l == 0) {
        my_putstr(entry->d_name);
        my_putchar(' ');
        *next_line = 1;
    }
}
