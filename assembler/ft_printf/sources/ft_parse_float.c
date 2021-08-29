/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 18:08:43 by brickon-          #+#    #+#             */
/*   Updated: 2020/02/13 19:10:43 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

void	ft_pars_width_float2(char **s, t_printf *p, char **str)
{
	*str = ft_str_write_push(*str, *s, p->width - ft_strlen(*s));
	if (p->flags[4] == '1')
		(*str)[p->width - ft_strlen(*s) - 1] = ' ';
	if (p->flags[2] == '1' && p->flags[0] == '1')
		(*str)[0] = '+';
	if (p->flags[2] == '1' && p->flags[0] == '0')
		(*str)[p->width - ft_strlen(*s) - 1] = '+';
	if (p->sig == '-' && p->flags[0] == '1')
		(*str)[0] = '-';
	if (p->sig == '-' && p->flags[0] == '0')
		(*str)[p->width - ft_strlen(*s) - 1] = '-';
}

char	*ft_pars_width_float(char **s, t_printf *p)
{
	char *str;

	str = ft_strnew(p->width);
	if (p->flags[0] == '1')
		str = ft_memset(str, '0', p->width);
	else
		str = ft_memset(str, ' ', p->width);
	if (p->flags[1] == '1')
	{
		if (p->sig == '-' || p->flags[2] == '1' || p->flags[4] == '1')
			str = ft_str_write_push(str, *s, 1);
		else
			str = ft_str_write_push(str, *s, 0);
		if (p->flags[4] == '1')
			str[0] = ' ';
		if (p->flags[2] == '1')
			str[0] = '+';
		if (p->sig == '-')
			str[0] = '-';
	}
	else if (p->flags[1] == '0')
		ft_pars_width_float2(s, p, &str);
	free(*s);
	*s = str;
	return (str);
}

void	ft_space_zero_float(char **s, t_printf *p)
{
	char *str;

	if (p->width <= (int)ft_strlen(*s))
	{
		str = ft_strnew(ft_strlen(*s) + 1);
		if (p->flags[4] != '1' && p->flags[2] != '1' && p->sig != '-')
			str = ft_str_write_push(str, *s, 0);
		else
			str = ft_str_write_push(str, *s, 1);
		if (p->flags[4] == '1')
			str[0] = ' ';
		if (p->flags[2] == '1')
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
