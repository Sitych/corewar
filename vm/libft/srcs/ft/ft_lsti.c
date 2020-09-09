/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:09:43 by snorcros          #+#    #+#             */
/*   Updated: 2019/09/14 16:05:59 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lsti(t_list *begin_list, size_t nbr)
{
	size_t	i;
	t_list	*buff;

	i = 0;
	buff = begin_list;
	while (i != nbr && buff)
	{
		buff = buff->next;
		i++;
	}
	return (buff);
}
