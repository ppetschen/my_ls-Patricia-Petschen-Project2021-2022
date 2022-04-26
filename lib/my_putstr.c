/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** Writes a string
*/

#include "../include/lib.h"

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
