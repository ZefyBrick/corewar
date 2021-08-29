/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 19:26:32 by cdubuque          #+#    #+#             */
/*   Updated: 2019/09/04 15:20:03 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t					identifier(char **s, va_list ap)
{
	char				*mas;
	char				*spez;
	int					h;

	h = 0;
	mas = ft_strnew(ft_strlen(*s));
	flags(&(*s), &h, mas);
	spez = ft_strnew(ft_strlen(*s));
	ft_spez(&(*s), spez);
	if (!(ft_strchr("cspidpouUxXf%", **s)) || **s == '\0' || \
	(**s == '%' && ((*(*s + 1) == '\0' && ft_while_digit(mas) == 0) \
	|| ft_vhod_elem(ft_strchr(*s, '%') + 1, "cspidpouUxXf") == 1)))
		return (ft_spez_mas(mas, spez, &(*s)));
	else if (ft_strchr("ouUxX", **s) || ft_strchr(spez, 'z'))
		return (ft_uns(mas, ap, **s, spez));
	else if (**s == 'i' || **s == 'd')
		return (ft_intint(mas, ap, h, spez));
	else if (**s == 's' || **s == 'c' || **s == '%')
		return (ft_string_and_char(mas, ap, **s, spez));
	else if (**s == 'p')
		return (ft_point(mas, ap, spez));
	else if (**s == 'f')
		return (ft_float(mas, h, spez, ap));
	return (0);
}

int						ft_pred_proz(char **s)
{
	char				*mas;
	char				*t;
	size_t				j;
	int					i;

	i = 0;
	j = 0;
	t = *s;
	mas = ft_strnew(ft_strlen(*s));
	while (t[i] != '%' && t[i] != '\0')
		mas[j++] = t[i++];
	if (t[i] == '%' && t[i - 1] == '%' && (t[i + 1] != '\0' || t[i + 1] != '%'))
	{
		i++;
		while (t[i] != '%' && t[i] != '\0')
			mas[j++] = t[i++];
	}
	mas[j] = '\0';
	ft_putstr(mas);
	free(mas);
	*s += i;
	return (j);
}

void					ft_s_read(char **s, int *k)
{
	*s += 2;
	ft_putchar('%');
	*k += 1;
}

int						ft_printf(char *s, ...)
{
	va_list				ap;
	int					k;

	k = 0;
	va_start(ap, s);
	if (!s)
		exit(0);
	while (*s)
	{
		k = k + ft_pred_proz(&s);
		while (*s == '%' && *(s + 1) == '%')
			ft_s_read(&s, &k);
		if (s[0] == '%' && s[1] != '\0')
		{
			s += 1;
			k = k + identifier(&s, ap);
			if (((*s != '%' && *s) || (*s == '%' && (*(s + 1) == '%' \
			|| *(s + 1) == '\0'))))
				s += 1;
		}
		else if (s[0] == '%' && s[1] == '\0')
			s += 1;
	}
	va_end(ap);
	return (k);
}
