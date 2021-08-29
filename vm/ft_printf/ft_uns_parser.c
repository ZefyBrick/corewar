/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 21:39:48 by cdubuque          #+#    #+#             */
/*   Updated: 2019/09/03 21:18:49 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char				*ft_cut(char *m, char c)
{
	char			*st;
	char			*fn;
	char			*tmp;

	fn = m;
	tmp = m;
	st = m;
	fn = ft_strchr(m, c) + 1;
	fn[ft_strlen(fn)] = '\0';
	st = ft_strsub(m, 0, ft_strlen(m) - ft_strlen(fn) - 1);
	m = ft_strjoin(st, fn);
	free(tmp);
	free(st);
	return (m);
}

void				hex(char c, char **mas, char *spez, size_t *h)
{
	char			*m;

	m = ft_strdup(*mas);
	while (*spez != '#' && *spez != '\0')
		spez += 1;
	while (*m != '#' && *m != '\0')
		m = ft_free_strdup(m, 1);
	if (*m == '#' || *spez == '#')
	{
		if (c == 'o')
			*h = 5;
		else if (c == 'x')
			*h = 4;
		else if (c == 'X')
			*h = 3;
	}
	while (ft_strchr(*mas, '#'))
		*mas = ft_cut(*mas, '#');
	free(m);
}

char				*ft_suns(unsigned long long i, char *m, char c, size_t h)
{
	if (c == 'o')
		return (ft_int(ft_unsigned((unsigned long long)i, 8, 0), m, h));
	if (c == 'x')
		return (ft_int(ft_unsigned((unsigned long long)i, 16, 32), m, h));
	if (c == 'X')
		return (ft_int(ft_unsigned((unsigned long long)i, 16, 0), m, h));
	if (ft_strchr("uUdi", c))
		return (ft_int(ft_unsigned((unsigned long long)i, 10, 0), m, h));
	return (NULL);
}

size_t				ft_res_uns(char *s, char *m, char *spez)
{
	size_t				h;

	h = ft_strlen(s);
	ft_putstr(s);
	free(s);
	free(spez);
	free(m);
	return (h);
}

size_t				ft_uns(char *m, va_list ap, char c, char *spez)
{
	unsigned long long	i;
	size_t				h;
	char				*s;

	hex(c, &m, spez, &h);
	if (ft_strchr(spez, 'z'))
		i = va_arg(ap, long long);
	else if (ft_strchr(spez, 'l') || ft_strchr(spez, 'j') || c == 'U')
		i = va_arg(ap, long long);
	else if (ft_strlen(spez) > 1 && spez[0] == 'h')
	{
		if (!(i = (unsigned char)va_arg(ap, int)))
			s = ft_strdup("0");
	}
	else if (ft_strlen(spez) == 1 && spez[0] == 'h')
		i = (unsigned short)va_arg(ap, int);
	else
		i = (unsigned)va_arg(ap, long long);
	if (i == 0 && ft_strchr(m, '.') == NULL)
		s = ft_strdup("0");
	else if (i == 0 && ft_strchr(m, '.') != NULL && m[0] == 0)
		return (ft_atoi(m));
	else
		s = ft_suns(i, m, c, h);
	return (ft_res_uns(s, m, spez));
}
