/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 21:44:55 by cdubuque          #+#    #+#             */
/*   Updated: 2019/08/14 21:50:30 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_modul(char *mas)
{
	int		i;

	i = ft_atoi(mas);
	if (i > 0)
		return (i);
	else
		return (-i);
}
