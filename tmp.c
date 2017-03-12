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





int main(int argc, char const *argv[])
{
	printf("double:%lu\n", sizeof(double));
	printf("float:%lu\n", sizeof(float));
	double a = 4.4;
	printf("%f\n", a);
	printf("%f\n", roundf(a));

	return 0;
}