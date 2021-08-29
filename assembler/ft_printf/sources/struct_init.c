/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:13:37 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/05 20:12:15 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	struct_init(t_printf *p)
{
	ft_memset(p->flags, '0', 5);
	p->sig = ' ';
	p->width = 0;
	p->prec = -1;
	p->dot = 0;
	ft_bzero(p->modifier, 4);
	p->specifier = '\0';
	p->hex_hash[0] = '0';
}
