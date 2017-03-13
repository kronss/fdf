/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_arround_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 11:03:54 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/12 11:03:55 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	all movent along any cord
*/


#include "fdf.h"


void		move_along_y(t_block *block, double shift)
{
	int y;
	int x;
	// printf("------%d\n", block->y_max);

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
			((*block).cord[y][x]).y = ((*block).cord[y][x]).y + shift;
			// ((*block).cord[y][x]).x = ((*block).cord[y][x]).x + shift;
			// ((*block).cord[y][x]).z = ((*block).cord[y][x]).z + shift;
			x++;
		}
		y++;
	}
	print_map(block);
	// printf("y %f\n", ((*block).cord[block->y_max - 1][block->x_max - 1]).y);
	// printf("x %f\n", ((*block).cord[block->y_max - 1][block->x_max - 1]).x);
}

void		move_along_x(t_block *block, double shift)
{
	int y;
	int x;
	// printf("------%d\n", block->y_max);

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
			// ((*block).cord[y][x]).y = ((*block).cord[y][x]).y + shift;
			((*block).cord[y][x]).x = ((*block).cord[y][x]).x + shift;
			// ((*block).cord[y][x]).z = ((*block).cord[y][x]).z + shift;
			x++;
		}
		y++;
	}
	print_map(block);
	// printf("y %f\n", ((*block).cord[block->y_max - 1][block->x_max - 1]).y);
	// printf("x %f\n", ((*block).cord[block->y_max - 1][block->x_max - 1]).x);
}


void		turn_arround_y(t_block *block, double angl)
{
	double	x_tmp;
	double	z_tmp;
	int		y;
	int		x;

	mlx_destroy_image(block->mlx, block->img);
	mlx_clear_window(block->mlx, block->win);
	create_img(block);
	y = 0;
	while (y < block->y_max)
	{
		x = 0;
		while (x < block->x_max)
		{
			x_tmp = ((block->cord)[y][x]).x;
			z_tmp = ((block->cord)[y][x]).z;
			((block->cord)[y][x]).x = x_tmp * cos(-angl) + z_tmp * sin(-angl);
			((block->cord)[y][x]).z = z_tmp * cos(-angl) - x_tmp * sin(-angl);
			x++;
		}
		y++;
	}
	print_map(block);
}

void		turn_arround_z(t_block *block, double angl)
{
	double	y_tmp;
	double	x_tmp;
	int		y;
	int		x;

	mlx_destroy_image(block->mlx, block->img);
	mlx_clear_window(block->mlx, block->win);
	create_img(block);	
	y = 0;
	while (y < block->y_max)
	{
		x = 0;
		while (x < block->x_max)
		{
			y_tmp = ((block->cord)[y][x]).y;
			x_tmp = ((block->cord)[y][x]).x;
			((block->cord)[y][x]).y = y_tmp * cos(angl) - x_tmp * sin(angl);
			((block->cord)[y][x]).x = x_tmp * cos(angl) + y_tmp * sin(angl);
			x++;
		}
		y++;
	}
	print_map(block);
}

void		turn_arround_x(t_block *block, double angl)
{
	double	y_tmp;
	double	z_tmp;
	int		y;
	int		x;


	
	mlx_destroy_image(block->mlx, block->img);
	mlx_clear_window(block->mlx, block->win);
	create_img(block);
	y = 0;
	while (y < block->y_max)
	{
		x = 0;
		while (x < block->x_max)
		{
			y_tmp = ((block->cord)[y][x]).y;
			z_tmp = ((block->cord)[y][x]).z;
			((block->cord)[y][x]).y = y_tmp * cos(angl) + z_tmp * sin(angl);
			((block->cord)[y][x]).z = z_tmp * cos(angl) - y_tmp * sin(angl);
			x++;
		}
		y++;
	}
	print_map(block);
}
