/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:31:30 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/04 17:57:20 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stradd_front(char *str, size_t len, char c)
{
	char	*ans;
	size_t	len_str;

	if (len <= (len_str = ft_strlen(str)))
		return (str);
	if (!(ans = ft_strnew(len)))
		return (NULL);
	ans = ft_memset(ans, c, len - len_str);
	if (str)
		ans = ft_strcat(ans, str);
	free(str);
	return (ans);
}
