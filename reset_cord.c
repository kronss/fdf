/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_cord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 12:53:02 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/12 12:53:03 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		color_change(t_block *b, char a)
{
	int		y;
	int		x;

	mlx_destroy_image(b->mlx, b->img);
	mlx_clear_window(b->mlx, b->win);
	create_img(b);
	y = 0;
	while (y < b->y_max)
	{
		x = 0;
		while (x < b->x_max)
		{
			a == 1 ? ((*b).cord[y][x]).color = 16777215 : 0;
			a == 2 ? ((*b).cord[y][x]).color = ((*b).cord[y][x]).color_res : 0;
			a == 3 ? ((*b).cord[y][x]).color += 255 : 0;
			a == 4 ? ((*b).cord[y][x]).color -= 255 : 0;
			a == 5 ? ((*b).cord[y][x]).color = (*b).color_param : 0;
			x++;
		}
		y++;
	}
	print_map(b);
}

void		zoom(t_block *b, double zoom)
{
	int		y;
	int		x;

	mlx_destroy_image(b->mlx, b->img);
	mlx_clear_window(b->mlx, b->win);
	create_img(b);
	y = 0;
	while (y < b->y_max)
	{
		x = 0;
		while (x < b->x_max)
		{
			((*b).cord[y][x]).y = ((*b).cord[y][x]).y * zoom;
			((*b).cord[y][x]).x = ((*b).cord[y][x]).x * zoom;
			((*b).cord[y][x]).z = ((*b).cord[y][x]).z * zoom;
			x++;
		}
		y++;
	}
	print_map(b);
}

void		reset_cord(t_block *b)
{
	int		y;
	int		x;

	mlx_destroy_image(b->mlx, b->img);
	mlx_clear_window(b->mlx, b->win);
	create_img(b);
	y = 0;
	while (y < b->y_max)
	{
		x = 0;
		while (x < b->x_max)
		{
			((*b).cord[y][x]).y = ((*b).cord[y][x]).y_res;
			((*b).cord[y][x]).x = ((*b).cord[y][x]).x_res;
			((*b).cord[y][x]).z = ((*b).cord[y][x]).z_res;
			((*b).cord[y][x]).color = ((*b).cord[y][x]).color_res;
			x++;
		}
		y++;
	}
	print_map(b);
}
