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

void				correct_center_cord(t_fdf_cord ***cord, int y_max, int x_max)
{
	int i = 0;
	int y;
	int x;
	int shft_y;
	int	shft_x;

	shft_y = y_max / 2;
	shft_x = x_max / 2;
	y = 0;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			printf("-center--\ncord -- %d\n", ++i);
			((*cord)[y][x]).y -= (double)shft_y;
			((*cord)[y][x]).x -= (double)shft_x;
			printf("y. %f\n", ((*cord)[y][x]).y);
			printf("x. %f\n", ((*cord)[y][x]).x);
			printf("z. %f\n------\n",((*cord)[y][x]).z);
			x++;
		}
		printf("================[y: %d] finish ==================\n", y);
		y++;
	}
}

void			create_cords(int x, int y, char **buf, t_fdf_cord		***cord)
{
	t_fdf_cord		tmp;
	tmp = (*cord)[y][x];
	static int i = 0;
	printf("-----\ncord -- %d\n", ++i);
	// if (!(tmp = malloc(sizeof(t_fdf_cord))))
	// 	fdf_error("error");
	tmp.y = (double)y;
	tmp.x = (double)x;
	printf("y:%f\n",tmp.y);
	printf("x:%f\n",tmp.x);
	tmp.z = (double)ft_atoi_shift_pointer(buf);
	// printf("posle  -- %p\n", buf);
	printf("z:%f\n  ---\n",tmp.z);
	if (**buf == ',')
	{
		(*buf)++;
		tmp.color = ft_atohex_shift_pointer(buf);
	}
	else
		tmp.color = 0;	
}

// void 				create_cords_array(t_fdf_cord ****cord, int res, char *buf, int y_max)
// {
// 	int 	x;
// 	int 	y;
// 	// printf("1[%p]\n", cord);
// 	// printf("1[%p]\n", *cord);
// 	if (!(*cord = malloc(sizeof(t_fdf_cord ***) * (y))))
// 		fdf_error("error");
// 	y = 0;
// 	while (y < y_max)
// 	{
// 		x = 0;
// 		if (!((*cord)[y] = malloc(sizeof(t_fdf_cord **) * (res / y_max))))
// 			fdf_error("error");
// 		while (x < (res / y_max))
// 		{	
// 			if (*buf != ' ' && *buf != '\n' && *buf != '\0')
// 			{
// 				(*cord)[y][x] = create_cords(x, y, &buf);
// 				printf("%f\n",(*cord)[y][x]->x);
// 				printf("%f\n",(*cord)[y][x]->y);
// 				printf("%f\n------\n",(*cord)[y][x]->z);
// 				x++;
// 			}	
// 			buf++;
// 		}
// 		(*cord)[y][x] = NULL;
// 		y++;
// 	}
// 	(*cord)[y] = NULL;
// 	// printf("2[%p]\n", cord);
// 	// printf("2[%p]\n", *cord);
// 	// printf("2[%p]\n", **cord);
// 	// printf("2[%p]\n", ***cord);
// 	// correct_center_cord(cord, x , y);
// }




void 				create_cords_array(t_fdf_cord ***cord, int res, char *buf, int y_max)
{
	int 	x;
	int 	y;
	// printf("1[%p]\n", cord);
	// printf("1[%p]\n", *cord);
	printf("res == %d\n", res);
	printf("y_max  %d\n", y_max);
	if (!((*cord) = malloc(sizeof(t_fdf_cord **) * (y_max + 1))))
		fdf_error("error");
	y = 0;
	while (y < y_max)
	{
		x = 0;
		if (!((*cord)[y] = malloc(sizeof(t_fdf_cord *) * ((res / y_max) + 1))))
			fdf_error("error");
		while (x < (res / y_max))
		{	
			if (*buf != ' ' && *buf != '\n' && *buf != '\0')
			{
				create_cords(x, y, &buf, cord);
				//(*cord)[y][x] = create_cords(x, y, &buf, cord);
				// printf("y. %f\n",(*cord)[y][x]->y);
				// printf("x. %f\n",(*cord)[y][x]->x);
				// printf("z. %f\n------\n",(*cord)[y][x]->z);
				x++;
			}	
			buf++;
		}
		// (*cord)[y][x] = NULL;
		// printf("y %d\n", y);
		// printf("x %d\n", x);
		// printf("(cord)[y][x] %p\n", &(*cord)[y][x]);
		y++;
	}
	(*cord)[y] = NULL;
	// printf("2[%p]\n", cord);
	// printf("2[%p]\n", *cord);
	// printf("2[%p]\n", **cord);
	// printf("2[%p]\n", ***cord);
	// correct_center_cord(cord, x , y);
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
	t_fdf_cord	**cord = NULL;
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
	


	create_cords_array(&cord, res, buf, ft_chrcount(buf, '\n'));
	// corect_center_cord(&cord, x_center, y_center);
	printf("=================================\n");
	// printf("[%c]--[%d]--[%c]\n", *buf, ft_atoi_shift_pointer(&buf), *buf);

	correct_center_cord(&cord, ft_chrcount(buf, '\n'), res / ft_chrcount(buf, '\n'));


	
	printf("return (0)\n");
	return (0);
}
