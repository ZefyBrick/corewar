/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:03:53 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/10 20:20:49 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			champ_code(t_cw *corewar, int out, t_ls *list)
{
	uint8_t		type;
	char		c;

	type = 0;
	c = list->label;
	corewar->dir = dir_size(list);
	list->instrbytes += codetype(list) + 1;
	corewar->bytes += list->instrbytes;
	write(out, &c, 1);
	if (list->instrbytes == 2)
	{
		arg_types_fill(corewar, list, &type);
		c = type;
		write(out, &c, 1);
	}
}

void			arg_types_fill(t_cw *corewar, t_ls *list, uint8_t *type)
{
	t_ls		*tmp;
	int			args;

	tmp = list->next;
	args = g_asm_tab[list->label].arg_num;
	corewar->iter = 0;
	while (args--)
	{
		if (tmp->label == REGISTER)
			reg_fill(corewar, type);
		else if (tmp->label == DIRECT || tmp->label == DIRECT_LABEL)
			dir_fill(corewar, type);
		else if (tmp->label == INDIRECTION || tmp->label == INDIRECT_LABEL)
			ind_fill(corewar, type);
		corewar->iter++;
		tmp = tmp->next;
	}
}

void			reg_fill(t_cw *corewar, uint8_t *type)
{
	if (corewar->iter == 0)
		(*type) |= 64;
	else if (corewar->iter == 1)
		(*type) |= 16;
	else if (corewar->iter == 2)
		(*type) |= 4;
}

void			dir_fill(t_cw *corewar, uint8_t *type)
{
	if (corewar->iter == 0)
		(*type) |= 128;
	else if (corewar->iter == 1)
		(*type) |= 32;
	else if (corewar->iter == 2)
		(*type) |= 8;
}

void			ind_fill(t_cw *corewar, uint8_t *type)
{
	if (corewar->iter == 0)
		(*type) |= 192;
	else if (corewar->iter == 1)
		(*type) |= 48;
	else if (corewar->iter == 2)
		(*type) |= 12;
}
