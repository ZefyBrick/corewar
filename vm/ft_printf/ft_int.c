/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:55:57 by cdubuque          #+#    #+#             */
/*   Updated: 2019/09/04 16:00:03 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*ft_only_accur(char *mas, size_t i, char *s, size_t h)
{
	int			r;
	char		*res;
	char		*m;

	m = ft_strdup(mas);
	if (ft_strlen(s) == 0 && h == 5)
	{
		free(m);
		return (ft_znak(0, s, 0, h));
	}
	r = ft_modul(m) - i;
	if (h == 5)
		r -= 1;
	if (r > 0)
	{
		free(m);
		m = ft_strnew(r);
		while (r--)
			m[r] = '0';
		res = ft_second_free_join(m, s);
	}
	else
		res = ft_strdup(s);
	free(m);
	return (res);
}

void			ft_null(size_t i, char **s, size_t z)
{
	char		*mas;

	mas = ft_strnew(i);
	if (i > 0)
	{
		mas[i] = '\0';
		if (z == 2)
		{
			while (i--)
				mas[i] = '0';
			*s = ft_second_free_join(mas, *s);
		}
		else
		{
			while (i--)
				mas[i] = ' ';
			if (z == 1)
				ft_first_free_join(&(*s), mas);
			else
				*s = ft_second_free_join(mas, *s);
		}
	}
	free(mas);
}

void			ft_hex_pref(char *mas, size_t ii)
{
	size_t		k;

	k = 0;
	if (ii == 2)
		mas[k++] = '+';
	else if (ii == 4 || ii == 3)
	{
		mas[k++] = '0';
		if (ii == 3)
			mas[k++] = 'X';
		else
			mas[k++] = 'x';
	}
	else if (ii == 5)
		mas[k++] = '0';
	mas[k] = '\0';
}

char			*ft_znak(size_t i, char *s, size_t z, size_t ii)
{
	char		*mas;

	mas = ft_strnew(3);
	if (ii > 1)
		ft_hex_pref(mas, ii);
	if (ft_strlen(mas) > 0 && ft_strlen(s) == 0)
		return (mas);
	if (ft_strlen(mas) > 0 && z != 2)
		s = ft_second_free_join(mas, s);
	if ((int)(i - ft_strlen(mas)) > 0)
		ft_null(i - ft_strlen(mas), &s, z);
	else
		ft_null(0, &s, z);
	if (ft_strlen(mas) > 0 && z == 2)
		s = ft_second_free_join(mas, s);
	if (ii == 1)
		s = ft_second_free_join(" ", s);
	free(mas);
	return (s);
}

char			*ft_only_width(char *mas, size_t i, char *s, size_t q)
{
	size_t		k;
	size_t		z;
	char		*tmp;

	z = 0;
	tmp = mas;
	while (*mas == '0' || *mas == '-')
	{
		if (*mas == '0' && z != 1)
			z = 2;
		if (*mas == '-')
			z = 1;
		mas += 1;
	}
	k = ft_atoi(mas);
	if (q == 1)
		i += 1;
	mas = tmp;
	if ((ft_strlen(s) == 0 && k == 0 && q == 5) || (k <= i && s[0] != '\0'))
		return (ft_znak(0, s, 0, q));
	if (k <= i)
		return (s);
	if (k > i)
		return (ft_znak(k - i, s, z, q));
	return (0);
}
