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

static void					ft_validate(char *line, int *res)
{
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
		ft_printf("map is not valid =(\n");
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

static void				ft_init_block(t_block *block, int y_max, int res)
{
	block->mlx = NULL;
	block->win = NULL;
	block->res = res;
	block->y_max = y_max;
	block->x_max = res / y_max;
	block->cord = NULL;
	block->zoom = 30;
	block->min_win_y = (block->y_max * block->zoom) + 200;
	block->min_win_x = (block->x_max * block->zoom) + 200;
	// block->
	// block->
}

int						main(int ar, char **av)
{
	t_block		block;
	char		*line;
	char		*buf;
	int			fd;
	int			res;

	line = NULL;
	buf = NULL;
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
	ft_init_block(&block, ft_chrcount(buf, '\n'), res);
	create_cords_array(&block, 0, 0, buf);
	// print_map(&block);
	return (0);
}
