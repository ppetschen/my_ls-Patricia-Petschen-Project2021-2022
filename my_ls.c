/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** my_ls
*/

#include "include/my_ls.h"

void chek_flag(char **str)
{
    int i = 0;
    while (str[1][i] != '\0') {
        if (str[1][0] == '-' && str[1][i] == 'l') {
            flag_one(str[i]);
        }
        i++;
    }
}

int if_directory(char *str)
{
    DIR *dir = opendir(str);

    if (dir == NULL) {
        return (0);
    } else {
        return (1);
    }
}

int main(int ac, char **av)
{
    int i = 1;
    int entered_directory = 0;
    if (ac == 1) {
        no_flag(ac);
        return (0);
    }
    while (i < ac) {
        if (if_directory(av[i]) == 1 && av[1][0] != '-' ) {
            no_flag(ac);
            return (0);
        }
        if (if_directory(av[i]) == 1 && av[1][0] == '-' ) {
            chek_flag(av);
            entered_directory = 1;
        }
        i++;
    }
    if (entered_directory == 0) {
        flag_one("./");
    }
}
