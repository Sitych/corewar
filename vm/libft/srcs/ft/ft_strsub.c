/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 11:32:36 by snorcros          #+#    #+#             */
/*   Updated: 2019/09/14 17:51:51 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	last_index_sub;

	last_index_sub = (size_t)start + len;
	if (!s || last_index_sub > ft_strlen((char *)s))
		return (NULL);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while ((size_t)start < last_index_sub)
	{
		*sub = s[start];
		sub++;
		start++;
	}
	*sub = '\0';
	return (sub - len);
}
