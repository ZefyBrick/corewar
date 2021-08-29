/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:36:13 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/05 20:10:25 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		prec_converter(t_printf *p, char *buf, int i)
{
	int		j;
	char	tmp[11];

	j = 0;
	p->dot = 1;
	if (!ft_strchr("0123456789", buf[i]))
		p->prec = 0;
	else
	{
		while (ft_strchr("0123456789", buf[i]))
			tmp[j++] = buf[i++];
		tmp[j] = '\0';
		p->prec = ft_atoi(tmp);
	}
	return (i);
}
