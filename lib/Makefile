##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Maks the file for the lib
##

SRC		=	my_putchar.c	\
			my_putstr.c		\
			my_strlen.c		\
			my_put_nbr.c	\
			my_strcat.c

OBJ 	=	$(SRC:.c=.o)

NAME 	= 	libmy.a

all: 	$(NAME)

$(NAME) : 	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: 	fclean all

