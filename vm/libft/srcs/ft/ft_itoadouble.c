/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoadouble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:30:57 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/04 18:31:45 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_digits(long double n)
{
	int					count;
	unsigned long long	buf;

	count = 0;
	buf = n;
	if (buf == 0)
		return (1);
	if (n < 0)
	{
		buf = n * (-1);
		count++;
	}
	while (buf > 0)
	{
		buf /= 10;
		count++;
	}
	return (count);
}

static int		ft_count_digits_mantiss(long double n)
{
	int			count;
	long double buf;
	int			buf2;

	count = 0;
	if (n < 0)
		buf = n * (-1) - (unsigned long long)(n * (-1));
	else
		buf = n - (unsigned long long int)n;
	while (buf > 0)
	{
		buf *= 10;
		buf2 = (unsigned long long int)buf;
		buf -= buf2;
		count++;
	}
	return (count);
}

static char		*get_int(long double n, char *str_n, int count_digits)
{
	size_t				i;
	unsigned long long	buf;

	i = count_digits - 1;
	buf = n;
	if (buf == 0)
		str_n[i] = 0 + 48;
	if (n < 0)
	{
		buf = n * (-1);
		str_n[0] = '-';
	}
	while (buf > 0)
	{
		str_n[i--] = buf % 10 + 48;
		buf /= 10;
	}
	return (str_n);
}

static char		*get_mantiss(long double n, char *str_n, int count_digits)
{
	size_t	i;
	int		buf;

	i = count_digits;
	if (n < 0)
		n = n * (-1) - (unsigned long long)(n * (-1));
	else
		n -= (unsigned long long)n;
	str_n[i] = '.';
	i++;
	while (n > 0)
	{
		n *= 10;
		buf = (int)n;
		str_n[i] = buf + '0';
		n -= buf;
		i++;
	}
	return (str_n);
}

char			*ft_itoadouble(long double n)
{
	char	*str_n;
	int		count;
	int		count_digits;

	count_digits = ft_count_digits(n);
	count = count_digits + ft_count_digits_mantiss(n);
	str_n = ft_strnew(count + 1);
	if (!str_n)
		return (NULL);
	str_n = get_int(n, str_n, count_digits);
	if (str_n[0] == '0')
		return (str_n);
	str_n = get_mantiss(n, str_n, count_digits);
	return (str_n);
}
