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

void		incrs_step(t_block *block)
{
	int y;
	int x;

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

}


void		reset_cord(t_block *block)
{
	int y;
	int x;

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

}
