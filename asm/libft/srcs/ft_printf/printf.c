/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:42:33 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/05 15:44:46 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_placeholder	parse(va_list ap, const char **format)
{
	t_placeholder	place;

	place = new_placeholder();
	if (set_type(&place, *format))
	{
		*format += 1;
		return (place);
	}
	*format += set_flags(&place, *format);
	*format += set_width(&place, *format, ap);
	*format += set_precision(&place, *format, ap);
	*format += set_length(&place, *format);
	*format += set_type(&place, *format);
	return (place);
}

char			*check_flag(char *str, t_placeholder *place)
{
	if (place->type.flag == 'c' && *str != '\0')
		place->flags &= ~FLG_ZERO;
	if (*str == '\0' && place->type.flag == 'c')
		place->flags &= ~(FLG_SPACE | FLG_PLUS);
	else if (place->type.flag == 'f' && (*str == 'n' || *str == 'i'
			|| *(str + 1) == 'i' || *(str + 1) == 'n'))
	{
		place->flags &= FLG_NULL;
		place->precision = 0;
	}
	else if (*str == '-' && place->type.flag != 's' && place->type.flag != 'c'
			&& (place->flags != 0 || place->precision != -1))
	{
		place->sign = 1;
		return (delete_sign(str));
	}
	return (str);
}

char			*to_str_logic(t_placeholder place, va_list ap)
{
	char *ans;

	ans = NULL;
	if (place.type.flag != 'm' && place.length.flag[0] == 'm')
		ans = check_flag(place.type.fun(ap), &place);
	else if (place.length.fun != NULL)
		ans = check_flag(place.length.fun(ap, place.type.flag), &place);
	if (place.precision != -1)
		ans = get_precision(&place, ans);
	ans = get_flags(place, ans);
	ans = get_width(place, ans);
	return (ans);
}

int				print_this(t_placeholder place, char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		count += ft_putchar(str[i]);
		i++;
	}
	if (place.type.flag == 'c' && str[i] == '\0' &&
		((i < place.width && place.width != 0) || *str == '\0'))
		count += write(1, "\0", 1);
	if (place.type.flag == 'c' && str[i] == '\0'
								&& (place.flags &= FLG_MINUS) == FLG_MINUS)
		while (i < place.width - 1)
		{
			count += write(1, " ", 1);
			i++;
		}
	free(str);
	return (count);
}

int				ft_printf(const char *format, ...)
{
	int				count;
	va_list			ap;
	t_placeholder	place;
	char			*ans;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		while (*format != '%' && *format != '\0')
			count += ft_putchar(*(format++));
		if (*format == '%' && *(++format) != '\0')
		{
			place = parse(ap, &format);
			if (placeholder_isempty(place)
				|| (place.type.flag == 'm' && place.length.flag[0] != 'm'))
				return (-1);
			else if (place.type.flag == 'm')
				break ;
			ans = to_str_logic(place, ap);
			count += print_this(place, ans);
		}
	}
	va_end(ap);
	return (count);
}
