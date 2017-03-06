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

#include "fdf.h"

	int 		key_hook(int key_code, void *param)
{
	// printf("key code is: [%d]\n", key_code);
	if (key_code == 53)
		exit(0);
	return (0);
}

// int 		mouse_hook(int mouse_code, void *param)
// {
// 	printf("mose code is: [%d]\n", mouse_code);
// 	return (0);
// }

// int expose_hook(int expose_code, void *param)
// {
// 	printf("expose_hook is: [%d]\n", expose_code);
// 	return (0);
// }

// int loop_hook(int loop_code, void *param)⁄€‹
// {
// 	printf("loop_hook is: [%d]\n", loop_code);
// 	return (0);
// }
// double					get_double(char *line)
// {
// 	char *tmp;

// 	tmp = line;
// 	while (*tmp != '\0')
// 	{

// 	}
// }
void dda_line (float x1, float y1, float x2, float y2, void *mlx, void *win)
{
    int        i, L, xstart, ystart, xend, yend;
    float    dX, dY, x[1000], y[1000];

    xstart = roundf(x1);
    ystart = roundf(y1);
    xend = roundf(x2);
    yend = roundf(y2);
    L = ft_max(abs(xend-xstart), abs(yend-ystart));
    dX = (x2-x1) / L;
    dY = (y2-y1) / L;
    i = 0;
    x[i] = x1;
    y[i] = y1;
    i++;
    while (i < L)
    {
        x[i] = x[i-1] + dX;
        y[i] = y[i-1] + dY;
        i++;
    }
    x[i] = x2;
    y[i] = y2;

    /* Output: -----------------------*/
    i = 0;
    while (i <= L)
    {
        mlx_pixel_put (mlx, win, roundf(x[i]), roundf(y[i]), 0xffffff);
        i++;
    }
    /* -------------------------------*/
}

// void		dda_line (t_block *block)
// {
// 	dda_line (float x1, float y1, float x2, float y2)
	
// 	int i, L, xstart, ystart, xend, yend;
// 	float dX, dY, x[1000], y[1000];
// 	xstart = roundf(x1);
// 	ystart = roundf(y1);
// 	xend = roundf(x2);
// 	yend = roundf(y2);
// 	L = max(abs(xend-xstart), abs(yend-ystart));
// 	dX = (x2-x1) / L;
// 	dY = (y2-y1) / L;
// 	i = 0;
// 	x[i] = x1;
// 	y[i] = y1;
// 	i++;
// 	while (i < L)
// 	{
// 		x[i] = x[i-1] + dX;
// 		y[i] = y[i-1] + dY;
// 		i++;
//   }
//   x[i] = x2;
//   y[i] = y2;
  
//   /* Output: -----------------------*/
//   i = 0;
//   while (i <= L)
//   {
//     plot (roundf(x[i]), roundf(y[i])); /* Draws a point. */
//     i++;
//   }
//   /* -------------------------------*/
// }


void				print_map(t_block *block)
{
	block->mlx = mlx_init();
	block->win = mlx_new_window(block->mlx ,block->min_win_x, block->min_win_y, "fdf");
	
	(block->cord)[y][x]
	


	// mlx_string_put(block->mlx, block->win, 200, 200, 0xffddff, "hello!\n");


	mlx_key_hook(block->win, key_hook, 0);
	// mlx_mouse_hook(block->win, mouse_hook, 0);
	// mlx_expose_hook(block->win, expose_hook, 0);
	// mlx_loop_hook(block->win, loop_hook, 0);
	mlx_loop(block->mlx);

}