# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvandenb <kvandenb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/04 14:08:37 by kvandenb          #+#    #+#              #
#    Updated: 2017/12/06 16:48:40 by kvandenb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libx_flags = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

cflags = -Wall -Wextra -Werror

make_libft = @make -C ./GNl/libft/

header = fdf.h

includes = ./GNL/libft/libft.a ./GNL/get_next_line.c

SRC = main.c init_plc.c

OBJ = *.o

cc = @gcc

name = fdf

all : $(name)

$(name) :
	@printf '\033[32m[ 🤖 ] %s\n\033[0m' "Making FdF"
	@make -C GNL/libft/
	$(cc) $(libx_flags) -g $(SRC) $(includes) -o $(name)
	@printf '\033[32m[ 🧐 ] %s\n\033[0m' "Create FdF"
clean:
	@make -C GNL/libft/ clean
	@/bin/rm -f $(name)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean Lib"
fclean: clean
	@make -C GNL/libft/ fclean
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean Lib all"
re: fclean all