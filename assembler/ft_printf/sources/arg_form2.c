/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_form2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:48:48 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/13 19:07:09 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	format_int(char **s, char *tmp, int len, t_printf *p)
{
	int		size;

	size = 0;
	if (p->flags[1] == '1')
		p->flags[0] = '0';
	if (p->prec > len)
		size = p->prec - len;
	ft_arg_mal(s, len + size, p);
	push_arg_int(s, tmp, len, p);
}

void	format_per(char **s, t_printf *p)
{
	ft_arg_mal(s, 1, p);
	push_per(s, p);
}

void	format_uint(char **s, char *tmp, int len, t_printf *p)
{
	int		size;

	size = 0;
	if (p->flags[1] == '1')
		p->flags[0] = '0';
	if (p->prec > len)
		size = p->prec - len;
	ft_arg_mal(s, len + size, p);
	push_arg_int(s, tmp, len, p);
}
