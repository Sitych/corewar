/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:31:30 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/04 17:41:08 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stradd_back(char *str, size_t len, char c)
{
	char	*ans;
	size_t	i;

	if (len <= (i = ft_strlen(str)))
		return (str);
	if (!(ans = ft_strnew(len)))
		return (NULL);
	if (str)
		ans = ft_strcat(ans, str);
	while (i < len)
	{
		ans[i] = c;
		i++;
	}
	free(str);
	return (ans);
}
