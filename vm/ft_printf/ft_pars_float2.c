/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_float2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 18:14:21 by brickon-          #+#    #+#             */
/*   Updated: 2019/09/01 18:24:21 by brickon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_intlen(int nb)
{
	int i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int		ft_float2(int h, char *spez, va_list ap, t_print *p)
{
	char *s;

	s = NULL;
	if (h == 1)
		p->space = 1;
	if (h == 2)
		p->plus = 1;
	if (p->pres == -1)
		p->pres = 6;
	if (ft_strchr(spez, 'L'))
	{
		free(spez);
		s = ft_conv_ldouble(va_arg(ap, long double), p, 0);
	}
	else
	{
		free(spez);
		s = ft_conv_float(va_arg(ap, double), p, 0);
	}
	if (p->pres == 0 && s[0] != 'i' && s[0] != 'n')
		*(ft_strchr(s, '.')) = '\0';
	else if (s[0] != 'i' && s[0] != 'n')
		*(ft_strchr(s, '.') + p->pres + 1) = '\0';
	ft_space_zero_float(&s, p);
	return (ft_putstr_len(s));
}

void	ft_move_i_whide(t_print *p, int *i, char *mas)
{
	p->wh = ft_atoi(mas + (*i));
	*i = *i + ft_intlen(p->wh);
}

void	ft_move_i_pres(t_print *p, int *i, char *mas)
{
	p->pres = 0;
	p->pres = ft_atoi(mas + (*i) + 1);
	*i = *i + ft_intlen(p->pres) + 1;
}

int		ft_float(char *mas, size_t h, char *spez, va_list ap)
{
	t_print	p;
	int		i;

	ft_create_struct(&p);
	i = 0;
	while (mas[i])
	{
		if (mas[i] == '-' || mas[i] == '0')
		{
			if (mas[i] == '-')
				p.minus = 1;
			else if (mas[i] == '0')
				p.zero = 1;
			i++;
		}
		else if (ft_isdigit(mas[i]) && mas[i] != '0' && mas[i] != '-')
			ft_move_i_whide(&p, &i, mas);
		else if (mas[i] == '.')
			ft_move_i_pres(&p, &i, mas);
		else
			i++;
	}
	free(mas);
	return (ft_float2(h, spez, ap, &p));
}
