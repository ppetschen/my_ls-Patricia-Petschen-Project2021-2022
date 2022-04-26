/*
** EPITECH PROJECT, 2021
** my_putchar.c
** File description:
** Writes a char
*/

#include "../include/lib.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
