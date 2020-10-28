/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 19:15:21 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/10/29 00:07:12 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#define T_DIR1	T_DIR + 2

int		op_live(uint8_t *arena, t_carriage *carriage)
{
	// Если операцию, на которой стоит каретка не перезаписывалась, то 
	// carriage->opcode == *carriage->program_counter

	uint32_t	*command;

	command = (uint32_t*)(arena + carriage->program_counter);
	// if (*command < 1 && *command > 4)
	// 	return (0);
	ft_printf("%d\n", *command);
	if (*command == (uint32_t)carriage->regs[0])
		carriage->live = TRUE;
	carriage->program_counter = (carriage->program_counter + T_DIR1 + OPCODE_SIZE) % MEM_SIZE;
	return (1);
}
