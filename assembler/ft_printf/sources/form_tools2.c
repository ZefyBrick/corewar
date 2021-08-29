/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_tools2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:47:47 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/13 19:07:35 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	push_arg_hex_oct(char **s, char *tmp, int len, t_printf *p)
{
	int		i;
	int		calibr;

	i = -1;
	calibr = calibration_of_prec(len, p);
	if (p->flags[3] == '1' || p->specifier == 'p')
	{
		push_hash(s, calibr, p);
		calibr = calibr_o_x(calibr, p);
	}
	calibr = push_zero(s, calibr, len, p);
	if (p->width > len && p->width > p->prec && p->flags[0] == '1'
			&& p->flags[1] == '1')
		cut_zero(s, len, p);
	if (p->specifier == 'x' || p->specifier == 'X')
		fill_hex_arg(s, tmp, calibr, p);
	else if (p->specifier == 'o')
		fill_oct_arg(s, tmp, calibr, p);
	else
		while (tmp[++i])
			(*s)[calibr + i] = tmp[i];
}

void	push_hash(char **s, int calibr, t_printf *p)
{
	int		i;
	char	*hash;

	i = -1;
	hash = whats_hash(p);
	while (++i < 2)
		(*s)[calibr + i] = hash[i];
}

char	*whats_hash(t_printf *p)
{
	char	*tmp;

	if (p->specifier == 'x' || p->specifier == 'p')
		tmp = "0x";
	else if (p->specifier == 'X')
		tmp = "0X";
	else
		tmp = "0";
	return (tmp);
}

int		calibration_of_prec(int len, t_printf *p)
{
	int		res;
	int		tmp;

	res = 0;
	if (len > p->prec)
		tmp = len;
	else
		tmp = p->prec;
	if (p->flags[1] == '1' || p->width <= len || p->width <= p->prec
			|| p->flags[0] == '1')
		res = 0;
	else if (p->width > tmp)
		res = p->width - tmp;
	return (res);
}

int		calibr_o_x(int calibr, t_printf *p)
{
	if (p->specifier == 'o')
		calibr += 1;
	else
		calibr += 2;
	return (calibr);
}
