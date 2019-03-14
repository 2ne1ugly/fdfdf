# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 15:18:59 by mchi              #+#    #+#              #
#    Updated: 2019/03/04 13:12:47 by mchi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc

SRCDIR=./src/

SRC=fdf.c init.c loop.c key.c matrix.c vector.c draw_prim.c world_view_proj.c \
mouse.c vector2.c get_next_line.c read_file.c img.c

SRCALL=$(addprefix $(SRCDIR), $(SRC))

LIB=-lmlx -lm -lft -L./libft -L./minilibx_macos -framework OpenGL -framework AppKit
INC=-Iinclude -Ilibft -Iminilibx_macos
FLAG=-g -Wall -Werror -Wextra -O3

LIBFT=./libft/libft.a

MINILIBX=./minilibx_macos/libmlx.a
 
OBJ=fdf.o init.o loop.o key.o matrix.o vector.o draw_prim.o world_view_proj.o mouse.o \
vector2.o get_next_line.o read_file.o img.o

NAME=fdf

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX)
	$(CC) $(FLAG) -c $(INC) $(SRCALL)
	$(CC) $(FLAG) $(LIB) $(INC) $(OBJ) -o $(NAME)

$(LIBFT):
	make -C libft

$(MINILIBX):
	make -C minilibx_macos

clean:
	make -C libft clean
	make -C minilibx_macos clean
	rm -rf $(OBJ)

fclean: clean
	rm -f $(MINILIBX)
	rm -f $(LIBFT)
	rm -f $(NAME)

re:
	make fclean
	make all