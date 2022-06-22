/*
** EPITECH PROJECT, 2021
** first flag
** File description:
** -l
*/

#include "my_ls.h"

void total_block(char *str)
{
	DIR *dir = opendir(str);
	struct stat stats;
	struct dirent *entry;
	int tot = 0;
	char *cat;

	while ((entry = readdir(dir))) {
		cat = my_strcat(my_strcat(str, "/"), entry->d_name);
		if ((lstat(cat, &stats)) == 0)
			(entry->d_name[0] != '.') ? tot += stats.st_blocks : 0;
	}
	closedir(dir);
    my_putstr("total ");
	my_put_nbr(tot / 2);
    my_putstr("\n");
}

void info_l_prints(char *res, struct dirent *entry)
{
    my_putstr(res);
    struct stat stats;
    stat(entry->d_name, &stats);
    char *time = ctime(&stats.st_mtime);
        int i = 4;
    my_putstr(". ");
    my_put_nbr(stats.st_nlink);
    my_putstr(" ");
    my_putstr(getpwuid(stats.st_uid)->pw_name);
    my_putstr(" ");
    my_putstr(getgrgid(stats.st_gid)->gr_name);
    my_putstr(" ");
    my_put_nbr(stats.st_size);
    my_putchar('\t');
    while (i != 16) {
        my_putchar(time[i]);
        i++;
    }
    my_putstr("  ");
    info(entry);
}

// stats.st_nlink primer numero
    //(for doubts check man 7 inode)   this     IF true false

void info_l(struct dirent *entry)
{
    if (entry != 0 && entry->d_name[0] != '.') {
        struct stat stats;
        stat(entry->d_name, &stats);
        char *res = malloc(sizeof(char)*11);
        res[0] = (stats.st_mode & S_IFDIR) ? 'd' : '-';
        res[1] = (stats.st_mode & S_IRUSR) ? 'r' : '-';
        res[2] = (stats.st_mode & S_IWUSR) ? 'w' : '-';
        res[3] = (stats.st_mode & S_IXUSR) ? 'x' : '-';
        res[4] = (stats.st_mode & S_IRGRP) ? 'r' : '-';
        res[5] = (stats.st_mode & S_IWGRP) ? 'w' : '-';
        res[6] = (stats.st_mode & S_IXGRP) ? 'x' : '-';
        res[7] = (stats.st_mode & S_IROTH) ? 'r' : '-';
        res[8] = (stats.st_mode & S_IWOTH) ? 'w' : '-';
        res[9] = (stats.st_mode & S_IXOTH) ? 'x' : '-';

        info_l_prints(res, entry);
        free(res);
    }
}

void flag_one(char *str)
{
    DIR *dir;
    struct dirent *entry;
    
    total_block(str);
    dir = opendir(str);
    entry = readdir(dir);
    while (entry != 0) {
        info_l(entry);
        if (entry != 0 && entry->d_name[0] != '.') 
            my_putstr("\n");
        entry = readdir(dir);
    }
    closedir(dir);
    free(entry);
}