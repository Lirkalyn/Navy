##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

#.PHONY : clean fclean re
.PHONY	:	$(NAME) clean fclean re

NAME	=	navy

SRC		=	main.c \
			scr/display.c \
			scr/display2.c \
			scr/cmp.c \
			scr/checker.c \
			scr/map_maker.c \

OBJ		=	$(SRC:.c=.o)

$(NAME)	:	$(OBJ)
			gcc $(OBJ) -o $(NAME) -Wall -Wextra

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean $(NAME)

#.PHONY	:	all $(NAME) clean fclean re
