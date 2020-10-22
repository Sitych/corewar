/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:48:38 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/10/21 20:48:34 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "operation.h"


int		load_op(t_vm *vm, t_carriage *cursor)
{
	
	if (*(cursor->program_counter) < 0x01 || *(cursor->program_counter) > 0x10)
	{
		cursor->opcode = 0;
		//invalide operation. Count byte shift
	}
	else
	{
		cursor->opcode = *(cursor->program_counter);
		cursor->cycle_to_die = g_op_tab[cursor->opcode].cycle_to_die;
	}
}
