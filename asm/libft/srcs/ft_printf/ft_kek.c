/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kek.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:19:00 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/05 18:17:53 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_count_digits(long double n)
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

int		ft_count_digits_mantiss(long double n)
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

char	*get_mantiss(long double n,
							char *str_n, int count_digits)
{
	size_t	i;
	int		buf;

	i = (str_n[0] == '0') ? 1 : count_digits;
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

char	*ft_get_d(long double n)
{
	char	*str_n;
	int		count_digits;

	str_n = NULL;
	str_n = ft_add_d(n, 0, &count_digits, str_n);
	if (!str_n)
		return (NULL);
	str_n = get_mantiss(n, str_n, count_digits);
	return (str_n);
}
