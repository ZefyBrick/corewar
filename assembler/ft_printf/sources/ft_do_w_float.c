/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_w_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 17:03:29 by brickon-          #+#    #+#             */
/*   Updated: 2020/02/13 19:09:52 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_print_inf_nan(double f, t_printf *p)
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

char	*ft_conv_flt2(char *s, double f, t_printf *p, unsigned int tmp)
{
	int i;

	i = 0;
	tmp = (unsigned int)f;
	ft_join_free(&s, ".");
	while (i < p->prec + 1)
	{
		f = (f - (double)tmp + 1) * 1000000.0;
		tmp = (unsigned int)f;
		ft_jf_utoa_push(&s, tmp, 1);
		i += 6;
	}
	if (*(ft_strchr(s, '.') + p->prec + 1) >= '5')
		return (ft_ronding(s, p->prec));
	return (s);
}

char	*ft_conv_float(double arg, int i, t_printf *p)
{
	char			*s;
	unsigned int	tmp;

	if (arg / 0. == arg || arg != arg)
		return (ft_print_inf_nan(arg, p));
	if (arg < 0)
	{
		arg = -arg;
		p->sig = '-';
	}
	s = NULL;
	while (arg >= 4294967294.0)
	{
		arg = arg / 10.0;
		i--;
	}
	tmp = (unsigned int)arg;
	s = ft_itoa(tmp);
	while (i++)
	{
		arg = (arg - (double)tmp + 1.0) * 10;
		tmp = (unsigned int)arg;
		!(s) ? s = ft_itoa(tmp) : ft_jf_utoa_push(&s, tmp, 1);
	}
	return (ft_conv_flt2(s, arg, p, tmp));
}
