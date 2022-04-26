/*
** EPITECH PROJECT, 2021
** flags.c
** File description:
** Execute the functions of the given flags
*/

#include "../include/my_ls.h"
#include "../include/lib.h"

void l_format_permission(struct stat fileinfo)
{
    my_putchar((fileinfo.st_mode & S_IFDIR) ? 'd' : '-');
    my_putchar((fileinfo.st_mode & S_IRUSR) ? 'r' : '-');
    my_putchar((fileinfo.st_mode & S_IWUSR) ? 'w' : '-');
    my_putchar((fileinfo.st_mode & S_IXUSR) ? 'x' : '-');

    my_putchar((fileinfo.st_mode & S_IRGRP) ? 'r' : '-');
    my_putchar((fileinfo.st_mode & S_IWGRP) ? 'w' : '-');
    my_putchar((fileinfo.st_mode & S_IXGRP) ? 'x' : '-');

    my_putchar((fileinfo.st_mode & S_IROTH) ? 'r' : '-');
    my_putchar((fileinfo.st_mode & S_IWOTH) ? 'w' : '-');
    my_putchar((fileinfo.st_mode & S_IXOTH) ? 'x' : '-');

    my_putchar(' ');
}

void l_format_name(struct stat fileinfo)
{
    struct passwd *password = getpwuid(fileinfo.st_uid);
    struct group *group = getgrgid(fileinfo.st_gid);

    my_putchar(fileinfo.st_nlink + 48);
    my_putchar(' ');
    my_putstr(password->pw_name);
    my_putchar(' ');
    my_putstr(group->gr_name);
    my_putchar(' ');
}

void l_format_time(struct stat fileinfo)
{
    char *time_t = ctime(&fileinfo.st_mtime);
    int len = my_strlen(time_t) - 13;
    int i = 0;
    char *time = malloc(len);

    while (i < len) {
        time[i] = time_t[i];
        i++;
    }
    write(1, time_t, len);
    my_putchar(' ');
}

void l_format(struct dirent *entry, int *checked_flag, char *arg)
{
    struct stat fileinfo;
    char *pathname = my_strcat(arg, entry->d_name);

    stat(pathname, &fileinfo);
    l_format_permission(fileinfo);
    l_format_name(fileinfo);
    my_put_nbr(fileinfo.st_size);
    my_putchar(' ');
    l_format_time(fileinfo);
    my_putstr(entry->d_name);
    my_putchar('\n');
    *checked_flag = 1;

}
