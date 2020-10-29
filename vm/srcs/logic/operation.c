/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:48:38 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/10/29 17:55:54 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "operation.h"


int		load_op(t_vm *vm, t_carriage *carrige)
{
	
	if (*(carrige->program_counter) < 0x01 || *(carrige->program_counter) > 0x10)
	{
		carrige->opcode = 0;
		//invalide operation. Count byte shift
	}
	else
	{
		carrige->opcode = *(carrige->program_counter);
		carrige->cycle_to_die = g_op_tab[carrige->opcode].cycle_to_die;
	}
}
