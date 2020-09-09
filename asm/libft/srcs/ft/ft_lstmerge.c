/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:33:08 by snorcros          #+#    #+#             */
/*   Updated: 2019/09/14 16:12:16 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmerge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *buff;

	buff = *begin_list1;
	if (*begin_list1 == 0)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (buff->next)
		buff = buff->next;
	buff->next = begin_list2;
}
