/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:42:26 by snorcros          #+#    #+#             */
/*   Updated: 2019/09/14 16:13:38 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *begin_list)
{
	int		i;
	t_list	*buff;

	i = 0;
	buff = begin_list;
	while (buff)
	{
		buff = buff->next;
		i++;
	}
	return (i);
}
