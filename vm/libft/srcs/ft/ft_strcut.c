/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:21:56 by snorcros          #+#    #+#             */
/*   Updated: 2019/09/09 15:23:21 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcut(char *dest, size_t len_res)
{
	size_t	i;
	char	*ans;

	i = 0;
	if (len_res == ft_strlen(dest))
		return (dest);
	if (!dest || !(ans = ft_strnew(len_res)))
		return (NULL);
	while (i < len_res)
	{
		ans[i] = dest[i];
		i++;
	}
	ans[i] = '\0';
	free(dest);
	return (ans);
}
