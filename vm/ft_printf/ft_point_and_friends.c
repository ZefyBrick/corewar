/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_and_friends.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 11:26:13 by cdubuque          #+#    #+#             */
/*   Updated: 2019/09/03 22:04:39 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t				ft_point(char *m, va_list ap, char *spez)
{
	unsigned long long	i;
	char				*s;
	int					j;

	i = (unsigned long long)va_arg(ap, void *);
	if (i == 0 && ft_strchr(m, '.') && \
		ft_atoi(ft_strchr(m, '.') + 1) == 0 && (m[0] == '.' || m[0] == '0'))
	{
		ft_putstr("0x");
		free(m);
		return (2);
	}
	s = ft_unsigned((unsigned long long)i, 16, 32);
	if (ft_strchr(m, '.'))
		s = ft_int(s, m, 4);
	if ((!(ft_strchr(m, '.'))) && m[0] != '\0')
		s = (ft_only_width(m, ft_strlen(s), s, 4));
	if (ft_strlen(m) == 0)
		s = ft_second_free_join("0x", s);
	ft_putstr(s);
	j = (int)ft_strlen(s);
	free(s);
	free(spez);
	free(m);
	return (j);
}

int					ft_spez_mas(char *mas, char *spez, char **s)
{
	int			h;

	h = 0;
	if (*mas != '\0')
	{
		if (ft_not_prob(mas) == 0 && *spez == '\0')
			ft_first_free_join(&mas, *s);
		while (*mas == ' ')
			mas = ft_free_strdup(mas, 1);
		ft_putstr(mas);
		h = ft_strlen(mas);
	}
	if (*spez != '\0')
	{
		while (ft_strchr("hlLjz", *spez) && *spez != '\0')
			spez = ft_free_strdup(spez, 1);
		ft_putstr(spez);
		h = ft_strlen(spez);
	}
	free(mas);
	free(spez);
	return (h);
}

void				ft_write_svoboda(char **w, char **mas)
{
	if (**mas == '0')
	{
		while (*((*mas) + 1) == '0')
			*mas = ft_free_strdup(*mas, 1);
		if (ft_isdigit(*((*mas) + 1)))
		{
			free(*w);
			*mas = ft_free_strdup(*mas, 1);
			*w = ft_second_free_join("0", ft_itoa(ft_atoi(*mas)));
			*mas = ft_free_strdup(*mas, ft_strlen(*w) - 1);
		}
		else
			*mas = ft_free_strdup(*mas, 1);
	}
	else
	{
		free(*w);
		*w = ft_itoa(ft_atoi(*mas));
		*mas = ft_free_strdup(*mas, ft_strlen(*w));
	}
}

void				ft_write_w(char *m, char **w)
{
	char	*mas;

	mas = ft_strdup(m);
	while (*mas)
	{
		if (ft_isdigit(*mas) || (*mas == '-' && ft_isdigit((mas[1]))))
			ft_write_svoboda(&(*w), &mas);
		if (!(ft_isdigit(*mas)) && *mas)
		{
			if (*mas == '.')
			{
				while (*mas == '.' || ft_isdigit(*mas))
					mas = ft_free_strdup(mas, 1);
			}
			else
				mas = ft_free_strdup(mas, 1);
		}
	}
	free(mas);
}
