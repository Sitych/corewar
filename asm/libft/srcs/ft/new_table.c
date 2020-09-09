/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 12:54:57 by snorcros          #+#    #+#             */
/*   Updated: 2019/09/08 19:52:37 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			**new_table(int n, int m)
{
	int **ans;
	int i;

	i = -1;
	if (!(ans = (int **)malloc(sizeof(int *) * (n))))
		return (NULL);
	while (++i < n)
		if (!(ans[i] = (int *)malloc(sizeof(int) * (m))))
		{
			free_table((void **)ans, i);
			return (NULL);
		}
		else
			ft_memset(ans[i], 0, m);
	return (ans);
}
