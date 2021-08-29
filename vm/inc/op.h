/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:06:54 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/13 22:14:40 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/

#ifndef OP_H
# define OP_H
# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				4096
# define IDX_MOD				512
# define CHAMP_MAX_SIZE			682

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		128
# define COMMENT_LENGTH			2048
# define COREWAR_EXEC_MAGIC		0xea83f3

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <ncurses.h>
# include <stdarg.h>
# include "../ft_printf/libftprintf.h"

# define CPL col_play
# define CR carriage
# define CW corewar
# define C_CAR col_car
# define CAR_MAS car_mas

typedef char	t_arg_type;

typedef struct		s_player
{
	char			*name;
	char			player_name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	int				n;
	char			*fullname;
	int				code_size;
	int				*exec_code;
	int				start;
	int				move;
	char			*dis_asm_name;
	int				now_pos;
}					t_player;

typedef struct		s_op
{
	char			*name;
	int				col_arg;
	int				cycles;
	char			*cry;
	int				dir;
}					t_op;

typedef struct		s_corewar
{
	unsigned char	*arena;
	int				col_play;
	int				col_car;
	int				plus_id;
	int				car_mas;
	int				last_player;
	int				start_cycles;
	int				col_live;
	int				cycles_to_die;
	int				col_check;
	int				active_car;
	int				dump;
	int				v30;
	int				dis_asm;
	int				cycle;
	int				aff;
	int				viz;
	int				max_n;
	int				*color_map;
}					t_corewar;

typedef	struct		s_carriage
{
	int				id;
	int				carry;
	int				op_code;
	int				cyc_live;
	int				cyc_to_op;
	int				pc;
	int				arg_types;
	int				byte_jump;
	int				registrs[REG_NUMBER + 1];
	int				move;
	char			*s;
}					t_carriage;
/*
**corewar
*/
void				ft_welcome_champions(t_player **players);
void				ft_winner(t_player **players, t_corewar *corewar);
void				ft_flags(t_corewar *corewar, char **s, int *i, int *n);
void				ft_play(t_corewar *corewar, t_player **players, int ac);
/*
**create
*/
void				ft_create_corewar(t_corewar **corewar);
void				ft_create_players(t_player ***players);
/*
**disasm
*/
void				ft_dis_write(t_player *players, int j, int fd, int op);
void				ft_dis_dir_2(char **s, t_player *players, int j, int fd);
void				ft_dis_dir_4(char **s, t_player *players, int j, int fd);
void				ft_if_dis_write(t_player *players, int now_pos, int fd);
void				ft_disassembler(t_corewar *corewar, t_player **players);

/*
**errors
*/
void				error(char *s);
void				ft_true_header(char *mh, char *mh2, char *fullname);
void				ft_code_size(t_player **players, int *mas, int i, int pos);
/*
**input_players
*/
void				ft_champions_up(char *s, int c, t_player **players, \
					char *s1);
void				ft_split_s(char **s);
void				ft_new_player_flag(char *s, int *c, t_player **players, \
					char *s1);
void				ft_new_player_c(char *s, int *c, t_player **players, \
					char *s1);
void				ft_give_number(char *s, int *c, t_player **players, int d);
/*
**validation
*/
void				ft_check_name(t_player **players, int *mas, int i,
					int pos);
void				ft_all_header(char **mh2, int *mas);
void				ft_check_magic_header(t_player **players, int *mas);
void				ft_check_file(t_player **players, int *mas, int i);
void				ft_validation(t_player **players);
/*
**validation_2
*/
int					ft_degree_16(int j);
int					ft_in_ten(char *s);
void				ft_exec_code(t_player **players, int *mas, int i, int pos);
void				ft_champion_comment(t_player **players, int *mas, int i,
					int pos);
/*
**arena
*/
void				ft_arena_exec_code(t_player **players, t_corewar *corewar);
void				ft_first_carriages(t_carriage **carriage, \
					t_player **players, t_corewar *corewar, int c);
void				ft_carriege_init(t_carriage ***carriege, \
					t_player **players, t_corewar *corewar);
void				ft_arena(t_player **players, t_corewar *corewar);
/*
**operations
*/
void				ft_wrong_ar_types(t_carriage *carriage, \
					t_corewar *corewar, int ar_types, int i);
