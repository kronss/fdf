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

void		color_change(t_block *block, char a)
{
	int y;
	int x;

	mlx_destroy_image(block->mlx, block->img);
	mlx_clear_window(block->mlx, block->win);
	create_img(block);
	y = 0;
	while (y < block->y_max)
	{
		x = 0;
		while (x < block->x_max)
		{
			a == 1 ? ((*block).cord[y][x]).color = 16777215 : 0;
			a == 2 ? ((*block).cord[y][x]).color = ((*block).cord[y][x]).color_res : 0;
			a == 3 ? ((*block).cord[y][x]).color = 255 : 0;
			a == 4 ? ((*block).cord[y][x]).color = 65280 : 0;
			a == 5 ? ((*block).cord[y][x]).color = 16711680 : 0;
			x++;
		}
		y++;
	}
	print_map(block);
}

void		zoom(t_block *block, double zoom)
{
	int y;
	int x;
	// printf("------%d\n", block->y_max);

	mlx_destroy_image(block->mlx, block->img);
	mlx_clear_window(block->mlx, block->win);
	create_img(block);
	y = 0;
	while (y < block->y_max)
	{
		x = 0;
		while (x < block->x_max)
		{
			((*block).cord[y][x]).y = ((*block).cord[y][x]).y * zoom;
			((*block).cord[y][x]).x = ((*block).cord[y][x]).x * zoom;
			((*block).cord[y][x]).z = ((*block).cord[y][x]).z * zoom;
			x++;
		}
		y++;
	}
	print_map(block);
}

void		reset_cord(t_block *block)
{
	int y;
	int x;

	mlx_destroy_image(block->mlx, block->img);
	mlx_clear_window(block->mlx, block->win);
	create_img(block);
	y = 0;
	while (y < block->y_max)
	{
		x = 0;
		while (x < block->x_max)
		{
			((*block).cord[y][x]).y = ((*block).cord[y][x]).y_res;
			((*block).cord[y][x]).x = ((*block).cord[y][x]).x_res;
			((*block).cord[y][x]).z = ((*block).cord[y][x]).z_res;
			((*block).cord[y][x]).color = ((*block).cord[y][x]).color_res;
			x++;
		}
		y++;
	}
	print_map(block);
}
