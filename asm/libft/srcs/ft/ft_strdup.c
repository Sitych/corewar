/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:12:00 by snorcros          #+#    #+#             */
/*   Updated: 2019/09/09 15:22:21 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ans;
	int		len;

	len = ft_strlen(src);
	ans = (char*)malloc(sizeof(char) * (len + 1));
	if (ans == NULL)
		return (0);
	ans = ft_strcpy(ans, src);
	return (ans);
}
