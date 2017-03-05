/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:02:39 by ochayche          #+#    #+#             */
/*   Updated: 2017/02/27 15:02:40 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# include <stdio.h> //dell


#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "minilibx_macos/mlx.h"
/*
**		open
**		read
**		write
**		close
**		malloc
**		free

**		perror

**		strerror
**		exit
**		All the functions defined in the library math (-lm et man 3 math)
**		All the functions defined in the library miniLibX.
*/

typedef	struct	s_block
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;


}				t_block;

typedef	struct	s_fdf_cord
{
	double	x;
	double	y;
	double	z;
	int		color;
}				t_fdf_cord;

void		ft_usage(char *argv);
void		fdf_error(char *str);






#endif