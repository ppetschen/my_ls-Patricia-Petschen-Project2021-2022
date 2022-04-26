##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## It creates the executable version
##

NAME	=	my_ls

SRC		=	src/main.c				\
			src/my_ls.c				\
			src/initialize_struct.c	\
			src/flag_l.c			\
			src/flags.c

LIB_DIR	=	lib

LIB		=	-L./lib -lmy

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			cd $(LIB_DIR) ; $(MAKE) -f Makefile
			gcc -o $(NAME) $(OBJ) $(LIB)

clean:
			rm -f $(OBJ)
			cd $(LIB_DIR) ; $(MAKE) -f Makefile clean

fclean:		clean
			rm -f $(NAME)
			cd $(LIB_DIR) ; $(MAKE) -f Makefile fclean

re:			fclean all
			cd $(LIB_DIR) ; $(MAKE) -f Makefile re