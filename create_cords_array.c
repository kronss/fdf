/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cords_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:44:48 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/06 17:44:49 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			create_cords(int x, int y, char **buf, t_block *block)
{
	((*block).cord[y][x]).y = (double)((y * 10) - ((*block).y_max * 10) / 2);
	((*block).cord[y][x]).x = (double)((x * 10) - ((*block).x_max * 10) / 2);
	((*block).cord[y][x]).z = (double)ft_atoi_shift_pointer(buf) * 10;
	if (**buf == ',')
	{
		(*buf)++;
		((*block).cord[y][x]).color = ft_atohex_shift_pointer(buf);
	}
	else
		((*block).cord[y][x]).color = 16777215;
	((*block).cord[y][x]).y_res = ((*block).cord[y][x]).y;
	((*block).cord[y][x]).x_res = ((*block).cord[y][x]).x;
	((*block).cord[y][x]).z_res = ((*block).cord[y][x]).z;
	((*block).cord[y][x]).color_res = ((*block).cord[y][x]).color;
}


void				create_cords_array(t_block *block, int y, int x, char *buf)
{
	// int i =0;
	// printf("[%d]\n", cord);
	
	if (!((*block).cord = malloc(sizeof(t_fdf_cord *) * ((*block).y_max))))
		fdf_error("error");
	while (y < block->y_max)
	{
		x = 0;
		if (!(((*block).cord)[y] = malloc(sizeof(t_fdf_cord) * ((*block).x_max))))
			fdf_error("error");
		while (x < block->x_max)
		{
			if (*buf != ' ' && *buf != '\n' && *buf != '\0')
			{
				// ((*block).cord)[y][x] = 
				// printf("========%d\n", i ++);
				create_cords(x, y, &buf, block);
				// printf("========%d\n", i);
				// 	printf("in y %.1f\n", ((*block).cord[y][x]).y);
				// 	printf("in x %.1f\n", ((*block).cord[y][x]).x);
				// 	printf("in z %.1f\n", ((*block).cord[y][x]).z);
				// 	printf("in col %d\n", ((*block).cord[y][x]).color);
				x++;
			}	
			buf++;
		}
		// (*cord)[y][x] = NULL;
		y++;
	}
	// (*cord)[y] = NULL;
	// printf("2[%p]\n", cord);
	// printf("2[%p]\n", *cord);
	// printf("2[%p]\n", **cord);
	// printf("2[%p]\n", ***cord);
	// correct_center_cord(cord, x , y);
}