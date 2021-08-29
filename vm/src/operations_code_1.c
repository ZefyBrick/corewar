/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_code_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:12:26 by cdubuque          #+#    #+#             */
/*   Updated: 2020/02/13 21:22:52 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		ft_live(t_carriage *carriage, t_corewar *corewar)
{
	int		d;

	d = ft_record_from_arena(CR->pc + 1, CW);
	if (CW->v30 == 1)
	{
		ft_printf("P %4i | live %i\n", CR->id, d);
		ft_v30(CW, CR, 5);
	}
	if (d < 0)
	{
		d = ft_modul_int(d);
		if (d <= CW->col_play)
			CW->last_player = d;
	}
	CW->col_live++;
	CR->cyc_live = CW->start_cycles;
	CR->pc = ft_limit(CR->pc + 5);
}

void		ft_ld_and_lld(t_carriage *carriage, t_corewar *corewar)
{
	int		d[2];

	ft_what_arguments(d, CR, CW, 2);
	if (((corewar->arena[carriage->arg_types] & 192) == 192 ||
	(corewar->arena[carriage->arg_types] & 192) == 128) && \
	(corewar->arena[carriage->arg_types] & 48) == 16 && d[1] >= 0
	&& d[1] < REG_NUMBER)
	{
		if ((corewar->arena[carriage->arg_types] & 192) == 192)
			d[0] = ft_record_from_arena(CR->pc + d[0], CW);
		if (CW->v30 == 1)
		{
			ft_printf("P %4i | %s %i r%i\n", CR->id, \
			g_op_tab[CR->op_code - 1].name, d[0], d[1] + 1);
			ft_v30(CW, CR, CR->move);
		}
		CR->pc = ft_limit(CR->pc + CR->move);
		CR->registrs[d[1]] = d[0];
		ft_carry(CR, d[1]);
	}
	else
		ft_wrong_ar_types(carriage, corewar,
		corewar->arena[carriage->arg_types], 2);
}

void		ft_st(t_carriage *carriage, t_corewar *corewar)
{
	int		d[2];

	ft_what_arguments(d, CR, CW, 2);
	if ((CW->arena[CR->arg_types] & 192) == 64
	&& ((CW->arena[CR->arg_types] & 48) == 16
	|| (CW->arena[CR->arg_types] & 48) == 48)
	&& !(ft_check_reg(CW->arena[CR->arg_types], 6, d)))
	{
		if ((CW->arena[CR->arg_types] & 48) == 48)
			ft_st2(carriage, corewar, d[0], d[1]);
		else
		{
			if (CW->v30 == 1)
				ft_printf("P %4i | st r%i %i\n", CR->id, d[0] + 1, d[1] + 1);
			CR->registrs[d[1]] = CR->registrs[d[0]];
		}
		if (CW->v30 == 1)
			ft_v30(CW, CR, CR->move);
		CR->pc = ft_limit(CR->pc + CR->move);
	}
	else
		ft_wrong_ar_types(CR, CW, CW->arena[carriage->arg_types], 2);
}

void		ft_st2(t_carriage *carriage, t_corewar *corewar, int a, int b)
{
	if (CW->v30 == 1)
		ft_printf("P %4i | st r%i %i\n", CR->id, a + 1, b);
	b = b % IDX_MOD;
	ft_record_to_arena(CW, CR->pc + b, CR->registrs[a],
	abs(CR->registrs[REG_NUMBER]));
}

void		ft_add_and_sub(t_carriage *carriage, t_corewar *corewar)
{
	int		d[3];

	ft_what_arguments(d, CR, CW, 3);
	if ((corewar->arena[carriage->arg_types] & 192) == 64
	&& (corewar->arena[carriage->arg_types] & 48) == 16
	&& (corewar->arena[carriage->arg_types] & 12) == 4
	&& !(ft_check_reg(corewar->arena[carriage->arg_types], 7, d)))
	{
		if (CW->v30 == 1)
			ft_printf("P %4i | %s r%i r%i r%i\n", CR->id, \
			g_op_tab[CR->op_code - 1].name, d[0] + 1, d[1] + 1, d[2] + 1);
		ft_reg_value(d, 6, corewar->arena[carriage->arg_types], CR);
		if (CR->op_code == 4)
			CR->registrs[d[2]] = d[0] + d[1];
		else
			CR->registrs[d[2]] = d[0] - d[1];
		if (CW->v30 == 1)
			ft_v30(CW, CR, CR->move);
		ft_carry(CR, d[2]);
		CR->pc = ft_limit(CR->pc + CR->move);
	}
	else
		ft_wrong_ar_types(CR, CW, corewar->arena[carriage->arg_types], 3);
}
