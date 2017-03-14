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

typedef	struct	s_fdf_cord
{
	double		x;
	double		y;
	double		z;

	double		x_res;
	double		y_res;
	double		z_res;

	int			color;
	// int			color_white;
	int			color_res;
}				t_fdf_cord;




typedef	struct		s_block
{
	void			*mlx;
	void			*win;
	int				y_max;
	int				x_max;

	void			*img;
	char 			*ptr;
	
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	double			x_ar[1200];
	double			y_ar[1200];
	// int				y_max;
	// int				x_max;




	int				res;
	int			zoom;

	t_fdf_cord 		**cord;
	// int				min_win_y;
	// int				min_win_x;
	

}					t_block;






void		ft_usage(char *argv);
void		fdf_error(char *str);
void		create_cords_array(t_block *block, int y, int x, char *buf);
void			create_map(t_block *block);
void		print_map(t_block *block);
void			create_img(t_block *block);


void		turn_arround_y(t_block *block, double angl);
void		turn_arround_x(t_block *block, double angl);
void		turn_arround_z(t_block *block, double angl);
void		reset_cord(t_block *block);
void		zoom(t_block *block, double zoom);
void		move_along_y(t_block *block, double shift);
void		move_along_x(t_block *block, double shift);
void		color_change(t_block *block, char a);

#endif
