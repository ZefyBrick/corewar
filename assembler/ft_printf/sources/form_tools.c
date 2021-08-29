/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 13:31:45 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/13 19:07:17 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_arg_mal(char **s, int len, t_printf *p)
{
	if (p->width >= len)
	{
		*s = (char *)malloc(sizeof(char) * (p->width));
		form_zero(s, p->width, p);
	}
	else
	{
		*s = (char *)malloc(sizeof(char) * (len));
		form_zero(s, len, p);
	}
}

void	form_zero(char **s, int size, t_printf *p)
{
	if (p->flags[0] == '1')
		*s = ft_memset(*s, 48, size);
	else
		*s = ft_memset(*s, 32, size);
}

int		ft_size_mal(int len, t_printf *p)
{
	int		res;

	if ((len) >= p->width && (len) >= (p->prec))
		res = len;
	if ((p->prec) >= (len) && (p->prec) >= p->width)
		res = p->prec;
	if (p->width >= (len) && p->width >= (p->prec))
		res = p->width;
	return (res);
}

int		ft_size_modif(int len, t_printf *p)
{
	int		res;

	if (p->flags[1] == '1')
		res = 0;
	else if ((p->width - len) > 0 && p->prec == -1)
		res = p->width - len;
	else if (p->width > len && p->prec > 0 && p->prec < len)
		res = p->width - p->prec;
	else
		res = p->width - len;
	if (res < 0)
		res = 0;
	return (res);
}