void				ft_operations(t_carriage ***carriege, t_corewar *corewar);
void				ft_operations2(t_carriage ***carriage, t_corewar *corewar);
/*
**operations_code_1
*/
void				ft_live(t_carriage *carriege, t_corewar *corewar);
void				ft_ld_and_lld(t_carriage *carriege, t_corewar *corewar);
void				ft_st(t_carriage *carriege, t_corewar *corewar);
void				ft_st2(t_carriage *carriage, t_corewar *corewar,
					int a, int b);
void				ft_add_and_sub(t_carriage *carriege, t_corewar *corewar);
/*
**operations_code_2
*/
void				ft_reg_for_and_or_xor(t_carriage *carriage, int *d);
void				ft_and_or_xor(t_carriage *carriege, t_corewar *corewar);
void				ft_zjmp(t_carriage *carriege, t_corewar *corewar);
void				ft_v_30_ldi_lldi(t_carriage *carriage, t_corewar *corewar,
					int *d);
void				ft_ldi_and_lldi(t_carriage *carriege, t_corewar *corewar);
/*
**operations_code_3
*/
void				ft_sti(t_carriage *carriege, t_corewar *corewar);
void				ft_sti2(t_carriage *carriage, int *d);
void				ft_fork_and_lfork(t_carriage ***carriege, \
					t_corewar *corewar);
void				ft_aff(t_carriage *carriege, t_corewar *corewar);
/*
**operations_code_4
*/
int					ft_ind(t_carriage *carriege, t_corewar *corewar);
int					ft_dir(t_carriage *carriege, t_corewar *corewar);
int					ft_reg(t_carriage *carriege, t_corewar *corewar);
int					ft_op_code(int par, int i);
int					ft_argument(int par, t_carriage *carriege, \
					t_corewar *corewar, int i);
/*
**lets_go_war
*/
void				ft_create_new_car(t_carriage *carriage);
void				ft_kill_car(t_carriage ***carriage, int *i, \
					t_corewar *corewar);
void				ft_verification_go(t_corewar *corewar, \
					t_carriage ***carriage);
void				ft_cycle(t_carriage ***carriage, t_corewar *corewar);
void				ft_lets_go_war(t_corewar *corewar, \
					t_carriage ***carriege);
/*
**tools
*/
void				ft_new_car(t_carriage ***carriage, t_corewar *corewar, \
					int d, int c);
void				ft_copy_car(t_carriage ***carrage, t_corewar *corewar, \
					int d);
int					ft_limit(int d);
void				ft_reg_value(int *d, int regs, int ar_types, \
					t_carriage *carriage);
void				ft_carry(t_carriage *carriage, int i);
/*
**tools2
*/
int					ft_record_from_arena(int d, t_corewar *corewar);
void				ft_record_to_arena(t_corewar *corewar, int c, int d,
					int color);
void				ft_what_arguments(int *d, t_carriage *carriage, \
					t_corewar *corewar, int c);
void				ft_v30(t_corewar *corewar, t_carriage *carriage, int max);
int					ft_check_reg(int arg, int regs, int *d);
/*
**tools3.c
*/
void				ft_header_disasm(t_player *players, int fd);
void				ft_record_short(t_corewar *corewar, t_carriage *carriage,
					short *zn);
void				ft_print_map(t_corewar *corewar);
void				ft_move_car(t_carriage *carriage, t_carriage *carriage_1);
void				ft_strcut(char **s, char *d, int c);
/*
** viz
*/

void				ft_print_lable(WINDOW *win2);
void				init_pair_win_colors(WINDOW **win, WINDOW **win2);
void				ft_delay(WINDOW *win, WINDOW *win2);
void				lg_show(t_corewar *corewar, t_carriage ***cr, WINDOW *w1,
					WINDOW *w2);
void				ft_show(t_player **players, t_corewar *corewar,
					t_carriage ***carriage);

/*
** viz_2
*/

void				print_info(t_corewar *corewar, WINDOW *win2);
void				ft_print_aren(t_corewar *cw, t_carriage ***car, WINDOW *w1,
					WINDOW *w2);
int					ft_check_car(t_corewar *cw, t_carriage ***car, int i);
void				create_map_color(t_corewar *corewar);
void				fill_players(t_player **players, t_corewar *corewar);

extern	const t_op	g_op_tab[16];
extern const char	g_core[8][27];
extern const char	g_war[8][27];
extern const char	g_to[8][27];

#endif
