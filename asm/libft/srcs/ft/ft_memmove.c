/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 12:52:19 by snorcros          #+#    #+#             */
/*   Updated: 2019/09/08 17:54:07 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dest > src)
	{
		while (len--)
			*((unsigned char*)dest + len) = *((unsigned char*)src + len);
	}
	else if (dest != src)
		while (i < len)
		{
			*((unsigned char*)dest + i) = *((unsigned char*)src + i);
			i++;
		}
	return (dest);
}
