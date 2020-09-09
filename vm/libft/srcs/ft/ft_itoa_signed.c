/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:10:51 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/04 18:26:30 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_digits(long long n, unsigned int base)
{
	int			count;
	long long	buf;

	count = 0;
	buf = n;
	if (n <= 0)
	{
		buf *= -1;
		count++;
	}
	while (buf > 0)
	{
		buf /= base;
		count++;
	}
	return (count);
}

char			*ft_itoa_signed(long long n, unsigned int base)
{
	char	*str_n;
	int		count;
	size_t	i;

	if (n == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	count = ft_count_digits(n, base);
	str_n = ft_strnew(count);
	if (!str_n)
		return (NULL);
	if (n < 0)
	{
		str_n[0] = '-';
		n *= -1;
	}
	i = count - 1;
	if (n == 0)
		str_n[i] = 0 + 48;
	while (n > 0)
	{
		str_n[i--] = n % base + 48;
		n /= base;
	}
	return (str_n);
}
