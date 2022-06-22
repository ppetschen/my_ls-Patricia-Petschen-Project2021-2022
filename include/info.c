/*
** EPITECH PROJECT, 2021
** info
** File description:
** for general ls
*/

#include "my_ls.h"

void info(struct dirent *entry)
{
    if (entry != 0 && entry->d_name[0] != '.') {
        my_putstr(entry->d_name);
        my_putstr("  ");
    }
}
