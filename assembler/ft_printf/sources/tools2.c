/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 12:52:52 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/13 19:12:55 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*fill_rep(char c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (c == 'X')
		tmp = "0123456789ABCDEF";
	else
		tmp = "0123456789abcdef";
	return (tmp);
}

char	*ft_itoa_base_c(unsigned long long value, int base, char c)
{
	char			*rep;
	static char		buf[50];
	char			*ptr;
	unsigned long	num;

	rep = fill_rep(c);
	ptr = &buf[49];
	*ptr = '\0';
	num = value;
	if (value != 0 && base == 10)
		value *= -1;
	if (value == 0)
		*--ptr = rep[value % base];
	while (value != 0)
	{
		*--ptr = rep[value % base];
		value /= base;
	}
	if (num != 0 && base == 10)
		*--ptr = '-';
	return (ptr);
}

void	int_len_modif(int *len, t_printf *p)
{
	if (p->flags[2] == '1' || p->flags[4] == '1' || (p->sig == '-'))
	{
		if (p->width == *len || p->width == p->prec)
			p->width++;
		if (p->prec > 0)
			p->prec++;
		(*len)++;
	}
}

int		one_percent(const char *format, int *i)
{
	while (format[++(*i)])
		if (!(ft_strchr("bcspdiouUxXfZ%", format[(*i)])))
			return (0);
	return (0);
}
