/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** It's the main function
*/

#include "../include/my_ls.h"
#include "../include/lib.h"

int main(int ac, char **av)
{
    flag_t *flags = initialize_flags();
    int i = 1;

    flags = detect_flags(ac, av, flags);
    while (i < ac) {
        if (is_folder(av[i]) == 1) {
            if (ac > 2) {
                my_putstr(av[i]);
                my_putstr("/:\n");
            }
            print_folder(av[i], flags);
            if (ac > 2 && i < ac - 1)
                my_putchar('\n');
        } else if (is_file(av[i]) == 0) {
            my_putstr(av[i]);
        }
        i++;
    }
    if (ac == 1)
        print_folder("./", flags);
}
