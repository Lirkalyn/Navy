##
## EPITECH PROJECT, 2019
## Day_10
## File description:
## makefile
##
.PHONY : clean fclean re

SRC	=	my_printf.c \
		replace_d.c \
		replace_c.c \
		replace_s.c \
		display.c \
		replace_p.c \
		replace_b.c \
		switchs.c \
		replace_o.c \
		replace_pour.c \
		replace_u.c \
		replace_x.c \
		replace_xx.c \
		replace_n.c \
		replace_p_d.c \
		replace_h_o.c \
		replace_h_x.c \
		replace_h_xx.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

$(NAME):	$(OBJ)
		gcc -c $(SRC)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../
		cp printf.h ../../include

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)
		rm -f ../$(NAME)

re:	fclean $(NAME)
