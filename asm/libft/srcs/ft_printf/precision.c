/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 21:33:52 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/05 19:25:43 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	strcount_digit(char *str)
{
	size_t count;

	count = 0;
	while (str[count] != '.' && str[count] != '\0')
		count++;
	return (count + 1);
}

static size_t	str_len_mantiss(char *str)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (str[i] != '.' && str[i] != '\0')
		i++;
	while (str[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
}

static char		*get_precision_float(t_placeholder *place, char *ans,
														size_t count_digit)
{
	size_t	i;

	if ((size_t)place->precision >= str_len_mantiss(ans))
		return (ft_stradd_back(ans, place->precision + count_digit, '0'));
	if (ans[place->precision + count_digit] >= '5' && (i = 1))
	{
		if (ans[place->precision + count_digit - i] != '9')
		{
			i = (ans[place->precision + count_digit - i] == '.') ? i + 1 : i;
			ans[place->precision + count_digit - i] += 1;
		}
		else
		{
			while (ans[place->precision + count_digit - i] == '9')
				ans[place->precision + count_digit - i++] = '0';
			i = (ans[place->precision + count_digit - i] == '.') ? i + 1 : i;
			ans[place->precision + count_digit - i] += 1;
		}
	}
	if (place->precision == 0 && ((place->flags & FLG_HASH) != FLG_HASH))
		return (ft_strcut(ans, count_digit - 1));
	if (place->precision == 0 && ((place->flags & FLG_HASH) == FLG_HASH))
		return (ft_strcut(ans, count_digit));
	return (ft_strcut(ans, place->precision + count_digit));
}

static char		*get_precision_p(t_placeholder *place, char *ans)
{
	if (ans[2] == '0')
	{
		if (place->precision == 0)
			ans = ft_strcut(ans, 2);
		else
			ans = ft_stradd_back(ans, place->precision + 2, '0');
	}
	else
	{
		if ((size_t)place->precision > ft_strlen(ans) - 2)
		{
			ans[1] = '0';
			ans = ft_stradd_front(ans, place->precision + 2, '0');
			ans[1] = 'x';
		}
	}
	return (ans);
}

char			*get_precision(t_placeholder *place, char *ans)
{
	if (place->type.flag == 'c' || (place->type.flag == 'o' &&
							(place->flags & FLG_HASH) != 0 && *ans == '0'))
		return (ans);
	if (place->type.flag == 'f')
		return (get_precision_float(place, ans, strcount_digit(ans)));
	if (place->type.flag == 'p')
		return (get_precision_p(place, ans));
	else if (place->precision == 0 && *ans == '0')
	{
		free(ans);
		place->flags &= ~FLG_HASH;
		if (place->type.flag == '%')
			place->flags &= FLG_NULL;
		return (ft_strnew(1));
	}
	else if ((place->type.flag == 'd' || place->type.flag == 'i'
	|| place->type.flag == 'o' || place->type.flag == 'u'
	|| place->type.flag == 'x' || place->type.flag == 'X')
	&& (place->precision > 0 && *ans != '\0')
	&& ((size_t)place->precision > ft_strlen(ans)))
		ans = ft_stradd_front(ans, place->precision, '0');
	else if (place->type.flag == 's' && place->precision >= 0)
		ans = ft_strcut(ans, place->precision);
	return (ans);
}
