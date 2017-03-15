#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochayche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 18:15:02 by ochayche          #+#    #+#              #
#    Updated: 2017/03/05 22:47:28 by ochayche         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

GCC = gcc

F = -Wall -Wextra -Werror
M = -lmlx -framework OpenGL -framework Appkit

NAME = fdf

OBJECT = ./fdf.o \
	./usage.o \
	./fdf_error.o \
	./create_cords_array.o \
	./print_map.o \
	./turn_arround_x.o \
	./create_map.o \
	./reset_cord.o

.PHONY: all clean fclean re bug debug

all: $(NAME)
	@make -C libft/
	@make -C ft_printf/

$(NAME): $(OBJECT)
		@make -C libft/
		@make -C ft_printf/
		$(GCC) $(F) $(M) -o $(NAME) $(OBJECT) -I minilibx_macos/libmlx.a libft/libft.a ft_printf/libftprintf.a

clean:
	@make clean -C libft/
	@make clean -C ft_printf/
	rm -rf $(OBJECT)

fclean: clean
	@make fclean -C libft/
	@make fclean -C ft_printf/
	rm -rf $(NAME)

re: fclean all

bug:
	gcc -g $(F) $(M) ./fdf.c ./usage.c ./fdf_error.c ./create_cords_array.c ./print_map.c ./turn_arround_x.c ./create_map.c ./reset_cord.c -I minilibx_macos/libmlx.a libft/libft.a ft_printf/libftprintf.a

debug: bug
	lldb -- a.out

%.o: ./%.c
	$(GCC) $(F) -o $@ -c $< -I ./
