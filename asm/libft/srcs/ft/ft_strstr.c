/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 12:54:57 by snorcros          #+#    #+#             */
/*   Updated: 2019/09/08 15:52:37 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	n;

	n = (size_t)ft_strlen((char *)needle);
	if (!*needle || !haystack)
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
			if (!ft_memcmp(haystack, needle, n))
				return ((char *)haystack);
		haystack++;
	}
	return (0);
}
