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

void			create_img(t_block *block)
{
	block->img = mlx_new_image(block->mlx, 1000, 1000);
	block->ptr = mlx_get_data_addr(block->img, &block->bits_per_pixel, &block->size_line, &block->endian);
}

void			create_map(t_block *block)
{
	block->mlx = mlx_init();
	block->win = mlx_new_window(block->mlx , 1000, 1000, "fdf"); // x , y
	create_img(block);
}
