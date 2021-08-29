/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_tools5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:39:48 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/13 19:08:24 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	fill_hex_arg(char **s, char *tmp, int calibr, t_printf *p)
{
	int		i;

	i = -1;
	if (p->prec == 0 && tmp[0] == '0')
		return ;
	else
		while (tmp[++i])
			(*s)[calibr + i] = tmp[i];
}

void	fill_oct_arg(char **s, char *tmp, int calibr, t_printf *p)
{
	int		i;

	i = -1;
	if (p->prec == 0 && tmp[0] == '0')
		return ;
	while (tmp[++i])
		(*s)[calibr + i] = tmp[i];
}

void	fill_int_arg(char **s, char *tmp, int calibr, t_printf *p)
{
	int		i;

	i = -1;
	if (p->prec == 0 && tmp[0] == '0')
		return ;
	while (tmp[++i])
		(*s)[calibr + i] = tmp[i];
}

void	int_modif(long long *arg, t_printf *p)
{
	p->flags[4] = '0';
	p->flags[2] = '0';
	p->sig = '-';
	*arg *= -1;
}
