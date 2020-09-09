/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_double.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:56:32 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/02/05 19:05:25 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_DOUBLE_H
# define HEADER_DOUBLE_H

# include "libft.h"
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# define BASE 10000

typedef	long double				t_ldouble;

typedef	unsigned long long int	t_ullint;

typedef struct					s_double
{
	t_ullint					mantisa;
	int							order;
	int							sign;
}								t_double;

typedef struct					s_bigdbl
{
	t_ullint					size;
	t_ullint					sizemax;
	short						*coef;
}								t_bigdbl;
t_bigdbl						ft_mul_la(t_bigdbl a, short b);
t_bigdbl						ft_pow_la(t_bigdbl a, int count, int dig);
t_bigdbl						ft_sum_la(t_bigdbl a, t_bigdbl b,
														unsigned long i);
int								ft_intlen(long long nbr);
char							*ft_add_d(t_ldouble a, int i, int *len,
																char *str);
t_bigdbl						ft_to_the_point(t_double val);
t_bigdbl						ft_new_la(unsigned int nbr);
t_double						ft_defldbl(long double *n);
char							*ft_revstr(char *str);
char							*ft_get_d(long double n);
char							*get_mantiss(long double n,
											char *str_n, int count_digits);
int								ft_count_digits_mantiss(long double n);
int								ft_count_digits(long double n);
int								ft_intlen(long long nbr);

#endif
