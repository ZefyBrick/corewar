/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:15:05 by brickon-          #+#    #+#             */
/*   Updated: 2020/02/13 22:06:59 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	ft_print_lable(WINDOW *win2)
{
	int k;

	k = 2;
	while (k < 10)
	{
		wattron(win2, COLOR_PAIR(2));
		mvwprintw(win2, k, 3, "%s", g_core[k - 2]);
		mvwprintw(win2, 8 + k, 30, "%s", g_war[k - 2]);
		wattron(win2, COLOR_PAIR(3));
		mvwprintw(win2, 8 + k, 8, "%s", g_to[k - 2]);
		wattroff(win2, COLOR_PAIR(3));
		wrefresh(win2);
		k++;
	}
}

void	init_pair_win_colors(WINDOW **win, WINDOW **win2)
{
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_WHITE);
	init_pair(7, COLOR_BLACK, COLOR_CYAN);
	init_pair(8, COLOR_BLACK, COLOR_RED);
	init_pair(9, COLOR_BLACK, COLOR_GREEN);
	init_pair(10, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(11, COLOR_BLACK, COLOR_BLACK);
	(*win) = newwin(68, 197, 0, 0);
	(*win2) = newwin(43, 55, 0, 196);
	wborder(*win, 35, 35, 35, 35, 35, 35, 35, 35);
	wborder(*win2, 35, 35, 35, 35, 35, 35, 35, 35);
}

void	ft_delay(WINDOW *win, WINDOW *win2)
{
	int c;

	c = 0;
	while (1)
	{
		c = getch();
		wrefresh(win2);
		wrefresh(win);
		if (c == 27)
			break ;
	}
}

void	lg_show(t_corewar *corewar, t_carriage ***cr, WINDOW *w1, WINDOW *w2)
{
	int		i;

	i = -1;
	while (((CW->start_cycles < CW->dump) || CW->dump < 0) && CW->col_car != 0 \
	&& (CW->cycle++ <= CW->cycles_to_die || CW->cycles_to_die < 0))
	{
		ft_print_aren(corewar, cr, w1, w2);
		wrefresh(w1);
		wrefresh(w2);
		CW->start_cycles++;
		if (CW->v30 == 1)
			ft_printf("It is now cycle %i\n", CW->start_cycles);
		while (++(CW->active_car) < CW->col_car)
			ft_cycle(cr, CW);
		if (CW->cycle == CW->cycles_to_die || CW->cycles_to_die < 0)
			ft_verification_go(CW, cr);
		CW->active_car = -1;
	}
	while (++i < CW->car_mas)
		free((*cr)[i]);
	free(*cr);
}

void	ft_show(t_player **players, t_corewar *corewar, t_carriage ***carriage)
{
	WINDOW *win;
	WINDOW *win2;

	initscr();
	noecho();
	start_color();
	init_pair_win_colors(&win, &win2);
	ft_delay(win, win2);
	ft_print_lable(win2);
	wrefresh(win);
	create_map_color(corewar);
	fill_players(players, corewar);
	lg_show(corewar, carriage, win, win2);
	ft_delay(win, win2);
	endwin();
}
