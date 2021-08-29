/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:14:24 by jormond-          #+#    #+#             */
/*   Updated: 2020/01/20 18:28:30 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_isspace(int c)
{
	if (c == '\t' || c == '\v' || c == '\n' ||
		c == ' ' || c == '\r' || c == '\f')
		return (1);
	return (0);
}