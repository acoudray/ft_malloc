/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachena <gmachena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:43:55 by gmachena          #+#    #+#             */
/*   Updated: 2020/02/21 16:38:30 by gmachena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <inttypes.h>
# include <stdarg.h>
# include "libft.h"

/*
**  FLAGS MACRO
*/

# define DIESE 1
# define ZERO 2
# define MINUS 4
# define PLUS 8
# define BLANK 16

/*
** SIZE MACRO
*/

# define H 1
# define HH 2
# define L 3
# define LL 4
# define J 5

# define LLONG long long
# define ULL unsigned long long int
# define UCHAR unsigned char
# define USHORT unsigned short
# define ULONG unsigned long

/*
****************************** STRUCT F_ID *******************************
*/

typedef struct			s_flags
{
	int					diese;
	int					zero;
	int					minus;
	int					plus;
	int					blank;
}						t_flags;

typedef struct			s_fid
{
	t_flags				flags;
	int					min_width;
	int					max_width;
	int					size;
	char				f_id;
	int					arg_count;
	int					len_fid;
	int					pos_fid;
	int					is_prec;
}						t_fid;

int						ft_printf(const char *format, ...);

/*
************************ FLAGS DETECTOR ANNEXE ***************************
*/

/*
** flag recognize dir
*/

int						fl_dir(char *str, int i);
char					patt_dir(char *str, int i);

/*
** flag recognize preci
*/

double					fl_preci_number(char *str, int i);
char					fl_preci_wildcard(char *str, int i);

/*
** flag recognize size
*/

char					*fl_size(char *str, int i);

int						is_flag(char *str, int i);
int						is_width(char *str, int i);
int						sz_preci(char *str, int i);
int						sz_length(char *str, int i);
int						is_type(char *str, int i);

int						ft_print_zero(int n);
int						ft_print_space(int n);
int						ft_putnstr(const char *str, int n, int start);
int						ft_print_diese(t_fid fid);

int						ft_apply_color(char *format);
int						ft_colors_1(char *format);
int						ft_colors_2(char *format);

int						ft_printd(char *i, t_fid fid);
int						ft_print(t_fid *fid, va_list va, char *format, int n);
int						ft_dispatcher(t_fid fid, va_list va);
int						ft_get_d_size(char *i, t_fid fid, int size);
int						ft_fill_arg_d(char *i, int size, int max, t_fid fid);

int						ft_dispatchf(t_fid fid, va_list va);
int						ft_dispatchc(t_fid fid, va_list va);
int						ft_dispatchd(t_fid fid, va_list va);

char					*ft_itoa_printf(intmax_t nbr, t_fid fid);
char					*ft_itoa_base_printf(uintmax_t nbr, t_fid fid,
							int base);
char					*ft_ftoa_printf(double nbr);

int						ft_fill_flags(char *format, t_fid *fid, int pos);
int						ft_fill_width(char *format, t_fid *fid, int pos);
int						ft_fill_precision(char *format, t_fid *fid, int pos);
int						ft_fill_length(char *format, t_fid *fid, int pos);
int						ft_fill_type(char *format, t_fid *fid, int pos);
int						ft_count_fid(char *str);
/*
*******************************TOOLS**************************************
*/
int						exit_error(char *str);
int						ft_print_flags_f(t_fid fid, char **str);
#endif
