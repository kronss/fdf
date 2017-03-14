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

/*
**	open file and reading it to buff[unsize]
**	validate: count nbr in line[y0] === line[yn]
**	initialization t_block and push date to t_block
**	push cords to 2 lvl array struckt
*/

#include "fdf.h"

static void				ft_color_pararm(char *str, t_block *block)
{
	if (*str == '0')
		block->color_param = ft_atohex(str);
	else
		block->color_param = ft_atoi(str);
}

static void				ft_validate(char *line, int *res)
{
	static int check = 0;

	if (check == 0)
		*res = 0;
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
	if (*res % check != 0 || check == 1)
	{
		ft_printf("map is not valid =(\n");
		exit(1);
	}
}

static void				join_to_buf(char **buf, char **line)
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

static void				ft_init_block(t_block *block, int y_max, int res)
{
	block->mlx = NULL;
	block->win = NULL;
	block->res = res;
	block->y_max = y_max;
	block->x_max = res / y_max;
	block->cord = NULL;
	if (res <= 400 && block->y_max <= 20 && block->x_max <= 20)
		block->zoom = 35;
	else if (res <= 10000 && block->y_max <= 100 && block->x_max <= 100)
		block->zoom = 6;
	else if (res <= 900 && block->y_max <= 30 && block->x_max <= 30)
		block->zoom = 20;
	else
		block->zoom = 2;
	block->color_param = 0xffffff;
}

int						main(int ar, char **av)
{
	t_block		block;
	char		*line;
	char		*buf;
	int			fd;
	int			res;

	if (!(ar == 2 || ar == 3))
		ft_usage(av[0]);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		fdf_error("error");
	while (get_next_line(fd, &line) > 0)
	{
		ft_validate(line, &res);
		join_to_buf(&buf, &line);
	}
	if (res == 0 || (get_next_line(fd, &line) == -1))
		fdf_error("error");
	ft_init_block(&block, ft_chrcount(buf, '\n'), res);
	ar == 3 ? ft_color_pararm(av[2], &block) : 0;
	create_cords_array(&block, 0, 0, buf);
	create_map(&block);
	print_map(&block);
	mlx_loop(block.mlx);
	return (0);
}
