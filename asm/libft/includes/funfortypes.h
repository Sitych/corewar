/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funfortypes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:01:53 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/05 17:07:33 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNFORTYPES_H
# define FUNFORTYPES_H
# include "libftprintf.h"

t_funtype		g_types[] =
{
	{'c', ft_c},
	{'%', ft_percent},
	{'d', ft_d},
	{'i', ft_d},
	{'s', ft_s},
	{'x', ft_x},
	{'X', ft_upx},
	{'o', ft_o},
	{'u', ft_u},
	{'b', ft_b},
	{'p', ft_p},
	{'f', ft_f},
	{'k', ft_colour},
	{'D', ft_unix_to_isodate},
	{'m', NULL}
};

t_funlenght		g_lengths[] =
{
	{"ll", length_ll},
	{"hh", length_hh},
	{"l", length_l},
	{"h", length_h},
	{"L", length_upl},
	{"z", length_z},
	{"j", length_j},
	{"m", NULL}
};

t_funflags		g_flags[] =
{
	{ FLG_ZERO, '0', flags_zero},
	{ FLG_PLUS, '+', flags_plus},
	{ FLG_HASH, '#', flags_hash},
	{ FLG_SPACE, ' ', flags_space},
	{ FLG_MINUS, '-', flags_minus},
	{ FLG_NULL, 'm', NULL}
};
#endif
