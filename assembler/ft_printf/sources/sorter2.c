/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 19:18:31 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/13 19:12:23 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		sort_bin(char c, int buf_size, va_list ap)
{
	unsigned long	i;
	char			*s;
	int				len;

	s = ft_strnew(BUFF_SIZE);
	i = va_arg(ap, unsigned long);
	s = ft_itoa_base_c(i, 2, c);
	len = ft_strlen(s);
	write(1, s, len);
	return (len - buf_size);
}

int		sort_oct(va_list ap, int buf_size, t_printf *p)
{
	unsigned long long	arg;
	char				*tmp;
	char				*s;
	int					len;

	arg = va_arg(ap, unsigned long);
	var_unsign_modif(&arg, p);
	tmp = ft_itoa_base_c(arg, 8, p->specifier);
	len = ft_strlen(tmp);
	if (arg == 0 && p->prec == -1 && p->flags[3] == '1')
		len--;
	if (p->flags[3] == '1')
		len++;
	if ((tmp[0] == '0') && p->prec == 0)
		len--;
	len = format_oct(&s, tmp, len, p);
	write(1, s, len);
	free(s);
	return (len - buf_size);
}

int		sort_uint(va_list ap, int buf_size, t_printf *p)
{
	unsigned long long	arg;
	int					len;
	char				*s;
	char				*tmp;

	p->flags[3] = '0';
	p->flags[4] = '0';
	p->flags[2] = '0';
	arg = va_arg(ap, unsigned long long);
	if (p->specifier != 'U')
		var_unsign_modif(&arg, p);
	tmp = ft_itoa(arg);
	len = ft_strlen(tmp);
	format_uint(&s, tmp, len, p);
	free(tmp);
	len = write_arg_int(len, p);
	write(1, s, len);
	free(s);
	return (p->width > len ? p->width - buf_size : len - buf_size);
}

int		sort_per(t_printf *p, int buf_size)
{
	int		len;
	char	*s;

	len = 1;
	p->prec = 0;
	format_per(&s, p);
	if (p->width > len)
		len = p->width;
	write(1, s, len);
	free(s);
	return (len - buf_size);
}

int		sort_float(va_list ap, int buf_size, t_printf *p)
{
	int		len;
	char	*s;

	buf_size = 1;
	p->width = 1;
	ft_float(&s, ap, p);
	len = ft_strlen(s);
	write(1, s, len);
	return (buf_size);
}
