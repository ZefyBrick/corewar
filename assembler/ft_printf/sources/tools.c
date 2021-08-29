/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 18:16:42 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/05 20:19:22 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		write_arg(int len, t_printf *p)
{
	int		res;

	if (p->width < len && (p->prec < 0 || p->prec > len))
		res = len;
	else if (p->width < len && p->prec > 0 && p->prec < len)
		res = p->prec;
	else
		res = p->width;
	return (res);
}

int		write_arg_c(int len, t_printf *p)
{
	int		res;

	if (p->width < len)
		res = len;
	else
		res = p->width;
	return (res);
}

int		write_arg_hex_oct(char *s, int size, t_printf *p)
{
	if (p->prec != 0)
		write(1, s, size);
	else if (p->width > 0)
		write(1, s, size);
	else
		size = 0;
	return (size);
}

int		write_arg_int(int len, t_printf *p)
{
	int		res;

	if (p->width >= len && p->width >= p->prec)
		res = p->width;
	else if (p->width < len && p->prec < len)
		res = len;
	else
		res = p->prec;
	return (res);
}

int		print_z(char *buf)
{
	write(1, "Z", 1);
	return (0 - ft_strlen(buf));
}
