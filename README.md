# my_ls-Patricia-Petschen-Project2021-2022
Unix System Programming Project in C


For this project we were asked to code a command that copies the ls command, with some function restrictions.


AUTHORIZED FUNCTIONS

The only system calls allowed are the folowing ones:

• opendir, readir, closedir, stat, lstat, write

• getpwuid, getgrgid, time, ctime, readlink,

• malloc, free, perror, strerror, exit.



Passed 60% of the basic tests.

Passed 50% of the '-t' option tests.

Compilation via Makefile
(~$ make)

Execute by: 
            
            ~$ ./my_ls (you can add the path to any file)
 
            ~$ ./my_ls -t (you must add the path to any file)

(for the option '-t' it is necesary to at least add a '.' as path to the file you are currently in)
