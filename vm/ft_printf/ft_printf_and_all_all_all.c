/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_and_all_all_all.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 12:11:31 by cdubuque          #+#    #+#             */
/*   Updated: 2019/09/01 12:16:17 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void					flags(char **s, int *h, char *mas)
{
	while (!(ft_strchr("jzhplLcsidpoUuxXf%", **s)))
	{
		if (**s == ' ' && *h == 0)
			*h = 1;
		else if (**s == '+')
			*h = 2;
		if (**s != '+')
		{
			*mas = **s;
			mas += 1;
		}
		*s = *s + 1;
	}
	*mas = '\0';
}

void					ft_spez(char **s, char *spez)
{
	while (!(ft_strchr("cspidpouUxXf%", **s)))
	{
		*spez = **s;
		*s = *s + 1;
		spez = spez + 1;
	}
	*spez = '\0';
}

char					*ft_string_accur(char *m, size_t i, char *s)
{
	int		id;

	while (*m == ' ')
		m = ft_free_strdup(m, 1);
	id = ft_atoi(m);
	if (id < (int)i && id != 0)
		s = ft_free_sub(s, 0, id);
	else if (id == 0 && s[0] != '%')
	{
		free(s);
		s = ft_strdup("\0");
	}
	return (s);
}
