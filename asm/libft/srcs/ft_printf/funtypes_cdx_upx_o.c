/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funtypes_cdisx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:46:44 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/04 19:46:47 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_c(va_list ap)
{
	char *ans;

	if (!(ans = ft_strnew(2)))
		return (NULL);
	ans[0] = (char)va_arg(ap, int);
	ans[1] = '\0';
	return (ans);
}

char	*ft_d(va_list ap)
{
	return (ft_itoa(va_arg(ap, int)));
}

char	*ft_x(va_list ap)
{
	return (ft_itoahex(va_arg(ap, unsigned int), 'l'));
}

char	*ft_upx(va_list ap)
{
	return (ft_itoahex(va_arg(ap, unsigned int), 'u'));
}

char	*ft_o(va_list ap)
{
	return (ft_itoabase(va_arg(ap, unsigned int), (unsigned int)8));
}
