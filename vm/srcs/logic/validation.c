/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 16:37:12 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/10/29 17:55:57 by qjosmyn          ###   ########.fr       */
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

t_carriage	*valid_carrige(t_champion *players, int col_champs)
{
	t_carriage	*carrige;
	t_carriage	*head;
	
	head = init_carrige(col_champs, players->id);
	carrige = head;
	players = players->next;
	while (players != NULL)
	{
		carrige->next = init_carrige(col_champs, players->id);
		carrige = carrige->next;
		players = players->next;
	}
	return (head);
}