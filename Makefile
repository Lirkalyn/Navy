##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

.PHONY	:	$(NAME) clean fclean re

NAME	=	navy

SRC		=	main.c \
			scr/display.c \
			scr/display2.c \
			scr/cmp.c \
			scr/checker.c \
			scr/map_maker.c \
			scr/boat_maker.c \
			scr/connection.c \
			scr/connection2.c \
			scr/act.c \
			scr/end.c

OBJ		=	$(SRC:.c=.o)

$(NAME)	:	$(OBJ)
			make -C lib/my
			gcc $(OBJ) -o $(NAME) -Wall -Wextra -L./lib/ -lmy

clean	:
			rm -f $(OBJ)
			make clean -C lib/my

fclean	:	clean
			rm -f $(NAME)
			make fclean -C lib/my

re		:	fclean $(NAME)
