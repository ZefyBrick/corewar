/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_and_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:55:11 by cdubuque          #+#    #+#             */
/*   Updated: 2020/01/30 17:34:51 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

char		*ft_string_width_and_accur(char *w, char *ac, size_t i, char *s)
{
	if (*ac && ft_strstr(w, "0"))
		s = ft_string_accur(ac, ft_strlen(s), s);
	else if (ft_modul(ac) < (int)i)
		s = ft_string_accur(ac, i, s);
	if ((int)ft_strlen(s) < ft_modul(w))
		s = ft_only_width(w, ft_strlen(s), s, 0);
	return (s);
}

char		*ft_string(char *s, char *m)
{
	char	*w;
	char	*ac;

	while (m[0] == '#')
		m = ft_free_strdup(m, 1);
	ft_write_ac_w(&w, &ac, m);
	if (m[0] == '\0' || ((int)ft_strlen(s) >= ft_modul(m) && \
	ft_strchr(m, '.') == NULL))
	{
		free(ac);
		free(w);
		return (s);
	}
	else if ((ft_strchr(m, '.') == NULL) && (int)ft_strlen(s) < ft_modul(m))
		s = ft_only_width(w, ft_strlen(s), s, 0);
	else
		s = ft_string_width_and_accur(w, ac, ft_strlen(s), s);
	free(ac);
	free(w);
	return (s);
}

char		*ft_char(char *s, char *m)
{
	if (s[0] == '0')
		s[0] = '\0';
	else
	{
		s[0] = ft_atoi(s) + 0;
		s[1] = '\0';
	}
	if (m[0] == '\0')
		return (s);
	return (ft_only_width(m, 1, s, 0));
}

size_t		ft_char_pars(char *ss, va_list ap, char *mas, char *spez)
{
	int		i;

	ss = ft_itoa(va_arg(ap, int));
	if (ss[0] == '0')
	{
		ss = ft_char(ss, mas);
		write(1, ss, ft_strlen(ss) + 1);
		i = ft_strlen(ss) + 1;
	}
	else
	{
		ss = ft_char(ss, mas);
		i = ft_strlen(ss);
		ft_putstr(ss);
	}
	ss = ft_char(ss, mas);
	free(ss);
	free(mas);
	free(spez);
	return (i);
}

size_t		ft_string_and_char(char *mas, va_list ap, char c, char *spez)
{
	char	*ss;
	size_t	i;

	ss = "0";
	if (c == 'c')
		return (ft_char_pars(ss, ap, mas, spez));
	else if (c == '%')
		ss = ft_string(ft_strdup("%"), mas);
	else if (c == 's')
	{
		ss = (va_arg(ap, char *));
		if (ss == NULL)
			ss = "(null)";
		ss = (ft_string(ft_strdup(ss), mas));
	}
	ft_putstr(ss);
	i = ft_strlen(ss);
	free(ss);
	free(mas);
	free(spez);
	return (i);
}
