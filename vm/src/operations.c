/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:59:24 by cdubuque          #+#    #+#             */
/*   Updated: 2020/02/13 21:57:59 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		ft_wrong_ar_types(t_carriage *carriage, t_corewar *corewar, \
int ar_types, int i)
{
	int		d;
	int		n;

	d = -1;
	n = 0;
	CR->move = 1;
	while (++d < i)
	{
		n = ar_types & 192;
		n = n >> 6;
		if (n == 1)
			CR->move += 1;
		else if (n == 2)
			CR->move += g_op_tab[CR->op_code - 1].dir;
		else if (n == 3)
			CR->move += 2;
		ar_types = ar_types << 2;
	}
	if (CW->v30 == 1)
		ft_v30(CW, CR, CR->move + 1);
	CR->pc = ft_limit(CR->pc + CR->move + 1);
}

void		ft_operations(t_carriage ***carriage, t_corewar *corewar)
{
	if ((*CR)[CW->active_car]->op_code == 1)
		ft_live((*CR)[CW->active_car], CW);
	else if ((*CR)[CW->active_car]->op_code == 2
	|| (*CR)[CW->active_car]->op_code == 13)
		ft_ld_and_lld((*CR)[CW->active_car], CW);
	else if ((*CR)[CW->active_car]->op_code == 3)
		ft_st((*CR)[CW->active_car], CW);
	else if ((*CR)[CW->active_car]->op_code == 4
	|| (*CR)[CW->active_car]->op_code == 5)
		ft_add_and_sub((*CR)[CW->active_car], CW);
	else if ((*CR)[CW->active_car]->op_code > 5
	&& (*CR)[CW->active_car]->op_code < 9)
		ft_and_or_xor((*CR)[CW->active_car], CW);
	else
		ft_operations2(carriage, corewar);
	(*CR)[CW->active_car]->arg_types =
	ft_limit((*CR)[CW->active_car]->pc + 1);
	(*CR)[CW->active_car]->cyc_to_op = 0;
	(*CR)[CW->active_car]->move = 1;
}

void		ft_operations2(t_carriage ***carriage, t_corewar *corewar)
{
	if ((*CR)[CW->active_car]->op_code == 9)
		ft_zjmp((*CR)[CW->active_car], CW);
	else if ((*CR)[CW->active_car]->op_code == 10
	|| (*CR)[CW->active_car]->op_code == 14)
		ft_ldi_and_lldi((*CR)[CW->active_car], CW);
	else if ((*CR)[CW->active_car]->op_code == 11)
		ft_sti((*CR)[CW->active_car], CW);
	else if ((*CR)[CW->active_car]->op_code == 12
	|| (*CR)[CW->active_car]->op_code == 15)
		ft_fork_and_lfork(CR, CW);
	else if ((*CR)[CW->active_car]->op_code == 16)
		ft_aff((*CR)[CW->active_car], CW);
}
