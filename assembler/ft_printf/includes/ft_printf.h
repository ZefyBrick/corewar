/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:58:38 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/13 19:15:37 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BUFF_SIZE 64
# define MAX_LL -9223372036854775808

# include <stdarg.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

typedef struct	s_printf
{
	char		flags[5];
	char		sig;
	int			width;
	int			prec;
	int			dot;
	char		modifier[20];
	int			count_mod;
	char		specifier;
	char		hex_hash[2];
}				t_printf;

/*
**  input
*/

int				ft_printf(const char *format, ...);
int				ft_arg_reader(const char *format, int i, va_list ap);
int				distributor(va_list ap, char *buf, t_printf *p, int res);

/*
**  struct init
*/

void			parse_struct(char *buf, t_printf *p);
void			struct_init(t_printf *p);
int				width_converter(t_printf *p, char *buf, int i);
int				prec_converter(t_printf *p, char *buf, int i);
int				modif_checker(t_printf *p, char *buf, int i);

/*
**  sort arg
*/

int				sort_int(va_list ap, int buf_size, t_printf *p);
int				sort_uint(va_list ap, int buf_size, t_printf *p);
int				sort_chr(va_list ap, int buf_size, t_printf *p);
int				sort_str(va_list ap, int buf_size, t_printf *p);
int				sort_ptr(va_list ap, int buf_size, t_printf *p);
int				sort_hex(va_list ap, int buf_size, t_printf *p);
int				sort_oct(va_list ap, int buf_size, t_printf *p);
int				sort_per(t_printf *p, int buf_size);
int				sort_float(va_list ap, int buf_size, t_printf *p);
int				sort_bin(char c, int buf_size, va_list ap);
int				sort_float(va_list ap, int buf_size, t_printf *p);

/*
**  form arg
*/

void			format_str(char **s, char *tmp, int len, t_printf *p);
void			format_int(char **s, char *tmp, int len, t_printf *p);
void			format_uint(char **s, char *tmp, int len, t_printf *p);
void			format_chr(char **s, t_printf *p);
int				format_ptr(char **s, char *tmp, int len, t_printf *p);
int				format_oct(char **s, char *tmp, int len, t_printf *p);
int				format_hex(char **s, char *tmp, int len, t_printf *p);
void			format_per(char **s, t_printf *p);

/*
**  form float
*/

void			ft_float(char **s, va_list ap, t_printf *p);
char			*ft_conv_flt2(char *s, double f, t_printf *p, unsigned int tmp);
char			*ft_print_inf_nan(double f, t_printf *p);
void			ft_space_zero_float(char **s, t_printf *p);
void			ft_jf_utoa_push(char **s, unsigned int n, int push);
int				ft_ulen(unsigned int nb);
char			*ft_ronding(char *s, int pres);
char			*ft_conv_ldouble(long double f, int i, t_printf *p);
char			*ft_conv_float(double arg, int i, t_printf *p);

/*
**  form tools
*/

void			form_zero(char **s, int size, t_printf *p);
void			ft_arg_mal(char **s, int len, t_printf *p);
void			ft_push_arg(char **s, char *tmp, t_printf *p);
void			ft_push_arg2(char **s, char *tmp, int size, t_printf *p);
void			push_arg_hex_oct(char **s, char *tmp, int len, t_printf *p);
void			push_arg_int(char **s, char *tmp, int len, t_printf *p);
void			push_hash(char **s, int calibr, t_printf *p);
int				calibr_o_x(int calibr, t_printf *p);
int				push_zero(char **s, int calibr, int len, t_printf *p);
int				cut_front_zero(char **s, t_printf *p);
void			cut_zero(char **s, int len, t_printf *p);
char			*whats_hash(t_printf *p);
int				calibration_of_prec(int len, t_printf *p);
int				ft_size_modif(int len, t_printf *p);
int				ft_size_mal(int len, t_printf *p);
int				fill_plus_or_space(char **s, char *tmp,
					int calibr, t_printf *p);
void			var_sign_modif(long long *arg, t_printf *p);
void			var_unsign_modif(unsigned long long *arg, t_printf *p);
void			push_per(char **s, t_printf *p);
void			fill_hex_arg(char **s, char *tmp, int calibr, t_printf *p);
void			fill_oct_arg(char **s, char *tmp, int calibr, t_printf *p);
void			fill_int_arg(char **s, char *tmp, int calibr, t_printf *p);
void			int_modif(long long *arg, t_printf *p);

/*
**  another tools
*/

int				ft_nbrlen(unsigned long i);
int				write_arg(int len, t_printf *p);
int				write_arg_c(int len, t_printf *p);
int				write_arg_hex_oct(char *s, int size, t_printf *p);
int				write_arg_int(int len, t_printf *p);
void			ft_strdup_free(char **s, char *arg, t_printf *p);
void			ft_strsub_free(char **s, char *tmp, t_printf *p);
char			*ft_itoa_base_c(unsigned long long value, int base, char c);
void			int_len_modif(int *len, t_printf *p);
char			*ft_itoa(long long n);
int				print_z(char *buf);
int				one_percent(const char *format, int *i);
char			*fill_rep(char c);

#endif
