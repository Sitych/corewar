/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:31:47 by snorcros          #+#    #+#             */
/*   Updated: 2019/09/22 17:59:38 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_overlong(long long prev, int sign, char s)
{
	long long		cur;

	cur = 10 * prev + (s - '0');
	if (prev > cur)
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	return (1);
}

int			ft_atoi(const char *str)
{
	long long	ans;
	int			sign;
	char		*str1;

	ans = 0;
	sign = 1;
	str1 = (char*)str;
	while (*str1 == '\t' || *str1 == '\n' || *str1 == '\f'
			|| *str1 == '\r' || *str1 == ' ' || *str1 == '\v')
		str1++;
	if (*str1 == '-')
	{
		sign = -1;
		str1++;
	}
	else if (*str1 == '+')
		str1++;
	while ((*str1 >= '0') && (*str1 <= '9'))
	{
		if (check_overlong(ans, sign, *str1) != 1)
			return (check_overlong(ans, sign, *str1));
		ans = 10 * ans + (*str1 - '0');
		str1++;
	}
	return (ans * sign);
}
