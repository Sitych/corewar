/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_n_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 19:51:35 by cnails            #+#    #+#             */
/*   Updated: 2020/09/25 19:53:40 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_n.h"

int		is_valid_int(int nbr, char *str)
{
	char *tmp;

	tmp = ft_itoa(nbr);
	if (strcmp(tmp, str))
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}

int		is_not_dupl(t_arg *arg, t_arg *end, int nbr)
{
	t_arg *head;

	head = arg;
	while (head != end)
	{
		if (head->index == nbr)
			return (0);
		head = head->next;
	}
	return (1);
}

t_arg	*new_arg(void)
{
	t_arg *arg;

	arg = (t_arg *)ft_memalloc(sizeof(t_arg));
	arg->next = NULL;
	return (arg);
}

int		first_free_nbr(t_arg *arg, int len)
{
	t_arg	*tmp;
	int		i;
	int		nbr;

	nbr = 0;
	i = 0;
	while (i < len)
	{
		tmp = arg;
		while (tmp)
		{
			if (nbr == tmp->index)
			{
				nbr++;
				break ;
			}
			else
				tmp = tmp->next;
		}
		if (!tmp)
			return (nbr);
		i++;
	}
	return (-1);
}
