/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:30:17 by snorcros          #+#    #+#             */
/*   Updated: 2019/09/14 16:10:44 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*previous;
	t_list	*next;

	previous = *begin_list;
	next = *begin_list;
	while (next && (*cmp)(next->content, data_ref) == 0)
	{
		*begin_list = next->next;
		free(next);
		next = *begin_list;
	}
	while (next)
	{
		previous = *begin_list;
		while (next && (*cmp)(next->content, data_ref) != 0)
			next = next->next;
		while (next && previous->next != next)
			previous = previous->next;
		if (next)
		{
			previous->next = next->next;
			free(next);
			next = previous->next;
		}
	}
}
