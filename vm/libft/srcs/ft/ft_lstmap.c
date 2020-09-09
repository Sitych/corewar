/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:03:32 by snorcros          #+#    #+#             */
/*   Updated: 2019/09/14 13:02:18 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*buf;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	buf = (t_list *)malloc(sizeof(t_list));
	if (!buf)
		return (NULL);
	buf = (*f)(lst);
	head = buf;
	while (lst->next)
	{
		lst = lst->next;
		ft_lstadd_back(&buf, (*f)(lst));
		if (!buf)
			return (NULL);
		buf = buf->next;
	}
	return (head);
}
