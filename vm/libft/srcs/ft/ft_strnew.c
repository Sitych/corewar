/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:39:15 by snorcros          #+#    #+#             */
/*   Updated: 2019/09/12 20:03:58 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ans;

	if (!(size + 1))
		return (NULL);
	ans = (char *)malloc(sizeof(char) * (size + 1));
	if (!ans)
		return (NULL);
	ans = ft_memset(ans, '\0', size + 1);
	return (ans);
}
