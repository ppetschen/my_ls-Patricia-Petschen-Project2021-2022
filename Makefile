##
## EPITECH PROJECT, 2021
## makefile
## File description:
## my_ls
##

MAIN	=	my_ls.c	\
			include/my_putstr.c	\
			include/my_putchar.c	\
			include/my_put_nbr.c	\
			include/my_strcat.c	\
			include/my_strlen.c	\
			include/info.c	\
			include/no_flag.c	\
			include/flag_one.c	\

NAME	=	my_ls

all:
	gcc -W -Wall -Werror -Wextra $(MAIN) -o $(NAME)

clean:
	rm *~

fclean:
	rm -f $(NAME)

re: fclean all