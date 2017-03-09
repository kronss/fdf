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

int         ft_max(int a, int b)
{
    return ((a > b) ? (a) : (b));
}

// (double x1, double y1, double x2, double y2, void *mlx, void *win)
void dda_line_x(t_block *block, int y, int x)
{
    int        i, L, x_start, y_start, x_end, y_end;
    double    dX, dY, x_a[1000], y_a[1000];
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
    x_a[i] = ((block->cord)[y][x]).x;
    y_a[i] = ((block->cord)[y][x]).y;
    i++;
    while (i < L)
    {
        x_a[i] = x_a[i - 1] + dX;
        y_a[i] = y_a[i - 1] + dY;
        i++;
    }
    x_a[i] = ((block->cord)[y][x + 1]).x;
    y_a[i] = ((block->cord)[y][x + 1]).y;

    /* Output: -----------------------*/
    i = 0;
    while (i <= L && ((x + 1) < block->x_max))
    {
        mlx_pixel_put(block->mlx, block->win, 500 + roundf(x_a[i]), 500 + roundf(y_a[i]), 0xffffff);
        i++;
        // y++;
    }
    /* -------------------------------*/
}

void dda_line_y(t_block *block, int y, int x)
{
    int        i, L, x_start, y_start, x_end, y_end;
    double    dX, dY, x_a[1000], y_a[1000];
    // printf("--y: %f\n", ((block->cord)[y][x]).y);
    // printf("--x: %f\n", ((block->cord)[y][x]).x);
    static int pp = 0;

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
    x_a[i] = ((block->cord)[y][x]).x;
    y_a[i] = ((block->cord)[y][x]).y;
    i++;
    while (i < L)
    {
        x_a[i] = x_a[i - 1] + dX;
        y_a[i] = y_a[i - 1] + dY;
        i++;
    }
    x_a[i] = ((block->cord)[y + 1][x]).x;
    y_a[i] = ((block->cord)[y + 1][x]).y;

    /* Output: -----------------------*/
    i = 0;
    while (i <= L && ((y + 1) < block->y_max))
    {
        mlx_pixel_put(block->mlx, block->win, 500 + roundf(x_a[i]), 500 + roundf(y_a[i]), 0xffffff);
        i++;
        // y++;
    }
    /* -------------------------------*/
}

void dda_line_dick(t_block *block, int y, int x)
{
    int        i, L, x_start, y_start, x_end, y_end;
    double    dX, dY, x_a[1000], y_a[1000];
    // printf("--y: %f\n", ((block->cord)[y][x]).y);
    // printf("--x: %f\n", ((block->cord)[y][x]).x);
    // static int pp = 0;

    x_start = 0;     //x1);
    y_start = 0;     //y1);
    x_end = 500;   //x2);
    y_end = 500;   //y2);
    // printf("cord %i :\n", pp);
    // pp++;
    // printf("y: %d\n", y_end - y_start);
    // printf("x: %d\n", x_end - x_start);
    L = ft_max(ABS(x_end - x_start), ABS(y_end - y_start));
    // printf("L == %d\n======\n", L);
    dX = (x_end - x_start) / L;
    dY = (y_end - y_start) / L;
    i = 0;
    x_a[i] = x_start;
    y_a[i] = y_start;
    i++;
    while (i < L)
    {
        x_a[i] = x_a[i - 1] + dX;
        y_a[i] = y_a[i - 1] + dY;
        i++;
    }
    x_a[i] = x_end;
    y_a[i] = y_end;

    /* Output: -----------------------*/
    i = 0;
    while (i <= L && ((y + 1) < 1000))
    {
        mlx_pixel_put(block->mlx, block->win, 50 + roundf(x_a[i]), 50 + roundf(y_a[i]), 0xffffff);
        i++;
        // y++;
    }
    /* -------------------------------*/
}


void				print_map(t_block *block)
{
	block->mlx = mlx_init();
	block->win = mlx_new_window(block->mlx , 1000, 1000, "fdf"); // x , y
    mlx_pixel_put(block->mlx, block->win, 500, 500, 0xffff00);
    int x;
    int y = 0;

    while (y < (block->y_max))
	{
        x = 0;
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
    dda_line_dick(block, 0 , 0);


	// mlx_string_put(block->mlx, block->win, 200, 200, 0xffddff, "hello!\n");


	mlx_key_hook(block->win, key_hook, 0);
	// mlx_mouse_hook(block->win, mouse_hook, 0);
	// mlx_expose_hook(block->win, expose_hook, 0);
	// mlx_loop_hook(block->win, loop_hook, 0);
	mlx_loop(block->mlx);
   
}