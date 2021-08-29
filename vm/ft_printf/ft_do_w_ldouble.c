/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_w_ldouble.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 17:27:14 by brickon-          #+#    #+#             */
/*   Updated: 2019/08/25 17:34:56 by brickon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_printl_inf_nan(long double f, t_print *p)
{
	if (f / 0. == f)
	{
		p->zero = 0;
		return (ft_strdup("inf"));
	}
	else
	{
		p->zero = 0;
		p->plus = 0;
		return (ft_strdup("nan"));
	}
}

char	*ft_cld2(char *s, long double f, t_print *p, unsigned int tmp)
{
	int i;

	i = 0;
	tmp = (unsigned int)f;
	ft_first_free_join(&s, ".");
	while (i < p->pres + 1)
	{
		f = (f - (long double)tmp + 1) * 1000000.0;
		tmp = (unsigned int)f;
		ft_jf_utoa_push(&s, tmp, 1);
		i += 6;
	}
	if (*(ft_strchr(s, '.') + p->pres + 1) >= '5')
		return (ft_ronding(s, p->pres));
	return (s);
}

char	*ft_conv_ldouble(long double f, t_print *p, int i)
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
