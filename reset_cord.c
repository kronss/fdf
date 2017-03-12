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

void		zoom(t_block *block, double zoom)
{
	int y;
	int x;
	printf("------%d\n", block->y_max);

	mlx_destroy_image(block->mlx, block->img);
	mlx_clear_window(block->mlx, block->win);
	create_img(block);
	// zoom > 0.0 ? (*z)++ : (*z)--;
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
	// printf("y %f\n", ((*block).cord[block->y_max - 1][block->x_max - 1]).y);
	// printf("x %f\n", ((*block).cord[block->y_max - 1][block->x_max - 1]).x);
	// printf("z %f\n", ((*block).cord[block->y_max - 1][block->x_max - 1]).z);
}

void		reset_cord(t_block *block)
{
	int y;
	int x;


	mlx_destroy_image(block->mlx, block->img);
	mlx_clear_window(block->mlx, block->win);
	create_img(block);

	// printf("do res y %f\n", ((*block).cord[block->y_max - 1][block->x_max - 1]).y);
	// printf("do res x %f\n", ((*block).cord[block->y_max - 1][block->x_max - 1]).x);
	// printf("do res z %f\n", ((*block).cord[block->y_max - 1][block->x_max - 1]).z);

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
	// printf("posle res y %f\n", ((*block).cord[block->y_max - 1][block->x_max - 1]).y);
	// printf("posle res x %f\n", ((*block).cord[block->y_max - 1][block->x_max - 1]).x);
	// printf("posle res z %f\n", ((*block).cord[block->y_max - 1][block->x_max - 1]).z);

}
