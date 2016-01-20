##
## Makefile for Makefile in /home/juliena/rendu/MUL_2013_wolf3d
## 
## Made by athomasjulien
## Login   <juliena@epitech.net>
## 
## Started on  Thu Dec 19 12:58:53 2013 athomasjulien
## Last update Sun Mar 16 22:31:53 2014 athomasjulien
##

SRC=		my_pixel_put_to_image.c	\
		rtv1.c			\
		my_calc.c		\
		my_object.c		\
		my_values.c		\
		my_lower_k.c		\
		calc_light.c		\
		calc_shadows.c		\
		my_free_func.c		\
		my_putstr.c

OBJ=		$(SRC:.c=.o)

CFLAGS=		-W -Wall -Werror -Wextra -I./minilibx

NAME=		rtv1


all:		$(NAME)

$(NAME):	$(OBJ)
		gcc $(OBJ) -L/usr/lib64 -L./minilibx -lmlx -L/usr/lib64/X11 -lXext -lX11 -lm -o $(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
