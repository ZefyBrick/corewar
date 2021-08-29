/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_form.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 12:24:07 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/05 19:54:51 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	format_str(char **s, char *tmp, int len, t_printf *p)
{
	ft_arg_mal(s, len, p);
	if (p->prec < 0 && p->dot == 1)
		p->prec = 0;
	ft_push_arg(s, tmp, p);
}

void	format_chr(char **s, t_printf *p)
{
	int		len;

	p->prec = 0;
	ft_arg_mal(s, 1, p);
	if ((len = p->width - 1) < 0)
		len = 0;
}

int		format_ptr(char **s, char *tmp, int len, t_printf *p)
{
	int		size;

	size = ft_size_mal(len, p);
	ft_arg_mal(s, size, p);
	push_arg_hex_oct(s, tmp, len, p);
	write_arg_hex_oct(*s, size, p);
	return (size);
}

int		format_hex(char **s, char *tmp, int len, t_printf *p)
{
	int		size;

	size = ft_size_mal(len, p);
	ft_arg_mal(s, size, p);
	push_arg_hex_oct(s, tmp, len, p);
	size = write_arg_hex_oct(*s, size, p);
	return (size);
}

int		format_oct(char **s, char *tmp, int len, t_printf *p)
{
	int		size;

	size = ft_size_mal(len, p);
	ft_arg_mal(s, size, p);
	push_arg_hex_oct(s, tmp, len, p);
	return (size);
}
