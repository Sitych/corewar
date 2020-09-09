/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 21:13:28 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/05 15:35:50 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		set_precision(t_placeholder *placeholder, const char *format,
																	va_list ap)
{
	int p;
	int k;

	k = 0;
	if (*format == '.')
	{
		k++;
		format++;
		if (*format == '*')
			k += star_precision(placeholder, ap);
		else if ((p = ft_atoi(format)) >= 0)
		{
			placeholder->precision = p;
			while (p > 0)
			{
				p /= 10;
				k++;
			}
			if (p == 0 && *format == '0')
				k++;
		}
		return (k);
	}
	return (0);
}

int		set_width(t_placeholder *placeholder, const char *format, va_list ap)
{
	int w;
	int k;

	k = 0;
	if (*format == '*')
	{
		if (star_width(placeholder, format, ap))
			return (1);
		k += 1;
		format++;
	}
	if ((w = ft_atoi(format)) > 0)
	{
		placeholder->width = w;
		while (w > 0)
		{
			w /= 10;
			k++;
		}
		return (k);
	}
	return (0);
}

char	*get_width(t_placeholder place, char *ans)
{
	if (place.type.flag == 'c' && ans[0] == '\0'
								&& (place.flags &= FLG_MINUS) == FLG_MINUS)
		return (ans);
	if ((place.flags & FLG_PLUS) == 0 && (place.flags & FLG_SPACE) == 0)
		ans = get_sign(place, ans);
	if (place.width != 0)
	{
		if (ft_strlen(ans) == 0 && place.type.flag == 'c'
								&& (place.flags &= FLG_MINUS) == 0)
			ans = ft_stradd_front(ans, place.width - 1, ' ');
		else if ((size_t)place.width > ft_strlen(ans)
				&& (place.flags & FLG_MINUS) == 0
				&& ((place.flags & FLG_ZERO) == 0 || place.type.flag == 's'))
			ans = ft_stradd_front(ans, place.width, ' ');
		else if ((place.flags & FLG_ZERO) == FLG_ZERO && place.precision != -1)
			ans = ft_stradd_front(ans, place.width, ' ');
	}
	return (ans);
}
