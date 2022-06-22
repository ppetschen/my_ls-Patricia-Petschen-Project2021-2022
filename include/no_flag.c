/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** no flags
*/

#include "my_ls.h"

int no_flag(int nb)
{
    DIR *dir;
    struct dirent *entry;
    dir = opendir("./");
    while (entry != 0) {
        entry = readdir(dir);
        info(entry);
    }
    my_putstr("\n");
    closedir(dir);
    return (nb);
}
