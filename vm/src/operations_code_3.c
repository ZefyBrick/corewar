/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_code_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:04:52 by cdubuque          #+#    #+#             */
/*   Updated: 2020/02/14 15:00:22 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		ft_sti(t_carriage *carriage, t_corewar *corewar)
{
	int		d[4];

	d[3] = 0;
	ft_what_arguments(d, CR, CW, 3);
	if (!(ft_check_reg(CW->arena[CR->arg_types], 7, d))
	&& (CW->arena[CR->arg_types] & 192) == 64
	&& (CW->arena[CR->arg_types] & 48) != 0
	&& ((CW->arena[CR->arg_types] & 12) == 4
	|| (CW->arena[CR->arg_types] & 12) == 8))
	{
		ft_reg_value(d, 3, CW->arena[CR->arg_types], CR);
		if ((CW->arena[CR->arg_types] & 48) == 48)
			d[1] = ft_record_from_arena(CR->pc + d[1], CW);
		d[3] = CR->pc + (d[1] + d[2]) % IDX_MOD;
		if (CW->v30 == 1)
			ft_sti2(carriage, d);
		ft_record_to_arena(CW, d[3], CR->registrs[d[0]],
		abs(CR->registrs[REG_NUMBER]));
		if (CW->v30 == 1)
			ft_v30(CW, CR, CR->move);
		CR->pc = ft_limit(CR->pc + CR->move);
	}
	else
		ft_wrong_ar_types(CR, corewar, CW->arena[CR->arg_types], 3);
}

void		ft_sti2(t_carriage *carriage, int *d)
{
	ft_printf("P %4i | sti r%i %i %i\n", CR->id, d[0] + 1, d[1], d[2]);
	ft_printf("%20s %i + %i = %i (with pc and mod %i)\n", \
	"| -> store to", d[1], d[2], d[1] + d[2], d[3]);
}

void		ft_fork_and_lfork(t_carriage ***carriage, t_corewar *corewar)
{
	short		d[2];
	int			d2[2];

	d[0] = ft_dir((*CR)[CW->active_car], CW);
	d[1] = d[0];
	if ((*CR)[CW->active_car]->op_code == 12)
		d[0] %= IDX_MOD;
	d2[0] = (*CR)[CW->active_car]->pc + d[0];
	d2[1] = ft_limit(d2[0]);
	ft_copy_car(CR, CW, d2[1]);
	(CW->active_car)++;
	if (CW->v30 == 1)
	{
		ft_printf("P %4i | %s %hd (%i)\n", \
		(*CR)[CW->active_car]->id,
		g_op_tab[(*CR)[CW->active_car]->op_code - 1].name, d[1], d2[0]);
		ft_v30(CW, (*CR)[CW->active_car], 3);
	}
	(*CR)[CW->active_car]->pc = ft_limit((*CR)[CW->active_car]->pc + 3);
	CW->col_car++;
}

void		ft_aff(t_carriage *carriage, t_corewar *corewar)
{
	int		d;

	d = ft_argument(CW->arena[ft_limit(CR->pc + 1)], CR, CW, 0);
	if ((CW->arena[CR->arg_types] & 192) == 64
	&& d < REG_NUMBER && d >= 0)
	{
		if (CW->v30 == 1 || CW->aff == 1)
		{
			ft_printf("Aff: %c\n", ((char)(CR->registrs[d] % 256)));
			ft_v30(CW, CR, 3);
		}
		CR->pc = ft_limit(CR->pc + 3);
	}
	else
		ft_wrong_ar_types(CR, CW, CW->arena[CR->arg_types], 1);
}
