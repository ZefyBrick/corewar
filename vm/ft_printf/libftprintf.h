/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 12:52:28 by cdubuque          #+#    #+#             */
/*   Updated: 2019/09/03 21:19:14 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct	s_print
{
	int			wh;
	int			pres;
	int			minus;
	int			plus;
	int			zero;
	int			space;
	char		sig;
}				t_print;

void			width(char *mas, size_t i, char *s);
size_t			identifier(char **s, va_list ap);
int				ft_printf(char *s, ...);
char			*ft_int(char *s, char *m, size_t h);
char			*ft_only_width(char *mas, size_t i, char *s, size_t q);
void			ft_null(size_t i, char **s, size_t z);
char			*ft_only_accur(char *mas, size_t i, char *s, size_t h);
char			*ft_width_and_accur(char *m, size_t i, char *s, int ii);
char			*ft_string(char *s, char *m);
int				ft_modul(char *mas);
char			*ft_string_accur(char *m, size_t i, char *s);
char			*ft_char(char *s, char *m);
size_t			ft_intint(char *m, va_list ap, size_t h, char *spez);
size_t			ft_uns(char *m, va_list ap, char c, char *spez);
char			*ft_znak(size_t i, char *s, size_t z, size_t ii);
size_t			ft_string_and_char(char *mas, va_list ap, char c, char *spez);
size_t			ft_colvo_uns(unsigned long long a, size_t col, size_t i);
char			*ft_putt_uns(unsigned long long n, char *s, size_t i, size_t m);
char			*ft_unsigned(unsigned long long a, size_t i, size_t m);
void			hex(char c, char **mas, char *spez, size_t *h);
char			*ft_cut(char *m, char c);
void			flags(char **s, int *h, char *mas);
void			ft_spez(char **s, char *spez);
size_t			ft_point(char *m, va_list ap, char *spez);
long long		ft_iint(char *spez, va_list ap, size_t *c);
char			*ft_minus(char *s, char *m);
char			*ft_suns(unsigned long long	i, char *m, char c, size_t h);
void			ft_hex_pref(char *mas, size_t ii);
int				ft_pred_proz(char **s);
char			*ft_while_uns(unsigned long long n, char *s, int h, size_t m);
int				ft_vhod_elem(char *s, char *d);
int				ft_while_digit(char *m);
int				ft_not_prob(char *m);
void			ft_write_ac_w(char **w, char **ac, char *m);
void			ft_write_w(char *m, char **w);
int				ft_spez_mas(char *mas, char *spez, char **s);
size_t			ft_char_pars(char *ss, va_list ap, char *mas, char *spez);
void			ft_write_svoboda(char **w, char **mas);
size_t			ft_res_uns(char *s, char *m, char *spez);
void			ft_s_read(char **s, int *k);
char			*ft_printl_inf_nan(long double f, t_print *p);
char			*ft_cld2(char *s, long double f, t_print *p, unsigned int tmp);
char			*ft_conv_ldouble(long double f, t_print *p, int i);
char			*ft_print_inf_nan(double f, t_print *p);
char			*ft_join_one(char *s);
char			*ft_ronding(char *s, int pres);
char			*ft_conv_flt2(char *s, double f, t_print *p, unsigned int tmp);
char			*ft_conv_float(double f, t_print *p, int i);
void			ft_create_struct(t_print *p);
char			*ft_str_write_push(char *dest, char *src, int push);
void			ft_pars_width_float2(char **s, t_print *p, char **str);
char			*ft_pars_width_float(char **s, t_print *p);
void			ft_space_zero_float(char **s, t_print *p);
int				ft_intlen(int nb);
int				ft_float2(int h, char *spez, va_list ap, t_print *p);
void			ft_move_i_whide(t_print *p, int *i, char *mas);
void			ft_move_i_pres(t_print *p, int *i, char *mas);
int				ft_float(char *mas, size_t h, char *spez, va_list ap);
int				ft_putstr_len(char *s);
void			ft_jf_utoa_push(char **s, unsigned int n, int push);
int				ft_ulen(unsigned int nb);

#endif
