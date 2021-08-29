/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_float2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 18:14:21 by brickon-          #+#    #+#             */
/*   Updated: 2020/02/13 19:15:26 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_float(char **s, va_list ap, t_printf *p)
{
	if (p->prec == -1)
		p->prec = 6;
	if (ft_strchr(p->modifier, 'L'))
		(*s) = ft_conv_ldouble(va_arg(ap, long double), 0, p);
	else
		(*s) = ft_conv_float(va_arg(ap, double), 0, p);
	if (p->prec == 0 && (*s)[0] != 'i' && (*s)[0] != 'n' && p->flags[3] == '0')
		*(ft_strchr((*s), '.')) = '\0';
	else if ((*s)[0] != 'i' && (*s)[0] != 'n')
		*(ft_strchr((*s), '.') + p->prec + 1) = '\0';
	ft_space_zero_float(s, p);
}
