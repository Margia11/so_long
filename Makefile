# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amargiac <amargiac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 13:00:21 by amargiac          #+#    #+#              #
#    Updated: 2023/03/01 12:59:12 by amargiac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
MLX_PATH	=	./minilibx
MLX	= $(MLX_PATH)/libmlx.a

SL_SRC	=	so_long.c\
			readmap.c \
			render.c \
 			map_checker.c \
			imgs_selector.c \
		 	close.c \
			movements.c \

HEADER = so_long.h

SL_OBJ	=	$(SL_SRC:.c=.o)

NAME	=	so_long

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -g

RM		=	rm -f

MLX		=	./libmlx.dylib

%.o: %.c
			$(CC) ${CFLAGS} -Imlx -c $< -o $@ 

all:		$(NAME)

$(NAME):	$(SL_OBJ) $(LIBFT)
			$(CC) $(CFLAGS) -o $(NAME) $(SL_OBJ) $(LIBFT)  $(MLX)

$(LIBFT):
		make -C $(LIBFT_PATH)

$(MLX):
		make -C $(MLX_PATH)

clean:
			make clean -C minilibx
			rm -f *.o
			rm -f ./*/*.o
			@echo "\033[33mSO_LONG>> Deleted \".o\" files\033[0m"

fclean:		clean
			rm -rf $(NAME)
			@echo "\033[33mSO_LONG>> Project cleaned\033[0m"

re:			fclean all
			@echo "\033[0;92mSO_LONG>> Project cleaned and recompiled\033[0m"

.PHONY:		all clean fclean re