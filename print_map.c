/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:52:13 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/06 17:52:14 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 		key_hook(int key_code, t_block *block)
{
	printf("key code is: [%d]\n", key_code);
	key_code == 53 ? exit(0) : 0;
	key_code == 91 ? turn_arround_x(block, -M_PI / 36) : 0;
	key_code == 87 ? turn_arround_x(block, M_PI / 36) : 0;
	key_code == 86 ? turn_arround_y(block, M_PI / 36) : 0;
	key_code == 88 ? turn_arround_y(block, -M_PI / 36) : 0;
	key_code == 89 ? turn_arround_z(block, M_PI / 36) : 0;
	key_code == 92 ? turn_arround_z(block, -M_PI / 36) : 0;
	key_code == 82 ? reset_cord(block) : 0;
	key_code == 69 ? zoom(block, 1.1) : 0;
	key_code == 78 ? zoom(block, 0.9) : 0;
	key_code == 126 ? move_along_y(block, 20) : 0;
	key_code == 125 ? move_along_y(block, -20) : 0;
	key_code == 123 ? move_along_x(block, 20) : 0;
	key_code == 124 ? move_along_x(block, -20) : 0;
	key_code == 18 ? color_change(block, 1) : 0;
	key_code == 19 ? color_change(block, 2) : 0;
	key_code == 20 ? color_change(block, 3) : 0;
	key_code == 21 ? color_change(block, 4) : 0;
	key_code == 23 ? color_change(block, 5) : 0;
	return (0);
}

void		draw(t_block *block, int y, int x, int L)
{
	int i;
	int j;
	int x_limit;
	int y_limit;

	i = 0;
	while (i <= L)
	{
		x_limit = (roundf((block->x_ar)[i] + 500)) * 4;
		y_limit = (roundf(((block->y_ar)[i] + 500)) * 4000);
		j = x_limit + y_limit;
		if (0 <= j && j < 3999997 && 0 <= x_limit && x_limit < 3997)
		{
			block->ptr[j] = (block->cord)[y][x].color % 256; // blue
			block->ptr[j + 1] = ((block->cord)[y][x].color / 256) % 256; // green
			block->ptr[j + 2] = ((block->cord)[y][x].color / 256 / 256) % 256; // red
			// block->ptr[j + 3] = (block->cord)[y][x].color / 256 / 256 / 256; // transparansy
		}
		i++;
	}
}

void            dda_line_x(t_block *block, int y, int x)
{
	int		i;
	int		L;
	double	dX;
	double	dY;
	
	L = ft_max(ABS(roundf(((block->cord)[y][x + 1]).x) - roundf(((block->cord)[y][x]).x)),
	ABS(roundf(((block->cord)[y][x + 1]).y) - roundf(((block->cord)[y][x]).y)));
	L = L > 1190 ? 1190 : L;
	dX = (((block->cord)[y][x + 1]).x - ((block->cord)[y][x]).x) / L;
	dY = (((block->cord)[y][x + 1]).y - ((block->cord)[y][x]).y) / L;
	i = 0;
	(block->x_ar)[i] = ((block->cord)[y][x]).x;
	(block->y_ar)[i] = ((block->cord)[y][x]).y;
	i++;
	while (i < L)
	{
		(block->x_ar)[i] = (block->x_ar)[i - 1] + dX;
		(block->y_ar)[i] = (block->y_ar)[i - 1] + dY;
		i++;
	}
	(block->x_ar)[i] = ((block->cord)[y][x + 1]).x;
	(block->y_ar)[i] = ((block->cord)[y][x + 1]).y;
	draw(block, y, x, L);
}

void dda_line_y(t_block *block, int y, int x)
{
	int		i;
	int		L;
	double	dX;
	double	dY;

	L = ft_max(ABS(roundf(((block->cord)[y + 1][x]).x) - roundf(((block->cord)[y][x]).x)),
	ABS(roundf(((block->cord)[y + 1][x]).y) - roundf(((block->cord)[y][x]).y)));
	L = L > 1190 ? 1190 : L; 
	dX = (((block->cord)[y + 1][x]).x - ((block->cord)[y][x]).x) / L;
	dY = (((block->cord)[y + 1][x]).y - ((block->cord)[y][x]).y) / L;
	i = 0;
	(block->x_ar)[i] = ((block->cord)[y][x]).x;
	(block->y_ar)[i] = ((block->cord)[y][x]).y;
	i++;
	while (i < L)
	{
		(block->x_ar)[i] = (block->x_ar)[i - 1] + dX;
		(block->y_ar)[i] = (block->y_ar)[i - 1] + dY;
		i++;
	}
	(block->x_ar)[i] = ((block->cord)[y + 1][x]).x;
	(block->y_ar)[i] = ((block->cord)[y + 1][x]).y;
	draw(block, y, x, L);
}

void				print_map(t_block *block)
{
	int x;
	int y = 0;

	while (y < (block->y_max))
	{
		x = 0 ;
		while (x < (block->x_max) && (x + 1) < (block->x_max))
		{
			dda_line_x(block, y , x);
			x++;
		}
		x = 0;
		while (x < (block->x_max) && (y + 1) < (block->y_max))
		{
			dda_line_y(block, y , x);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(block->mlx, block->win, block->img, 0, 0);
	mlx_hook(block->win, 2, 5, key_hook, block);
}
