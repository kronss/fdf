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

/*
**	b->ptr[j + 0] = (b->cord)[y][x].color % 256; // blue
**	b->ptr[j + 1] = ((b->cord)[y][x].color / 256) % 256; // green
**	b->ptr[j + 2] = ((b->cord)[y][x].color / 256 / 256) % 256; // red
**	b->ptr[j + 3] = (b->cord)[y][x].color / 256 / 256 / 256; // transparansy
*/

#include "fdf.h"

static int			key_hook(int key_code, t_block *b)
{
	key_code == 53 ? exit(0) : 0;
	key_code == 91 ? turn_arround_x(b, -M_PI / 36) : 0;
	key_code == 87 ? turn_arround_x(b, M_PI / 36) : 0;
	key_code == 86 ? turn_arround_y(b, M_PI / 36) : 0;
	key_code == 88 ? turn_arround_y(b, -M_PI / 36) : 0;
	key_code == 89 ? turn_arround_z(b, M_PI / 36) : 0;
	key_code == 92 ? turn_arround_z(b, -M_PI / 36) : 0;
	key_code == 82 ? reset_cord(b) : 0;
	key_code == 69 ? zoom(b, 1.1) : 0;
	key_code == 78 ? zoom(b, 0.9) : 0;
	key_code == 126 ? move_along_y(b, 20) : 0;
	key_code == 125 ? move_along_y(b, -20) : 0;
	key_code == 123 ? move_along_x(b, 20) : 0;
	key_code == 124 ? move_along_x(b, -20) : 0;
	key_code == 18 ? color_change(b, 1) : 0;
	key_code == 19 ? color_change(b, 2) : 0;
	key_code == 116 ? color_change(b, 3) : 0;
	key_code == 121 ? color_change(b, 4) : 0;
	key_code == 20 ? color_change(b, 5) : 0;
	return (0);
}

static void			draw(t_block *b, int y, int x, int l)
{
	int		i;
	int		j;
	int		x_limit;
	int		y_limit;

	i = 0;
	while (i <= l)
	{
		x_limit = (roundf((b->x_ar)[i] + 500)) * 4;
		y_limit = (roundf(((b->y_ar)[i] + 500)) * 4000);
		j = x_limit + y_limit;
		if (0 <= j && j < 3999997 && 0 <= x_limit && x_limit < 3997)
		{
			b->ptr[j] = (b->cord)[y][x].color % 256;
			b->ptr[j + 1] = ((b->cord)[y][x].color / 256) % 256;
			b->ptr[j + 2] = ((b->cord)[y][x].color / 256 / 256) % 256;
		}
		i++;
	}
}

static void			dda_line_x(t_block *b, int y, int x)
{
	int		i;
	int		l;
	double	dx;
	double	dy;

	l =
	ft_max(ABS(roundf(((b->cord)[y][x + 1]).x) - roundf(((b->cord)[y][x]).x)),
	ABS(roundf(((b->cord)[y][x + 1]).y) - roundf(((b->cord)[y][x]).y)));
	l = l > 1190 ? 1190 : l;
	dx = (((b->cord)[y][x + 1]).x - ((b->cord)[y][x]).x) / l;
	dy = (((b->cord)[y][x + 1]).y - ((b->cord)[y][x]).y) / l;
	i = 0;
	(b->x_ar)[i] = ((b->cord)[y][x]).x;
	(b->y_ar)[i] = ((b->cord)[y][x]).y;
	i++;
	while (i < l)
	{
		(b->x_ar)[i] = (b->x_ar)[i - 1] + dx;
		(b->y_ar)[i] = (b->y_ar)[i - 1] + dy;
		i++;
	}
	(b->x_ar)[i] = ((b->cord)[y][x + 1]).x;
	(b->y_ar)[i] = ((b->cord)[y][x + 1]).y;
	draw(b, y, x, l);
}

static void			dda_line_y(t_block *b, int y, int x)
{
	int		i;
	int		l;
	double	dx;
	double	dy;

	l =
	ft_max(ABS(roundf(((b->cord)[y + 1][x]).x) - roundf(((b->cord)[y][x]).x)),
	ABS(roundf(((b->cord)[y + 1][x]).y) - roundf(((b->cord)[y][x]).y)));
	l = l > 1190 ? 1190 : l;
	dx = (((b->cord)[y + 1][x]).x - ((b->cord)[y][x]).x) / l;
	dy = (((b->cord)[y + 1][x]).y - ((b->cord)[y][x]).y) / l;
	i = 0;
	(b->x_ar)[i] = ((b->cord)[y][x]).x;
	(b->y_ar)[i] = ((b->cord)[y][x]).y;
	i++;
	while (i < l)
	{
		(b->x_ar)[i] = (b->x_ar)[i - 1] + dx;
		(b->y_ar)[i] = (b->y_ar)[i - 1] + dy;
		i++;
	}
	(b->x_ar)[i] = ((b->cord)[y + 1][x]).x;
	(b->y_ar)[i] = ((b->cord)[y + 1][x]).y;
	draw(b, y, x, l);
}

void				print_map(t_block *b)
{
	int x;
	int y;

	y = 0;
	while (y < (b->y_max))
	{
		x = 0;
		while (x < (b->x_max) && (x + 1) < (b->x_max))
		{
			dda_line_x(b, y, x);
			x++;
		}
		x = 0;
		while (x < (b->x_max) && (y + 1) < (b->y_max))
		{
			dda_line_y(b, y, x);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(b->mlx, b->win, b->img, 0, 0);
	mlx_hook(b->win, 2, 5, key_hook, b);
}
