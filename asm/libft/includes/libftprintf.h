/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:39:03 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/05 18:40:38 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft.h"
# include "unixtime.h"
# include <stdarg.h>
# include <inttypes.h>
# include "header_double.h"

# define FLG_NULL	0
# define FLG_PLUS	1
# define FLG_MINUS	2
# define FLG_HASH	4
# define FLG_SPACE	8
# define FLG_ZERO	16

typedef struct	s_funtype
{
	char	flag;
	char	*(*fun)(va_list);
}				t_funtype;

typedef struct	s_funlenght
{
	char	*flag;
	char	*(*fun)(va_list ap, char c);
}				t_funlenght;

typedef struct	s_placeholder
{
	uint8_t			flags;
	int				width;
	int				precision;
	t_funlenght		length;
	t_funtype		type;
	unsigned char	sign;
}				t_placeholder;

typedef struct	s_funflags
{
	uint8_t	inint;
	char	flag;
	char	*(*fun)(char *, t_placeholder);
}				t_funflags;

int				ft_printf(const char *format, ...);

t_placeholder	new_placeholder(void);
int				placeholder_isempty(t_placeholder place);
int				placeholder_isnotempty(t_placeholder place);
char			*delete_sign(char *str);
int				set_type(t_placeholder *placeholder, const char *format);
int				set_flags(t_placeholder *placeholder, const char *format);
int				set_width(t_placeholder *placeholder, const char *format,
														va_list ap);
char			*get_width(t_placeholder place, char *ans);
int				set_precision(t_placeholder *placeholder, const char *format,
															va_list ap);
char			*get_precision(t_placeholder *place, char *ans);
int				set_length(t_placeholder *placeholder, const char *format);
char			*get_sign(t_placeholder placeholder, char *str);

t_placeholder	parse(va_list ap, const char **format);
char			*check_flag(char *str, t_placeholder *place);
char			*to_str_logic(t_placeholder place, va_list ap);
int				print_this(t_placeholder place, char *str);
char			*ft_c(va_list ap);
char			*ft_d(va_list ap);
char			*ft_s(va_list ap);
char			*ft_x(va_list ap);
char			*ft_upx(va_list ap);
char			*ft_o(va_list ap);
char			*ft_u(va_list ap);
char			*ft_b(va_list ap);
char			*ft_p(va_list ap);
char			*ft_f(va_list ap);
char			*ft_colour(va_list ap);
char			*ft_percent(va_list ap);

char			*length_l(va_list ap, char typeflag);
char			*length_ll(va_list ap, char typeflag);
char			*length_h(va_list ap, char typeflag);
char			*length_hh(va_list ap, char typeflag);
char			*length_upl(va_list ap, char typeflag);
char			*length_z(va_list ap, char typeflag);
char			*length_j(va_list ap, char typeflag);

char			*flags_zero(char *str, t_placeholder place);
char			*flags_plus(char *str, t_placeholder place);
char			*flags_space(char *str, t_placeholder place);
char			*flags_hash(char *str, t_placeholder place);
char			*flags_minus(char *str, t_placeholder place);
char			*get_flags(t_placeholder placeholder, char *str);

int				star_width(t_placeholder *placeholder, const char *format,
														va_list ap);
int				star_precision(t_placeholder *placeholder, va_list ap);

#endif
