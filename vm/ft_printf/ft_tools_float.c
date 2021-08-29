/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 18:17:08 by brickon-          #+#    #+#             */
/*   Updated: 2019/09/01 18:30:14 by brickon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_ulen(unsigned int nb)
{
	int u;

	u = 1;
	while (nb / 10)
	{
		nb /= 10;
		u++;
	}
	return (u);
}

void	ft_jf_utoa_push(char **s, unsigned int n, int push)
{
	char	*str;
	int		x;
	int		lens;

	lens = ft_strlen(*s);
	x = lens + (ft_ulen(n)) - push;
	str = (char*)malloc(sizeof(char) * (x + 1));
	if (str == NULL)
		return ;
	str[x] = '\0';
	x = x - 1;
	while (n >= 10 && x >= lens)
	{
		str[x] = n % 10 + '0';
		n = n / 10;
		x--;
	}
	if (n < 10)
		str[x] = n + '0';
	str = ft_memcpy(str, *s, ft_strlen(*s));
	free(*s);
	*s = str;
}

int		ft_putstr_len(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	return (i);
}
