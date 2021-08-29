/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:03:47 by cdubuque          #+#    #+#             */
/*   Updated: 2020/02/13 23:00:55 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		ft_arena_exec_code(t_player **players, t_corewar *corewar)
{
	int		c;
	int		i;

	c = -1;
	while (++c < CW->CPL)
	{
		i = -1;
		while (++i < players[c]->code_size)
			corewar->arena[players[c]->start + i] = \
			(unsigned char)players[c]->exec_code[i];
	}
}

void		ft_first_carriages(t_carriage **carriage, t_player **players,
t_corewar *corewar, int c)
{
	int		i;

	if (!((*carriage) = (t_carriage *)malloc(sizeof(t_carriage))))
		exit(0);
	(*carriage)->id = CW->CPL - c;
	(*carriage)->carry = 0;
	(*carriage)->op_code = 0;
	(*carriage)->cyc_live = 0;
	(*carriage)->pc = players[CW->CPL - c - 1]->start;
	(*carriage)->arg_types = (*carriage)->pc + 1;
	(*carriage)->byte_jump = -1;
	(*carriage)->registrs[0] = c - CW->CPL;
	(*carriage)->registrs[REG_NUMBER] = c - CW->CPL;
	(*carriage)->cyc_to_op = 0;
	(*carriage)->move = 1;
	i = 0;
	while (++i < REG_NUMBER)
		(*carriage)->registrs[i] = 0;
}

void		ft_carriage_init(t_carriage ***carriage, t_player **players, \
t_corewar *corewar)
{
	int		c;

	c = -1;
	if (!((*carriage) = (t_carriage **)malloc(sizeof(t_carriage *) * CW->CPL)))
		exit(0);
	while (++c < CW->CPL)
		ft_first_carriages(&(*carriage)[c], players, corewar, c);
	CW->C_CAR = CW->CPL;
	corewar->car_mas = CW->CPL;
	corewar->plus_id = CW->C_CAR;
}

void		ft_arena(t_player **players, t_corewar *corewar)
{
	int			i;
	int			c;
	t_carriage	**carriage;

	i = -1;
	c = -1;
	if (!(CW->arena = (unsigned char *)malloc(sizeof(unsigned char) \
	* MEM_SIZE)))
		exit(0);
	while (++i < MEM_SIZE)
		(CW)->arena[i] = 0;
	while (++c < MAX_PLAYERS && players[c]->name != NULL)
		;
	CW->CPL = c;
	c = 0;
	while (++c < CW->CPL)
		players[c]->start = players[c - 1]->start + MEM_SIZE / CW->CPL;
	ft_arena_exec_code(players, CW);
	ft_carriage_init(&carriage, players, CW);
	if (corewar->viz == 0)
		ft_lets_go_war(corewar, &carriage);
	else
		ft_show(players, corewar, &carriage);
}
