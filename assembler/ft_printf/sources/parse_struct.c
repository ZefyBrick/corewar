/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 12:40:31 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/13 19:11:19 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	parse_struct(char *buf, t_printf *p)
{
	int	i;

	i = -1;
	struct_init(p);
	while (buf[++i])
	{
		if (buf[i] == '-')
			p->flags[1] = '1';
		if (buf[i] == '0' && !ft_strchr(".0123456789", buf[i - 1]))
			p->flags[0] = '1';
		if (buf[i] == '+')
			p->flags[2] = '1';
		if (buf[i] == '#')
			p->flags[3] = '1';
		if (buf[i] == ' ')
			p->flags[4] = '1';
		if (ft_strchr("123456789", buf[i]) && buf[i - 1] != '.')
			i = width_converter(p, buf, i);
		if (buf[i - 1] == '.')
			i = prec_converter(p, buf, i);
		if (ft_strchr("jhlLz", buf[i]))
			i = modif_checker(p, buf, i);
	}
	p->specifier = buf[i - 1];
}
