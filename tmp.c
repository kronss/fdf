#include <stdio.h>
# include <math.h>

	// int 		key_hook(int key_code, void *param)
// {
// 	printf("key code is: [%d]\n", key_code);
// 	if (key_code == 53)
// 		exit(0);
// 	return (0);
// }

// int 		mouse_hook(int mouse_code, void *param)
// {
// 	printf("mose code is: [%d]\n", mouse_code);
// 	return (0);
// }

// // int expose_hook(int expose_code, void *param)
// // {
// // 	printf("expose_hook is: [%d]\n", expose_code);
// // 	return (0);
// // }

// // int loop_hook(int loop_code, void *param)⁄€‹
// // {
// // 	printf("loop_hook is: [%d]\n", loop_code);
// // 	return (0);
// // }
// double					get_double(char *line)
// {
// 	char *tmp;

// 	tmp = line;
// 	while (*tmp != '\0')
// 	{

// 	}
// }



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




	// sleep(5000);


	// block->mlx = mlx_init();
	// block->win = mlx_new_window(block->mlx ,640, 480, "fdf");
	// block->y = 50;
	// while (block->y < 150)
	// {
	// 	block->x = 50;
	// 	while (block->x < 150)
	// 	{
	// 		mlx_pixel_put(block->mlx, block->win, block->x, block->y, 0xFFFFFF);
	// 		block->x++;
	// 	}
	// 	block->y++;
	// }
	// ft_printf("dick\n");

	// // mlx_string_put(block->mlx, block->win, 200, 200, 0xffddff, "hello!\n");


	// mlx_key_hook(block->win, key_hook, 0);
	// mlx_mouse_hook(block->win, mouse_hook, 0);
	// // mlx_expose_hook(block->win, expose_hook, 0);
	// // mlx_loop_hook(block->win, loop_hook, 0);
	// mlx_loop(block->mlx);







// void 	segment(int x0, int y0, int x1, int y1, int color)
// void brazenheim_x(t_block *block, int y, int )
// {
// 	int j;
//   int dx = ABS((block->cord)[y][x + 1].x - (block->cord)[y][x].x);
//   int dy = ABS((block->cord)[y][x + 1].y - (block->cord)[y][x].y);
//   int sx = (block->cord)[y][x + 1].x >= (block->cord)[y][x].x ? 1 : -1;
//   int sy = (block->cord)[y][x + 1].y >= (block->cord)[y][x].y ? 1 : -1;
  
//   if (dy <= dx)
//   {
//     int d = (dy << 1) - dx;
//     int d1 = dy << 1;
//     int d2 = (dy - dx) << 1;

//     j = (((block->cord)[y][x].x + 500) * 4) + (((block->cord)[y][x].y + 500) * 1000 * 4);
//     block->ptr[j] = 255U;			// blue
//     block->ptr[j + 1] = 255U;		// green
//     block->ptr[j + 2] = 255U;		// red
    
//     //putpixel((block->cord)[y][x].x, (block->cord)[y][x].y, color);


//     for(int x_cor = (block->cord)[y][x].x + sx, y_cor = (block->cord)[y][x].y, i = 1; i <= dx; i++, x_cor += sx)
//     {
//       if ( d >0)
//       {
//         d += d2;
//         y += sy;
//       }
//       else
//         d += d1;
//       putpixel(x_cor, y, color);
//     }
//   }
//   else
//   {
//     int d = (dx << 1) - dy;
//     int d1 = dx << 1;
//     int d2 = (dx - dy) << 1;
    

//      j = (((block->cord)[y][x].x + 500) * 4) + (((block->cord)[y][x].y + 500) * 1000 * 4);
//     block->ptr[j] = 255U;			// blue
//     block->ptr[j + 1] = 255U;		// green
//     block->ptr[j + 2] = 255U;		// red

//    putpixel((block->cord)[y][x].x, (block->cord)[y][x].y, color);
  //   for(int y_cor = (block->cord)[y][x].y + sy, x = (block->cord)[y][x].x, i = 1; i <= dy; i++, y_cor += sy)
  //   {
  //     if ( d >0)
  //     {
  //       d += d2;
  //       x += sx;
  //     }
  //     else
  //       d += d1;
  //     putpixel(x, y_cor, color);
  //   }
  // }
