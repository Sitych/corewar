/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funtypes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:14:01 by snorcros          #+#    #+#             */
/*   Updated: 2019/12/07 14:36:20 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_u(va_list ap)
{
	return (ft_itoabase(va_arg(ap, unsigned int), (unsigned int)10));
}

char	*ft_b(va_list ap)
{
	return (ft_itoabase(va_arg(ap, unsigned int), (unsigned int)2));
}

char	*ft_p(va_list ap)
{
	char *str;

	str = ft_itoahex((unsigned long long)va_arg(ap, void *), 'l');
	str = ft_stradd_front(str, ft_strlen(str) + 2, '0');
	str[1] = 'x';
	return (str);
}
