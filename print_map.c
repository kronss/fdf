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

int 		key_hook(int key_code, t_block *block)
{
	printf("key code is: [%d]\n", key_code);
	key_code == 53 ? exit(0) : 0;
	mlx_destroy_image(block->mlx, block->img);
	mlx_clear_window(block->mlx, block->win);
	create_img(block);
	key_code == 91 ? turn_arround_x(block, -M_PI / 12) : 0;
	key_code == 84 ? turn_arround_x(block, M_PI / 12) : 0;
	key_code == 86 ? turn_arround_y(block, M_PI / 12) : 0;
	key_code == 88 ? turn_arround_y(block, -M_PI / 12) : 0;
	key_code == 89 ? turn_arround_z(block, M_PI / 12) : 0;
	key_code == 92 ? turn_arround_z(block, -M_PI / 12) : 0;
	key_code == 87 ? reset_cord(block) : 0;
	print_map(block);
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

int         ft_max(int a, int b)
{
    return ((a > b) ? (a) : (b));
}



void            dda_line_x(t_block *block, int y, int x)
{
    int        i, L, x_start, y_start, x_end, y_end;
    double    dX, dY, x_ar[1000], y_ar[1000];
    int j;

    // printf("--y: %f\n", ((block->cord)[y][x]).y);
    // printf("--x: %f\n", ((block->cord)[y][x]).x);
    static int pp = 0;

    x_start = roundf(((block->cord)[y][x]).x);     //x1);
    y_start = roundf(((block->cord)[y][x]).y);     //y1);
    x_end = roundf(((block->cord)[y][x + 1]).x);   //x2);
    y_end = roundf(((block->cord)[y][x + 1]).y);   //y2);
    // printf("cord %i :\n", pp);
    pp++;
    // printf("y: %d\n", y_end - y_start);
    // printf("x: %d\n", x_end - x_start);
    L = ft_max(ABS(x_end - x_start), ABS(y_end - y_start));
    // printf("L == %d\n======\n", L);
    dX = (((block->cord)[y][x + 1]).x - ((block->cord)[y][x]).x) / L;
    dY = (((block->cord)[y][x + 1]).y - ((block->cord)[y][x]).y) / L;
    i = 0;
    x_ar[i] = ((block->cord)[y][x]).x;
    y_ar[i] = ((block->cord)[y][x]).y;
    i++;
    while (i < L)
    {
        x_ar[i] = x_ar[i - 1] + dX;
        y_ar[i] = y_ar[i - 1] + dY;
        i++;
    }
    x_ar[i] = ((block->cord)[y][x + 1]).x;
    y_ar[i] = ((block->cord)[y][x + 1]).y;

    /* Output: -----------------------*/
    i = 0;

    // void		draw(t_block *block, int *x_ar, int *y_ar, int L)
    {
    	int i;

    	i = 0;
    	while (i <= L)
    	{
        j = ((roundf(x_ar[i] + 500)) * 4) + (roundf((y_ar[i] + 500)) * block->size_line);
	block->ptr[j] = 255U; // blue
        block->ptr[j + 1] = 255U; // green
        block->ptr[j + 2] = 255U; // red
        // mlx_pixel_put(block->mlx, block->win, roundf(x_ar[i]), roundf(y_ar[i]), 0xffffff);
        i++;
        // y++;
   		}

    }

    while (i <= L)  // add limmit
    {
        j = ((roundf(x_ar[i] + 500)) * 4) + (roundf((y_ar[i] + 500)) * block->size_line);
        block->ptr[j] = (block->cord)[y][x].color % 256; // blue
        block->ptr[j + 1] = ((block->cord)[y][x].color / 256) % 256; // green
        block->ptr[j + 2] = ((block->cord)[y][x].color / 256 / 256) % 256; // red
        // block->ptr[j + 3] = (block->cord)[y][x].color / 256 / 256 / 256; // transparansy
        i++;
        // y++;
    }
    /* -------------------------------*/
}

void dda_line_y(t_block *block, int y, int x)
{
    int        i, L, x_start, y_start, x_end, y_end;
    double    dX, dY, x_ar[1000], y_ar[1000];
    // printf("--y: %f\n", ((block->cord)[y][x]).y);
    // printf("--x: %f\n", ((block->cord)[y][x]).x);
    static int pp = 0;
    int j;


    x_start = roundf(((block->cord)[y][x]).x);     //x1);
    y_start = roundf(((block->cord)[y][x]).y);     //y1);
    x_end = roundf(((block->cord)[y + 1][x]).x);   //x2);
    y_end = roundf(((block->cord)[y + 1][x]).y);   //y2);
    // printf("cord %i :\n", pp);
    pp++;
    // printf("y: %d\n", y_end - y_start);
    // printf("x: %d\n", x_end - x_start);
    L = ft_max(ABS(x_end - x_start), ABS(y_end - y_start));
    // printf("L == %d\n======\n", L);
    dX = (((block->cord)[y + 1][x]).x - ((block->cord)[y][x]).x) / L;
    dY = (((block->cord)[y + 1][x]).y - ((block->cord)[y][x]).y) / L;
    i = 0;
    x_ar[i] = ((block->cord)[y][x]).x;
    y_ar[i] = ((block->cord)[y][x]).y;
    i++;
    while (i < L)
    {
        x_ar[i] = x_ar[i - 1] + dX;
        y_ar[i] = y_ar[i - 1] + dY;
        i++;
    }
    x_ar[i] = ((block->cord)[y + 1][x]).x;
    y_ar[i] = ((block->cord)[y + 1][x]).y;

    /* Output: -----------------------*/
    i = 0;
    while (i <= L)
    {
        j = ((roundf(x_ar[i]) + 500) * 4) + ((roundf(y_ar[i] + 500)) * block->size_line);
        block->ptr[j] = (block->cord)[y][x].color % 256; // blue
        block->ptr[j + 1] = ((block->cord)[y][x].color / 256) % 256; // green
        block->ptr[j + 2] = ((block->cord)[y][x].color / 256 / 256) % 256; // red
        // block->ptr[j + 3] = (block->cord)[y][x].color / 256 / 256 / 256; // transparansy
        i++;
    }
    /* -------------------------------*/
}

void				print_map(t_block *block)
{
	int x;
	int y = 0;

	// turn_arround_x(block, -M_PI / 5);
	// turn_arround_y(block, -M_PI / 5);
	// turn_arround_z(block, M_PI / 5);
	while (y < (block->y_max))
	{
		x = 0 ;
		while (x < (block->x_max) && (x + 1) < (block->x_max))
		{
			dda_line_x(block, y , x);
			x++;
		}
		x = 0;
		while (x < (block->x_max) && (y + 1) < (block->y_max))
		{
			dda_line_y(block, y , x);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(block->mlx, block->win, block->img, 0, 0);
	mlx_key_hook(block->win, key_hook , block);


	// mlx_mouse_hook(block->win, mouse_hook, 0);
	// mlx_expose_hook(block->win, expose_hook, 0);
	// mlx_loop_hook(block->win, loop_hook, 0);
	mlx_loop(block->mlx);
}





