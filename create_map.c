/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 11:19:33 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/12 11:19:34 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			create_img(t_block *b)
{
	b->img = mlx_new_image(b->mlx, 1000, 1000);
	b->ptr = mlx_get_data_addr(b->img, &b->bits_per_pixel,
	&b->size_line, &b->endian);
}

void			create_map(t_block *b)
{
	b->mlx = mlx_init();
	b->win = mlx_new_window(b->mlx, 1000, 1000, "fdf");
	create_img(b);
}
