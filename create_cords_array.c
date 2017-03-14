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

static void			create_cords(int x, int y, char **buf, t_block *b)
{
	((*b).cord[y][x]).y = (double)((y * b->zoom) - ((*b).y_max * b->zoom) / 2);
	((*b).cord[y][x]).x = (double)((x * b->zoom) - ((*b).x_max * b->zoom) / 2);
	((*b).cord[y][x]).z = (double)ft_atoi_shift_pointer(buf) * b->zoom;
	if (**buf == ',')
	{
		(*buf)++;
		((*b).cord[y][x]).color = ft_atohex_shift_pointer(buf);
	}
	else
		((*b).cord[y][x]).color = 16777215;
	((*b).cord[y][x]).y_res = ((*b).cord[y][x]).y;
	((*b).cord[y][x]).x_res = ((*b).cord[y][x]).x;
	((*b).cord[y][x]).z_res = ((*b).cord[y][x]).z;
	((*b).cord[y][x]).color_res = ((*b).cord[y][x]).color;
}

void				create_cords_array(t_block *b, int y, int x, char *buf)
{
	if (!((*b).cord = malloc(sizeof(t_fdf_cord *) * ((*b).y_max))))
		fdf_error("error");
	while (y < b->y_max)
	{
		x = 0;
		if (!(((*b).cord)[y] = malloc(sizeof(t_fdf_cord) * ((*b).x_max))))
			fdf_error("error");
		while (x < b->x_max)
		{
			if (*buf != ' ' && *buf != '\n' && *buf != '\0')
			{
				create_cords(x, y, &buf, b);
				x++;
			}
			buf++;
		}
		y++;
	}
}
