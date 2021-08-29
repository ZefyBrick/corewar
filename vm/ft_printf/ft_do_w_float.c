/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_w_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 17:03:29 by brickon-          #+#    #+#             */
/*   Updated: 2019/08/24 17:15:38 by brickon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_print_inf_nan(double f, t_print *p)
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

char	*ft_join_one(char *s)
{
	char	*str;
	int		k;
	int		i;

	i = 0;
	k = ft_strlen(s) + 2;
	str = malloc(k);
	str[i] = '1';
	while (s[i])
	{
		str[i + 1] = s[i];
		i++;
	}
	str[i + 1] = '\0';
	free(s);
	return (str);
}

char	*ft_ronding(char *s, int pres)
{
	int i;

	i = ft_strchr(s, '.') - s + pres + 1;
	while (i >= 1)
	{
		if (s[i - 1] == '.')
			i--;
		if (s[i - 1] < '9')
		{
			s[i - 1]++;
			break ;
		}
		else
			s[i - 1] = 48;
		i--;
	}
	if (!i)
		return (ft_join_one(s));
	return (s);
}

char	*ft_conv_flt2(char *s, double f, t_print *p, unsigned int tmp)
{
	int i;

	i = 0;
	tmp = (unsigned int)f;
	ft_first_free_join(&s, ".");
	while (i < p->pres + 1)
	{
		f = (f - (double)tmp + 1) * 1000000.0;
		tmp = (unsigned int)f;
		ft_jf_utoa_push(&s, tmp, 1);
		i += 6;
	}
	if (*(ft_strchr(s, '.') + p->pres + 1) >= '5')
		return (ft_ronding(s, p->pres));
	return (s);
}

char	*ft_conv_float(double f, t_print *p, int i)
{
	char			*s;
	unsigned int	tmp;

	if (f / 0. == f || f != f)
		return (ft_print_inf_nan(f, p));
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
		f = (f - (double)tmp + 1.0) * 10;
		tmp = (unsigned int)f;
		!(s) ? s = ft_itoa(tmp) : ft_jf_utoa_push(&s, tmp, 1);
	}
	return (ft_conv_flt2(s, f, p, tmp));
}
