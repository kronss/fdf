/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:01:59 by ochayche          #+#    #+#             */
/*   Updated: 2017/02/27 15:02:00 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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



t_fdf_cord			*create_cords(int x, int y, char **buf)
{
	t_fdf_cord		*curr;
	
	curr = malloc(sizeof(t_fdf_cord));
	curr->x = x;
	curr->y = y;
	// printf("*create_cords [%c]\n", **buf);
	// printf("do atoi-- %p\n", buf);
	curr->z = ft_atoi_shift_pointer(buf);
	// printf("posle  -- %p\n", buf);
	if (**buf == ',')
	{
		(*buf)++;
		curr->color = ft_atohex_shift_pointer(buf);
	}
	else
		curr->color = 0;	
	return (curr);
}

void 				create_cords_array(t_fdf_cord ***cord, int res, char *buf)
{
	int 	i;
	int 	x;
	int 	y;

	if (!(*cord = malloc(sizeof(t_fdf_cord **) * res)))
		fdf_error("error");
	i = 0;
	x = 0;
	y = 0;
	while (*buf != '\0')
	{
		if (*buf != ' ' && *buf != '\n' && *buf != '\0') // && printf("while [%c]\n", *buf))
		{	
			// printf("do-----[%c] [%p]\n", *buf, &buf);
			
			(*cord)[i] = create_cords(x, y, &buf);
			i++;
			x++;
			// printf("posle--[%c] [%p]\n", *buf, &buf);
			// printf("posle   crea--%p\n\n\n\n", &buf);
			// sleep(1);
			// buf++;
		}
		if (*buf == '\n')
		{
			// printf("------------------------\\n--------------------------------------\n");
			y ++;
			x = 0;
		}
		buf ++;
	}

}

static void					ft_validate(char *line, int *res)
{
	// printf("line - ft_validate [%p]\n", &line);
	static int check = 0;
	while (*line != '\0')
	{
		if (*line != ' ')
		{
			(*res)++;
			while (*line != ' ' && *line != '\0')
				line++;
			continue ;
		}
		line++;
	}

	if (!check)
		check = (*res);
	if (*res % check != 0)
	{
		ft_printf("map is not valid\n");
		exit(1);
	}
}

static void					join_to_buf(char **buf, char **line)
{
	char			*tmp;
	char			*tmp2;

	if (*buf)
	{
		tmp = ft_strdup(*buf);
		ft_strdel(buf);
		tmp2 = ft_strjoin(tmp, *line);
		*buf = ft_strjoin(tmp2, "\n");
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	else
		*buf = ft_strjoin(*line, "\n");
	ft_strdel(line);
}

int						main(int ar, char **av)
{
	t_block		*block;
	t_fdf_cord	**cord;
	char		*line;
	char		*buf = NULL;
	int			fd;
	int 		res;

	if (ar != 2)
		ft_usage(av[0]);
	if ((fd = open(av[1] ,O_RDONLY)) == -1)
		fdf_error("error");
	res = 0;
	while (get_next_line(fd, &line) > 0)
	{
		ft_validate(line, &res);
		join_to_buf(&buf, &line);
	}
	if (res == 0 || (get_next_line(fd, &line) == -1))
		fdf_error("error");
	ft_printf("file was read:\n%s\n", buf);
	ft_printf("was found %d cords\n", res);
	// printf("srt--%p\n", &buf);
	create_cords_array(&cord, res, buf);

	// printf("[%c]--[%d]--[%c]\n", *buf, ft_atoi_shift_pointer(&buf), *buf);




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
	
	return (0);
}
