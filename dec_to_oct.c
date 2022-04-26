/*
** EPITECH PROJECT, 2021
** dec_to_oct
** File description:
** pass from decimal to octal
*/

#include "my_ls.h"

int dec_to_oct(int dec)
{
    int res = 0;
    int temp_dec;
    int tens = 1;
    int prev_dec;

    while (dec > 0) {
        prev_dec = dec;
        dec = dec / 8;
        temp_dec = 8 * dec;
        res += (prev_dec - temp_dec) * tens;
        tens = tens * 10;
    }
    my_put_nbr(res);
    return (0);
}
