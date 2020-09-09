/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 14:35:38 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/05 16:30:28 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*length_l(va_list ap, char typeflag)
{
	if (typeflag == 'i' || typeflag == 'd')
		return (ft_itoa_signed(va_arg(ap, long int), 10));
	if (typeflag == 'u')
		return (ft_itoabase(va_arg(ap, unsigned long int), 10));
	else if (typeflag == 'f')
		return (ft_f(ap));
	else if (typeflag == 'o')
		return (ft_itoabase(va_arg(ap, unsigned long int), 8));
	else if (typeflag == 'x')
		return (ft_itoahex(va_arg(ap, unsigned long int), 'l'));
	else if (typeflag == 'X')
		return (ft_itoahex(va_arg(ap, unsigned long int), 'u'));
	return (ft_strnew(1));
}

char	*length_ll(va_list ap, char typeflag)
{
	if (typeflag == 'i' || typeflag == 'd')
		return (ft_itoa_signed(va_arg(ap, long int), 10));
	if (typeflag == 'u')
		return (ft_itoabase(va_arg(ap, unsigned long long int), 10));
	else if (typeflag == 'o')
		return (ft_itoabase(va_arg(ap, unsigned long long int), 8));
	else if (typeflag == 'x')
		return (ft_itoahex(va_arg(ap, unsigned long long int), 'l'));
	else if (typeflag == 'X')
		return (ft_itoahex(va_arg(ap, unsigned long long int), 'u'));
	return (ft_strnew(1));
}

char	*length_h(va_list ap, char typeflag)
{
	if (typeflag == 'i' || typeflag == 'd')
		return (ft_itoa((short int)va_arg(ap, int)));
	else if (typeflag == 'u')
		return (ft_itoabase((unsigned short)va_arg(ap, unsigned int), 10));
	else if (typeflag == 'o')
		return (ft_itoabase((unsigned short)va_arg(ap, unsigned int), 8));
	else if (typeflag == 'x')
		return (ft_itoahex((unsigned short)va_arg(ap, unsigned int), 'l'));
	else if (typeflag == 'X')
		return (ft_itoahex((unsigned short)va_arg(ap, unsigned int), 'u'));
	return (ft_strnew(1));
}

char	*length_hh(va_list ap, char typeflag)
{
	if (typeflag == 'i' || typeflag == 'd')
		return (ft_itoa((signed char)va_arg(ap, int)));
	if (typeflag == 'u')
		return (ft_itoabase((unsigned char)va_arg(ap, unsigned int), 10));
	else if (typeflag == 'o')
		return (ft_itoabase((unsigned char)va_arg(ap, unsigned int), 8));
	else if (typeflag == 'x')
		return (ft_itoahex((unsigned char)va_arg(ap, unsigned int), 'l'));
	else if (typeflag == 'X')
		return (ft_itoahex((unsigned char)va_arg(ap, unsigned int), 'u'));
	return (ft_strnew(1));
}

char	*length_upl(va_list ap, char typeflag)
{
	long double number;
	char		*str;

	number = va_arg(ap, long double);
	if (typeflag == 'f')
	{
		if (number != number)
		{
			str = ft_strnew(5);
			if (number > 0)
				return (ft_strcpy(str, "nan\0"));
			else
				return (ft_strcpy(str, "-nan\0"));
		}
		else if (number != 0 && number * 10 == number)
		{
			str = ft_strnew(5);
			if (number > 0)
				return (ft_strcpy(str, "inf\0"));
			else
				return (ft_strcpy(str, "-inf\0"));
		}
		return (ft_get_d(number));
	}
	return (ft_strnew(1));
}
