/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:44:21 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/05 20:15:49 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			distributor(va_list ap, char *buf, t_printf *p, int res)
{
	int			buf_size;

	buf_size = ft_strlen(buf) + 1;
	if (ft_strchr("di", p->specifier))
		res = sort_int(ap, buf_size, p);
	else if (p->specifier == 'c')
		res = sort_chr(ap, buf_size, p);
	else if (p->specifier == 'p')
		res = sort_ptr(ap, buf_size, p);
	else if (p->specifier == 's')
		res = sort_str(ap, buf_size, p);
	else if (ft_strchr("xX", p->specifier))
		res = sort_hex(ap, buf_size, p);
	else if (p->specifier == 'o')
		res = sort_oct(ap, buf_size, p);
	else if (p->specifier == 'b')
		res = sort_bin(p->specifier, buf_size, ap);
	else if (p->specifier == 'u' || p->specifier == 'U')
		res = sort_uint(ap, buf_size, p);
	else if (p->specifier == '%')
		res = sort_per(p, buf_size);
	else if (p->specifier == 'f')
		res = sort_float(ap, buf_size, p);
	return (res);
}

int			ft_arg_reader(const char *format, int i, va_list ap)
{
	char		buf[BUFF_SIZE];
	t_printf	p;
	int			j;

	j = 0;
	ft_bzero(buf, BUFF_SIZE);
	while (format[++i])
	{
		buf[j++] = format[i];
		if (ft_strchr("bcspdiouUxXfZ%", format[i]))
		{
			buf[j] = '\0';
			parse_struct(buf, &p);
			if (format[i] == 'Z')
				return (print_z(buf));
			j = distributor(ap, buf, &p, 0);
			return (j);
		}
	}
	return (0);
}

int			ft_printf(const char *format, ...)
{
	int			i;
	static int	ret;
	va_list		ap;

	i = 0;
	ret = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
			write(1, &format[i], 1);
		else
		{
			ret += ft_arg_reader(format, i, ap);
			while (!(ft_strchr("bcspdiouUxXfZ%", format[++i]) &&
						format[i] != '\0'))
				;
		}
		i++;
	}
	va_end(ap);
	return (ret += i);
}
