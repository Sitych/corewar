/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 10:56:54 by snorcros          #+#    #+#             */
/*   Updated: 2019/09/14 15:44:55 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*buf;

	buf = *alst;
	while (buf)
	{
		*alst = buf->next;
		(del)(buf->content, buf->content_size);
		buf->content = NULL;
		free(buf);
		buf = *alst;
	}
	*alst = NULL;
}
