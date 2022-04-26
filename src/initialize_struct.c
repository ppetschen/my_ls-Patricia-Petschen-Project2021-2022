/*
** EPITECH PROJECT, 2021
** intialize_struct.c
** File description:
** It initializes all the structs
*/

#include "../include/my_ls.h"

flag_t *initialize_flags(void)
{
    flag_t *flags = malloc(sizeof(flag_t) * 5);

    flags[0].type = 'l';
    flags[1].type = 'R';
    flags[2].type = 'd';
    flags[3].type = 'r';
    flags[4].type = 't';
    return flags;
}
