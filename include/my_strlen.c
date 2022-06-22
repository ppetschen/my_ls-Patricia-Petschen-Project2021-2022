/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** Returns the length of the string
*/

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}