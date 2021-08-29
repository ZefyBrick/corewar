/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickon- <brickon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:54:51 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/13 21:06:56 by brickon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	print_info(t_corewar *corewar, WINDOW *win2)
{
	wattron(win2, COLOR_PAIR(11));
	mvwprintw(win2, 27, 3, "Cycles total :               ");
	mvwprintw(win2, 28, 3, "Carriages total :                ");
	mvwprintw(win2, 29, 3, "cycles_to_die :                 ");
	wattron(win2, COLOR_PAIR(1));
	mvwprintw(win2, 27, 3, "Cycles total : %d", corewar->start_cycles);
	mvwprintw(win2, 28, 3, "Carriages total : %d", corewar->col_car);
	mvwprintw(win2, 29, 3, "cycles_to_die : %d", corewar->cycles_to_die);
	wattron(win2, COLOR_PAIR(corewar->last_player + 1));
	mvwprintw(win2, 30, 3, "WINNER");
}

void	ft_print_aren(t_corewar *cw, t_carriage ***car, WINDOW *w1, WINDOW *w2)
{
	int	i;
	int	k;
	int	j;

	i = -1;
	j = 2;
	k = 3;
	while (++i < MEM_SIZE)
	{
		if (i % 64 == 0 && i >= 64)
		{
			k = 3;
			j++;
		}
		wattron(w1, COLOR_PAIR(cw->color_map[i]));
		mvwprintw(w1, j, k, "%.2x", cw->arena[i]);
		if (ft_check_car(cw, car, i))
		{
			wattron(w1, COLOR_PAIR(cw->color_map[i] + 5));
			mvwprintw(w1, j, k, "%.2x", cw->arena[i]);
		}
		k += 3;
		print_info(cw, w2);
	}
}

int		ft_check_car(t_corewar *cw, t_carriage ***car, int i)
{
	int num_car;

	num_car = -1;
	while (++num_car != cw->col_car)
	{
		if ((*car)[num_car]->pc == i)
			return (1);
	}
	return (0);
}

void	create_map_color(t_corewar *corewar)
{
	int i;

	i = -1;
	corewar->color_map = (int *)malloc(sizeof(int) * MEM_SIZE);
	while (++i < MEM_SIZE)
		corewar->color_map[i] = 1;
}

void	fill_players(t_player **players, t_corewar *corewar)
{
	int		c;
	int		i;

	c = -1;
	while (++c < CW->CPL)
	{
		i = -1;
		while (++i < players[c]->code_size)
			corewar->color_map[players[c]->start + i] = c + 2;
	}
}
