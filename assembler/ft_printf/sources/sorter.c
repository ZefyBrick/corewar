/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:36:04 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/13 19:11:42 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		sort_int(va_list ap, int buf_size, t_printf *p)
{
	int			len;
	long long	arg;
	char		*s;
	char		*tmp;

	arg = va_arg(ap, long long);
	if (!(ft_strchr(p->modifier, 'l')) && (!(ft_strchr(p->modifier, 'z'))))
		var_sign_modif(&arg, p);
	if (arg < 0)
		int_modif(&arg, p);
	tmp = ft_itoa(arg);
	len = ft_strlen(tmp);
	int_len_modif(&len, p);
	format_int(&s, tmp, len, p);
	free(tmp);
	if (p->prec == 0 && tmp[0] == '0')
		len = 0;
	len = write_arg_int(len, p);
	write(1, s, len);
	free(s);
	return (len - buf_size);
}

int		sort_chr(va_list ap, int buf_size, t_printf *p)
{
	char	c1;
	char	*s;
	int		len;

	len = 1;
	c1 = va_arg(ap, int);
	format_chr(&s, p);
	if (p->flags[1] == '1' || p->width == 0)
		s[0] = c1;
	else
		s[p->width - len] = c1;
	len = write_arg_c(len, p);
	if (p->flags[0] == '1' && p->flags[1] == '1')
		cut_zero(&s, 1, p);
	write(1, s, len);
	free(s);
	return (len - buf_size);
}

int		sort_str(va_list ap, int buf_size, t_printf *p)
{
	char	*s;
	char	*tmp;
	int		len;

	len = 6;
	if (!(tmp = va_arg(ap, char *)))
	{
		format_str(&s, "(null)", len, p);
		p->prec > -1 ? len = p->prec : len;
		write(1, s, len);
		free(s);
		return (len - buf_size);
	}
	else
	{
		len = ft_strlen(tmp);
		format_str(&s, tmp, len, p);
		len = write_arg(len, p);
		write(1, s, len);
		free(s);
	}
	return (len - buf_size);
}

int		sort_ptr(va_list ap, int buf_size, t_printf *p)
{
	void	*ptr;
	char	*tmp;
	char	*s;
	int		len;
	int		i;

	i = 9;
	ptr = va_arg(ap, void *);
	tmp = ft_itoa_base_c((unsigned long long)ptr, 16, p->specifier);
	len = ft_strlen(tmp) + 2;
	p->prec += 2;
	len = format_ptr(&s, tmp, len, p);
	free(s);
	return (len - buf_size);
}

int		sort_hex(va_list ap, int buf_size, t_printf *p)
{
	unsigned long long	arg;
	char				*tmp;
	char				*s;
	int					len;
	int					i;

	i = 9;
	arg = va_arg(ap, unsigned long);
	var_unsign_modif(&arg, p);
	tmp = ft_itoa_base_c(arg, 16, p->specifier);
	len = ft_strlen(tmp);
	if (!ft_strcmp(tmp, "0"))
		p->flags[3] = '0';
	if (p->flags[3] == '1')
	{
		len += 2;
		p->prec += 2;
	}
	len = format_hex(&s, tmp, len, p);
	free(s);
	return (len - buf_size);
}