// }

void		draw(t_block *block, int y, int x, int L)
{
	int i;
	int j;
	int x_limit;

	i = 0;
    while (i <= L)  // add limmit
	{
		x_limit = (roundf((block->x_ar)[i] + 500)) * 4;
		j = x_limit + (roundf(((block->y_ar)[i] + 500)) * block->size_line);
		if (0 <= j && j < 3999997 && 0 <= x_limit && x_limit < 3997)
		{
			block->ptr[j] = (block->cord)[y][x].color % 256; // blue
			block->ptr[j + 1] = ((block->cord)[y][x].color / 256) % 256; // green
			block->ptr[j + 2] = ((block->cord)[y][x].color / 256 / 256) % 256; // red
			// block->ptr[j + 3] = (block->cord)[y][x].color / 256 / 256 / 256; // transparansy
		}
		i++;
    }

}
void            dda_line_x(t_block *block, int y, int x)
{
    int        i, L, x_start, y_start, x_end, y_end;
    double    dX, dY;
    int j;

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
    (block->x_ar)[i] = ((block->cord)[y][x]).x;
    (block->y_ar)[i] = ((block->cord)[y][x]).y;
    i++;
    while (i < L)
    {
        (block->x_ar)[i] = (block->x_ar)[i - 1] + dX;
        (block->y_ar)[i] = (block->y_ar)[i - 1] + dY;
        i++;
    }
    (block->x_ar)[i] = ((block->cord)[y][x + 1]).x;
    (block->y_ar)[i] = ((block->cord)[y][x + 1]).y;

    /* Output: -----------------------*/
    // draw(block, y, x, L);
    i = 0;
    while (i <= L)  // add limmit
	{
		j = ((roundf((block->x_ar)[i] + 500)) * 4) + (roundf(((block->y_ar)[i] + 500)) * block->size_line);
		if (0 <= j && j < 3999997)
		{
			block->ptr[j] = (block->cord)[y][x].color % 256; // blue
			block->ptr[j + 1] = ((block->cord)[y][x].color / 256) % 256; // green
			block->ptr[j + 2] = ((block->cord)[y][x].color / 256 / 256) % 256; // red
			// block->ptr[j + 3] = (block->cord)[y][x].color / 256 / 256 / 256; // transparansy
		}
		i++;
		// y++;
    }
    /* -------------------------------*/
}



void dda_line_y(t_block *block, int y, int x)
{
    int        i, L, x_start, y_start, x_end, y_end;
    double    dX, dY;
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
    (block->x_ar)[i] = ((block->cord)[y][x]).x;
    (block->y_ar)[i] = ((block->cord)[y][x]).y;
    i++;
    while (i < L)
    {
        (block->x_ar)[i] = (block->x_ar)[i - 1] + dX;
        (block->y_ar)[i] = (block->y_ar)[i - 1] + dY;
        i++;
    }
    (block->x_ar)[i] = ((block->cord)[y + 1][x]).x;
    (block->y_ar)[i] = ((block->cord)[y + 1][x]).y;

    /* Output: -----------------------*/
    i = 0;
    while (i <= L)
    {
		j = ((roundf((block->x_ar)[i]) + 500) * 4) + ((roundf((block->y_ar)[i] + 500)) * block->size_line);
		if (0 <= j && j < 3999997)
		{
			block->ptr[j] = (block->cord)[y][x].color % 256; // blue
			block->ptr[j + 1] = ((block->cord)[y][x].color / 256) % 256; // green
			block->ptr[j + 2] = ((block->cord)[y][x].color / 256 / 256) % 256; // red
			// block->ptr[j + 3] = (block->cord)[y][x].color / 256 / 256 / 256; // transparansy
		}
		i++;
    }
    /* -------------------------------*/
}



int main(int argc, char const *argv[])
{
	printf("double:%lu\n", sizeof(double));
	printf("float:%lu\n", sizeof(float));
	double a = 4.4;
	printf("%f\n", a);
	printf("%f\n", roundf(a));

	return 0;
}