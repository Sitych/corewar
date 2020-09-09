/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placeholder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 14:36:48 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/04 21:29:51 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_placeholder	new_placeholder(void)
{
	t_placeholder buf;

	buf.flags = FLG_NULL;
	buf.length.flag = "m\0";
	buf.precision = -1;
	buf.width = 0;
	buf.type.flag = 'm';
	buf.sign = 0;
	return (buf);
}

int				placeholder_isempty(t_placeholder place)
{
	return (place.flags == FLG_NULL && place.length.flag[0] == 'm' &&
			place.precision == -1 && place.width == 0
			&& place.type.flag == 'm' && place.sign == 0);
}

int				placeholder_isnotempty(t_placeholder place)
{
	return ((place.flags != FLG_NULL || place.precision != -1
			|| place.width != 0 || place.sign != 0) && place.type.flag == 'm');
}
