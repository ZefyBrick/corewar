/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_tools3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 15:53:58 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/13 19:13:58 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		push_zero(char **s, int calibr, int len, t_printf *p)
{
	int		i;
	int		zero;

	i = -1;
	if ((zero = p->prec - len) < 0)
		zero = 0;
	if (p->width > len && p->width > p->prec && p->flags[0] == '1'
			&& p->flags[1] == '0')
	{
		if (len > p->prec)
			zero = p->width - len;
		else
			zero = p->prec - len;
	}
	while (++i < zero)
		(*s)[calibr + i] = '0';
	return (calibr + zero);
}

void	ft_push_arg(char **s, char *tmp, t_printf *p)
{
	int		i;
	int		len;
	int		size;

	i = -1;
	len = ft_strlen(tmp);
	size = ft_size_modif(len, p);
	ft_push_arg2(s, tmp, size, p);
}

void	ft_push_arg2(char **s, char *tmp, int size, t_printf *p)
{
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(tmp);
	if (p->prec == 0)
		return ;
	else if (p->prec > 0 && p->prec < len)
		while (++i < p->prec)
			(*s)[size + i] = tmp[i];
	else
		while (tmp[++i])
			(*s)[size + i] = tmp[i];
	if (p->width > len && p->width > p->prec && p->flags[0] == '1'
			&& p->flags[1] == '1')
		cut_zero(s, len, p);
}

void	cut_zero(char **s, int len, t_printf *p)
{
	int		i;

	i = 0;
	if (((p->flags[1] == '1' || p->flags[0] == '1') && p->width > len))
	{
		if (len > p->prec)
			i = len;
		else
			i = p->prec;
	}
	while (i < p->width)
		(*s)[i++] = ' ';
}

void	push_arg_int(char **s, char *tmp, int len, t_printf *p)
{
	int		i;
	int		calibr;

	i = -1;
	calibr = calibration_of_prec(len, p);
	if (p->flags[2] == '1' || p->flags[4] == '1')
		calibr = fill_plus_or_space(s, tmp, calibr, p);
	if (p->flags[0] == '1' && p->prec < p->width && p->prec > len)
		calibr = cut_front_zero(s, p);
	if (p->sig == '-')
		(*s)[calibr++] = p->sig;
	calibr = push_zero(s, calibr, len, p);
	fill_int_arg(s, tmp, calibr, p);
}
