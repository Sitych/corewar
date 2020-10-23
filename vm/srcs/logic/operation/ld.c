/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:54:42 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/10/23 17:36:42 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "operation.h"

// нет проверки типа аргументов на валидность
int		op_ld(uint8_t *arena, t_carriage *carriage)
{
	int			i;
	uint8_t		*ptr;
	uint8_t		type_args[MAX_ARGS];
	uint32_t	args[MAX_ARGS];

	ptr = arena + carriage->program_counter + OPCODE_SIZE;
	i = 0;
	while (i < g_op_tab[carriage->opcode].col_args)
	{
		type_args[i] = *ptr >> (sizeof(uint8_t) - (i + 1) * 2);
		i++;
	}
	i = 0;
	ptr += TYPE_ARGS_SIZE;
	while (i < g_op_tab[carriage->opcode].col_args)
	{
		if (type_args[i] == REG_CODE)
		{
			args[i] = (uint32_t)(*(uint8_t*)ptr);
			ptr += REG_SIZE;
		}
		else if (type_args[i] == DIR_CODE)
		{		// нет определение отрицательного числа
			args[i] = (uint32_t)(*(uint16_t*)ptr);
			ptr += DIR_SIZE;
		}
		else if (type_args[i] == IND_CODE)
		{		// нет определение отрицательного числа
			args[i] = (uint32_t)(*(uint32_t*)ptr);
			ptr += IND_SIZE;	
		}
		else
		{
			ft_printf("Invalid argument %d in ld at %d position arena", i + 1, carriage->program_counter);
			return (0);
		}
		i++;
	}
	// type_args[0] - тип первого аргумента
	if (type_args[0] == DIR_CODE)
	{
		carriage->regs[args[1]] = args[0];
	}
	else if (type_args[0] == IND_CODE)
	{
		ptr = arena + carriage->program_counter + args[0] % IDX_MOD;
		carriage->regs[args[1]] = *(uint32_t*)ptr;
	}
	carriage->program_counter += OPCODE_SIZE + TYPE_ARGS_SIZE;
	i = 0;
	while (i < g_op_tab[carriage->opcode].col_args)
	{
		if (type_args[i] == REG_CODE)
			carriage->program_counter += REG_SIZE;
		else if (type_args[i] == DIR_CODE)
			carriage->program_counter += DIR_SIZE;
		else if (type_args[i] == IND_CODE)
			carriage->program_counter += IND_SIZE;
		i++;
	}
	return (1);
}
