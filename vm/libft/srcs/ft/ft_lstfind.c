/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:17:06 by snorcros          #+#    #+#             */
/*   Updated: 2019/09/14 15:54:33 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list *buff;

	buff = begin_list;
	while (buff)
	{
		if ((*cmp)(buff->content, data_ref) == 0)
			return (buff);
		buff = buff->next;
	}
	return (buff);
}
