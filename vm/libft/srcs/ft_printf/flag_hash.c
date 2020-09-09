/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:09:01 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/04 19:16:37 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	only_zero(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

static int	only_zero_and_space(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '0' || str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

static char	*hash_type_o(char *str, t_placeholder place)
{
	if ((place.flags & FLG_ZERO) == FLG_ZERO
		&& ((place.width <= (int)ft_strlen(str) && str[0] != '0'
				&& place.width >= place.precision)
		|| (str[0] != '0' && place.width > (int)ft_strlen(str))))
		return (ft_stradd_front(str, ft_strlen(str) + 1, '0'));
	if ((place.precision > place.width && place.width != 0)
		|| (place.flags & FLG_ZERO) == FLG_ZERO
		|| (place.precision == (int)ft_strlen(str) && str[0] == '0')
		|| (only_zero_and_space(str) && place.precision == -1))
		return (str);
	if (only_zero(str) && place.precision != -1)
		return (ft_stradd_front(str, place.precision, '0'));
	else
		return (ft_stradd_front(str, ft_strlen(str) + 1, '0'));
}

char		*flags_hash(char *str, t_placeholder place)
{
	if (*str == '0' && *(str + 1) == '\0' && place.width < 1
										&& place.precision == -1)
		return (str);
	if (place.type.flag == 'o')
		return (hash_type_o(str, place));
	else if (place.type.flag == 'x' && !only_zero(str))
	{
		if ((place.flags & FLG_ZERO) == 0 || str[0] != '0'
			|| place.precision > place.width
			|| place.width > (int)ft_strlen(str))
			str = ft_stradd_front(str, ft_strlen(str) + 2, '0');
		str[1] = 'x';
	}
	else if (place.type.flag == 'X' && !only_zero(str))
	{
		if ((place.flags & FLG_ZERO) == 0 || str[0] != '0'
			|| place.precision > place.width
			|| place.width > (int)ft_strlen(str))
			str = ft_stradd_front(str, ft_strlen(str) + 2, '0');
		str[1] = 'X';
	}
	return (str);
}
