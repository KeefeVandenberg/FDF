# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvandenb <kvandenb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/04 14:08:37 by kvandenb          #+#    #+#              #
#    Updated: 2017/12/19 16:54:41 by kvandenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libx_flags = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

cflags = -Wall -Wextra -Werror

make_libft = @make -C ./GNl/libft/

header = fdf.h

includes = ./GNL/libft/libft.a ./GNL/get_next_line.c

SRC = main.c init.c utils.c draw_loop.c generate.c utils_2.c

OBJ = *.o

cc = @gcc

name = fdf

all : $(name)

$(name) :
	@make -C GNL/libft/
	$(cc) $(libx_flags) -g $(SRC) $(includes) -o $(name)
	@echo "Created FDF executable"
clean:
	@make -C GNL/libft/ clean
	@/bin/rm -f $(name)
fclean: clean
	@make -C GNL/libft/ fclean
re: fclean all