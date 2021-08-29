/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 18:08:43 by brickon-          #+#    #+#             */
/*   Updated: 2019/08/24 18:12:35 by brickon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_create_struct(t_print *p)
{
	p->minus = 0;
	p->plus = 0;
	p->pres = -1;
	p->space = 0;
	p->wh = 0;
	p->zero = 0;
}

char	*ft_str_write_push(char *dest, char *src, int push)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i + push] = src[i];
		i++;
	}
	return (dest);
}

void	ft_pars_width_float2(char **s, t_print *p, char **str)
{
	*str = ft_str_write_push(*str, *s, p->wh - ft_strlen(*s));
	if (p->space == 1)
		(*str)[p->wh - ft_strlen(*s) - 1] = ' ';
	if (p->plus == 1 && p->zero == 1)
		(*str)[0] = '+';
	if (p->plus == 1 && p->zero == 0)
		(*str)[p->wh - ft_strlen(*s) - 1] = '+';
	if (p->sig == '-' && p->zero == 1)
		(*str)[0] = '-';
	if (p->sig == '-' && p->zero == 0)
		(*str)[p->wh - ft_strlen(*s) - 1] = '-';
}

char	*ft_pars_width_float(char **s, t_print *p)
{
	char *str;

	str = ft_strnew(p->wh);
	if (p->zero == 1)
		str = ft_memset(str, '0', p->wh);
	else
		str = ft_memset(str, ' ', p->wh);
	if (p->minus == 1)
	{
		if (p->sig == '-' || p->plus == 1 || p->space == 1)
			str = ft_str_write_push(str, *s, 1);
		else
			str = ft_str_write_push(str, *s, 0);
		if (p->space == 1)
			str[0] = ' ';
		if (p->plus == 1)
			str[0] = '+';
		if (p->sig == '-')
			str[0] = '-';
	}
	else if (p->minus == 0)
		ft_pars_width_float2(s, p, &str);
	free(*s);
	*s = str;
	return (str);
}

void	ft_space_zero_float(char **s, t_print *p)
{
	char *str;

	if (p->wh <= (int)ft_strlen(*s))
	{
		str = ft_strnew(ft_strlen(*s) + 1);
		if (p->space != 1 && p->plus != 1 && p->sig != '-')
			str = ft_str_write_push(str, *s, 0);
		else
			str = ft_str_write_push(str, *s, 1);
		if (p->space == 1)
			str[0] = ' ';
		if (p->plus == 1)
			str[0] = '+';
		if (p->sig == '-')
			str[0] = '-';
		free(*s);
		*s = str;
	}
	else
		str = ft_pars_width_float(s, p);
	free(*s);
	*s = str;
}
