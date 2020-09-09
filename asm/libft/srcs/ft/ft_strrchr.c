/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 12:25:50 by snorcros          #+#    #+#             */
/*   Updated: 2019/09/08 13:54:53 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*occur;

	occur = (const char*)0;
	while (*s != '\0')
	{
		if (*s == (char)c)
			occur = s;
		s++;
	}
	if (!c && !*s)
		return ((char *)s);
	return ((char *)occur);
}
