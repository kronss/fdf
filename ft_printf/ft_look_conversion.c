/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_look_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 14:43:02 by ochayche          #+#    #+#             */
/*   Updated: 2017/02/17 14:43:03 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	parsing format str between % and conversion specifier
**	pushing data to struct
**	list->flags[1] = '#';
**	list->flags[2] = '0';
**	list->flags[3] = '-';
**	list->flags[4] = '+';
**	list->flags[5] = ' ';
*/

#include "ft_printf.h"

static void				create_list(t_flist **list)
{
	(*list) = malloc(sizeof(t_flist));
	(*list)->flags = ft_strdup(" *****");
	(*list)->width = -1;
	(*list)->precision = -1;
	(*list)->hh = 0;
	(*list)->h = 0;
	(*list)->l = 0;
	(*list)->z = 0;
	(*list)->ll = 0;
	(*list)->j = 0;
}

static void				ft_flags(char **fmt, t_flist **list)
{
	if (**fmt == '#')
		((*list)->flags)[1] = '#';
	else if (**fmt == '0')
		((*list)->flags)[2] = '0';
	else if (**fmt == '-')
		((*list)->flags)[3] = '-';
	else if (**fmt == '+')
		((*list)->flags)[4] = '+';
	else if (**fmt == ' ')
		((*list)->flags)[5] = ' ';
}

static char				ft_double_hl(char *fmt, char c)
{
	char				res;

	res = 0;
	while (ft_strchr_f("+-#0 .123456789hljz", *fmt))
	{
		if (*fmt == c)
			res++;
		fmt++;
	}
	if (res % 2 != 0)
		return (1);
	else
		return (0);
}

static void				ft_modifier(char **fmt, t_flist **lst)
{
	if (**fmt == 'h' && !(*lst)->h && !(*lst)->hh)
	{
		if (ft_double_hl(*fmt, 'h'))
			(*lst)->h = 1;
		else
			(*lst)->hh = 1;
	}
	if (**fmt == 'l' && !(*lst)->l && !(*lst)->ll)
	{
		if (ft_double_hl(*fmt, 'l'))
			(*lst)->l = 1;
		else
			(*lst)->ll = 1;
	}
	if (**fmt == 'z')
		((*lst)->z = 1);
	if (**fmt == 'j')
		((*lst)->j = 1);
}

int						ft_look_conversion(char **fmt, va_list va)
{
	t_flist				*lst;

	create_list(&lst);
	while ((ft_strchr_f("+-#0 .123456789hljz", **fmt)))
	{
		(ft_strchr_f("#0-+ ", **fmt)) ? ft_flags(fmt, &lst) : 0;
		if (ft_strchr_f("123456789", **fmt))
		{
			lst->width = ft_atoi_f(fmt);
			continue ;
		}
		if (**fmt == '.' && (*fmt)++)
		{
			lst->precision = ft_atoi_f(fmt);
			continue ;
		}
		(ft_strchr_f("hlzj", **fmt)) ? ft_modifier(fmt, &lst) : 0;
		(*fmt)++;
	}
	if (ft_strchr_f("%sSpdDioOuUxXcC", **fmt))
		lst->spec = **fmt;
	else
		lst->spec = **fmt;
	return (ft_out(lst, va));
}
