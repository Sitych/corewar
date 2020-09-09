/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 16:37:12 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/09/09 18:34:18 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

//remake with valide order champ
t_champion	*valid_champions(char **chmp_file_name, size_t col_champs)
{
	t_champion	*champs;
	t_champion	*head;

	head = parse_champion(chmp_file_name[col_champs - 1], col_champs);
	champs = head;
	while (--col_champs != 0)
	{
		champs->next = parse_champion(chmp_file_name[col_champs - 1], col_champs);
		champs = champs->next;
	}
	return (head);
}

t_carriage	*valid_cursor(t_champion *players)
{
	t_carriage	*cursor;
	t_carriage	*head;
	
	head = init_carrige(players->id);
	cursor = head;
	players = players->next;
	while (players != NULL)
	{
		cursor->next =  init_carrige(players->id);
		cursor = cursor->next;
		players = players->next;
	}
	return (head);
}