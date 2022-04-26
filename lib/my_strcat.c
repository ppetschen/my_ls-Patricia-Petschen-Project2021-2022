/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** Returns the sum of two strings
*/

#include "../include/lib.h"
#include "../include/my_ls.h"

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    int len_dest = my_strlen(dest);
    int len_src = my_strlen(src);
    char *result = malloc(len_dest + len_src);

    while (i < len_dest) {
        result[i] = dest[i];
        i++;
    }
    result[i] = '/';
    while (j < len_src) {
        result[i] = src[j];
        i++;
        j++;
    }
    return result;
}
