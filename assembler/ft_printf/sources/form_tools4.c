/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_tools4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:00:11 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/13 19:14:45 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		fill_plus_or_space(char **s, char *tmp, int calibr, t_printf *p)
{
	if (p->flags[2] == '1' && tmp[0] != '-')
		(*s)[calibr] = '+';
	else if (p->flags[2] == '0' && p->flags[4] == '1')
		(*s)[calibr] = ' ';
	return (++calibr);
}

int		cut_front_zero(char **s, t_printf *p)
{
	int		i;
	int		size;

	i = -1;
	size = p->width - p->prec;
	while (++i < size)
		(*s)[i] = ' ';
	return (i);
}

void	var_sign_modif(long long *arg, t_printf *p)
{
	if (p->modifier[0] == 'z' ||
			(p->modifier[0] == 'l' && (p->count_mod % 2) == 0))
		(*arg) = (long long)(*arg);
	if (p->modifier[0] == 'j' ||
			(p->modifier[0] == 'l' && (p->count_mod % 2) != 0))
		(*arg) = (long)(*arg);
	else if (p->modifier[0] == 'h' && (p->count_mod % 2) == 0)
		(*arg) = (short)(*arg);
	else if (p->modifier[0] == 'h' && (p->count_mod % 2) != 0)
		(*arg) = (char)(*arg);
	else
		(*arg) = (int)(*arg);
}

void	var_unsign_modif(unsigned long long *arg, t_printf *p)
{
	if (p->modifier[0] == 'z' ||
			(p->modifier[0] == 'l' && (p->count_mod % 2) == 0))
		(*arg) = (unsigned long long)(*arg);
	else if (p->modifier[0] == 'j' || (p->modifier[0] == 'l'
				&& (p->count_mod % 2) != 0))
		(*arg) = (long)(*arg);
	else if (p->modifier[0] == 'h' && (p->count_mod % 2) == 0)
		(*arg) = (unsigned short)(*arg);
	else if (p->modifier[0] == 'h' && (p->count_mod % 2) != 0)
		(*arg) = (unsigned char)(*arg);
	else
		(*arg) = (unsigned int)(*arg);
}

void	push_per(char **s, t_printf *p)
{
	int		calibr;

	calibr = 0;
	if (p->flags[1] == '0')
		if ((calibr = p->width - 1) < 0)
			calibr = 0;
	if (p->flags[1] == '1')
		cut_zero(s, 1, p);
	(*s)[calibr] = '%';
}
