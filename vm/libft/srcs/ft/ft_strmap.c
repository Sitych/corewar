/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dima <dima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:03:25 by snorcros          #+#    #+#             */
/*   Updated: 2020/08/28 12:52:27 by dima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, int (*f)(int))
{
	char	*ans;
	int		i;

	i = 0;
	if (!s || !f || !(ft_strlen((char *)s) + 1))
		return (NULL);
	ans = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!ans)
		return (NULL);
	while (*s)
	{
		ans[i] = (*f)(*s);
		s++;
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
