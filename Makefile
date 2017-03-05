#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochayche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 18:15:02 by ochayche          #+#    #+#              #
#    Updated: 2017/01/18 18:15:03 by ochayche         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

GCC = gcc

# F = -Wall -Wextra -Werror

NAME = fdf

OBJECT = ./fdf.o \
	./usage.o \
	./fdf_error.o 

.PHONY: all clean fclean re

all: $(NAME)
	@make -C libft/
	@make -C ft_printf/

$(NAME): $(OBJECT)
		@make -C libft/
		@make -C ft_printf/
		$(GCC) $(F) -lmlx -framework OpenGL -framework Appkit -o $(NAME) $(OBJECT) -I minilibx_macos/libmlx.a libft/libft.a ft_printf/libftprintf.a


clean:
	@make clean -C libft/
	@make clean -C ft_printf/
	rm -rf $(OBJECT)

fclean: clean
	@make fclean -C libft/
	@make fclean -C ft_printf/
	rm -rf $(NAME)

re: fclean all

r: all
	./fdf test_1.fdf

bag:
	gcc -g ./fdf.c ./usage.c ./fdf_error.c  -I minilibx_macos/libmlx.a libft/libft.a ft_printf/libftprintf.a

debag: bag
	lldb -- a.out test_1.fdf

# fdf.o: fdf.c
# 	$(GCC) $(F) -c fdf.c

%.o: ./%.c
	$(GCC) $(F) -o $@ -c $< -I ./