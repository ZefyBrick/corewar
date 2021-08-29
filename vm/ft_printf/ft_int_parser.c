/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 21:37:26 by cdubuque          #+#    #+#             */
/*   Updated: 2019/09/04 15:20:23 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				ft_write_ac_w(char **w, char **ac, char *m)
{
	size_t			j;
	int				zn;
	char			*mas;

	mas = ft_strdup(m);
	j = 0;
	zn = 0;
	if (ft_strrchr(mas, '-'))
		zn = 1;
	if (ft_strrchr(mas, '.'))
	{
		if (ft_isdigit((ft_strrchr(mas, '.') + 1)[0]))
			j = ft_atoi(ft_strrchr(mas, '.') + 1);
	}
	*ac = ft_itoa(j);
	*w = ft_strdup("0");
	while (*mas == ' ')
		mas = ft_free_strdup(mas, 1);
	ft_write_w(mas, &(*w));
	if (zn == 1 && ft_atoi(*w) > 0)
	{
		free(*w);
		*w = ft_itoa(-ft_atoi(*w));
	}
	free(mas);
}

char				*ft_int(char *s, char *m, size_t h)
{
	char			*w;
	char			*ac;
	int				i;

	ft_write_ac_w(&w, &ac, m);
	if (ft_strlen(s) == 1 && s[0] == '0' && ft_strchr(m, '.'))
		s[0] = '\0';
	i = ft_strlen(s);
	if (ft_modul(ac) > (int)i)
	{
		s = ft_only_accur(ac, i, s, h);
		i = ft_strlen(s);
	}
	if (ft_atoi(ac) != 0 && w[0] == '0')
		w = ft_free_strdup(w, 1);
	s = ft_only_width(w, i, s, h);
	free(ac);
	free(w);
	return (s);
}

long long			ft_iint(char *spez, va_list ap, size_t *c)
{
	long long		i;

	if (ft_strchr(spez, 'l') || ft_strchr(spez, 'j'))
		i = va_arg(ap, long long);
	else if (ft_strlen(spez) > 1 && spez[0] == 'h')
		i = (char)va_arg(ap, int);
	else if (ft_strlen(spez) == 1 && spez[0] == 'h')
		i = (short)va_arg(ap, int);
	else
		i = va_arg(ap, int);
	if (i < 0)
	{
		*c = 1;
		i = -i;
	}
	return (i);
}

char				*ft_minus(char *s, char *m)
{
	int				c;

	c = 0;
	if (s[0] == '0' && (!(ft_strchr(m, '.'))))
		s[0] = '-';
	else if (s[0] == ' ')
	{
		while (s[c] == ' ' && s[c + 1] == ' ')
			c++;
		s[c] = '-';
	}
	else
		s = ft_second_free_join("-", s);
	if (ft_strchr(ft_strchr(s, '-'), ' '))
		s[ft_strlen(s) - 1] = '\0';
	return (s);
}

size_t				ft_intint(char *m, va_list ap, size_t h, char *spez)
{
	long long		i;
	char			*s;
	size_t			c;

	c = 0;
	i = ft_iint(spez, ap, &c);
	if (c == 1 && (h == 1 || h == 2))
		h = 0;
	hex('i', &m, spez, &h);
	s = ft_int(ft_unsigned((unsigned long long)i, 10, 0), m, h);
	if (c == 1)
		s = ft_minus(s, m);
	ft_putstr(s);
	free(spez);
	c = ft_strlen(s);
	free(s);
	free(m);
	return (c);
}
