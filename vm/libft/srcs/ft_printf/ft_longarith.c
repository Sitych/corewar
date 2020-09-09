/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longarith.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 23:20:37 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/02/05 19:03:02 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_double.h"

t_bigdbl	ft_mul_la(t_bigdbl a, short b)
{
	t_bigdbl		rslt;
	unsigned long	i;
	unsigned long	temp;
	unsigned long	carry;

	i = 0;
	carry = 0;
	rslt.size = a.size;
	rslt.coef = (short*)malloc(sizeof(short) * (a.size + 1));
	while (i < a.size)
	{
		temp = a.coef[i] * b + carry;
		carry = temp / BASE;
		rslt.coef[i] = temp - carry * BASE;
		i++;
	}
	if (carry)
	{
		rslt.coef[i] = carry;
		rslt.size = a.size + 1;
	}
	return (rslt);
}

t_bigdbl	ft_pow_la(t_bigdbl a, int count, int dig)
{
	t_bigdbl	buf;
	t_bigdbl	rslt;

	rslt.size = 1;
	rslt.coef = (short*)malloc(sizeof(short));
	rslt.coef[0] = (count == 0) ? 1 : a.coef[0];
	if (count == 0)
		return (rslt);
	while (--count)
	{
		buf = rslt;
		rslt = ft_mul_la(buf, dig);
		free(buf.coef);
	}
	return (rslt);
}

t_bigdbl	ft_sum_la(t_bigdbl a, t_bigdbl b, unsigned long i)
{
	t_bigdbl		rslt;
	long			temp;
	int				carry;

	if (a.size < b.size)
		return (ft_sum_la(b, a, 0));
	rslt.size = a.size;
	carry = 0;
	rslt.coef = (short*)malloc(sizeof(short) * (a.size + 1));
	while (i < b.size)
	{
		temp = a.coef[i] + b.coef[i] + carry;
		rslt.coef[i++] = (temp >= BASE) ? temp - BASE : temp;
		carry = (temp >= BASE) ? 1 : 0;
	}
	while (i < a.size)
	{
		temp = a.coef[i] + carry;
		rslt.coef[i++] = (temp >= BASE) ? temp - BASE : temp;
		carry = (temp >= BASE) ? 1 : 0;
	}
	(carry == 1) ? rslt.coef[i] = carry : 0;
	(carry == 1) ? rslt.size = a.size + 1 : 0;
	return (rslt);
}

t_bigdbl	ft_new_la(unsigned int nbr)
{
	t_bigdbl		rslt;
	size_t			i;
	unsigned int	n;

	n = nbr;
	i = 1;
	while (n > BASE)
	{
		n = n / BASE;
		i++;
	}
	rslt.size = i;
	rslt.coef = (short*)malloc(sizeof(short) * i);
	i = 0;
	while (i < rslt.size)
	{
		rslt.coef[i] = nbr % BASE;
		nbr = nbr / BASE;
		i++;
	}
	return (rslt);
}
