/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_w_ldouble.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 17:27:14 by brickon-          #+#    #+#             */
/*   Updated: 2020/02/13 19:15:09 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_printl_inf_nan(long double f, t_printf *p)
{
	if (f / 0. == f)
	{
		p->flags[0] = '0';
		return (ft_strdup("inf"));
	}
	else
	{
		p->flags[0] = '0';
		p->flags[2] = '0';
		return (ft_strdup("nan"));
	}
}

char	*ft_cld2(char *s, long double f, t_printf *p, unsigned int tmp)
{
	int i;

	i = 0;
	tmp = (unsigned int)f;
	ft_join_free(&s, ".");
	while (i < p->prec + 1)
	{
		f = (f - (long double)tmp + 1) * 1000000.0;
		tmp = (unsigned int)f;
		ft_jf_utoa_push(&s, tmp, 1);
		i += 6;
	}
	if (*(ft_strchr(s, '.') + p->prec + 1) >= '5')
		return (ft_ronding(s, p->prec));
	return (s);
}

char	*ft_conv_ldouble(long double f, int i, t_printf *p)
{
	char			*s;
	unsigned int	tmp;

	if (f / 0. == f || f != f)
		return (ft_printl_inf_nan(f, p));
	if (f < 0)
	{
		f = -f;
		p->sig = '-';
	}
	s = NULL;
	while (f >= 4294967294.0)
	{
		f = f / 10.0;
		i--;
	}
	tmp = (unsigned int)f;
	s = ft_itoa(tmp);
	while (i++)
	{
		f = (f - (long double)tmp + 1.0) * 10;
		tmp = (unsigned int)f;
		!(s) ? s = ft_itoa(tmp) : ft_jf_utoa_push(&s, tmp, 1);
	}
	return (ft_cld2(s, f, p, tmp));
}
