/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revers_bytes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:45:16 by cdubuque          #+#    #+#             */
/*   Updated: 2020/02/13 21:09:50 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_revers_bytes(int i, int r)
{
	unsigned int	c;

	c = (unsigned int)i;
	if (r == 4)
		c = ((c & 0xff000000) >> 24) | ((c & 0x000000ff) << 24) \
		| ((c & 0x0000ff00) << 8) | ((c & 0x00ff0000) >> 8);
	else
		c = (((unsigned short)c & 0x00ff) << 8) \
		| (((unsigned short)c & 0xff00) >> 8);
	return (c);
}
