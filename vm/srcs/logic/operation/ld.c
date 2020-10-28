/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:54:42 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/10/28 20:48:04 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"
#include <math.h>

int32_t		get_arg(uint8_t *ptr, uint8_t type)
{
	int32_t	arg;
	int32_t	i;
	uint8_t	size;

	arg = 0;
	i = 0;
	size = (type == REG_CODE) ? REG_SIZE_BYTE : 0;
	size = (type == IND_CODE) ? IND_SIZE_BYTE : size;
	size = (type == DIR_CODE) ? DIR_SIZE_BYTE : size;
	if (size == 0)
		ft_printf("BLYA");
	while (i < size)
	{
		arg |= *(ptr + i);
		if (i != size - 1)
			arg = arg << CHAR_BIT;
		i++;
	}
	return (arg);
}

int32_t		get_params(t_arg *args, uint8_t *arena, t_carriage *carriage)
{
	int32_t i;
	int32_t	shift;
	uint8_t	*ptr;

	ptr = arena + carriage->program_counter + OPCODE_SIZE;
	shift = 0;
	i = 0;
	while (i < g_op_tab[carriage->opcode - 1].col_args)
	{
		args[i].type = (*ptr >> (CHAR_BIT - (i + 1) * 2)) & THREE_BITS;
		args[i].value = get_arg(ptr + shift, args[i].type);
		//Написать для indirect
		shift += pow(2, 2 + args[i].type);
		i++;
	}
	return (1);
}

// нет проверки типа аргументов на валидность
int		op_ld(uint8_t *arena, t_carriage *carriage)
{
	int			i;
	uint8_t		*ptr;
	uint8_t		type_args[MAX_ARGS];
	uint32_t	args[MAX_ARGS];

	ptr = arena + carriage->program_counter + OPCODE_SIZE;
	i = 0;
	while (i < g_op_tab[carriage->opcode - 1].col_args)
	{
		type_args[i] = (*ptr >> (sizeof(uint8_t) * 8 - (i + 1) * 2)) & 0x03;
		i++;
	}
	i = 0;
	ptr += TYPE_ARGS_SIZE;
	while (i < g_op_tab[carriage->opcode - 1].col_args)
	{
		if (type_args[i] == REG_CODE)
		{
			args[i] = get_arg(ptr, REG_SIZE_BYTE);
			ptr += REG_SIZE_BYTE;
		}
		else if (type_args[i] == DIR_CODE)
		{		// нет определение отрицательного числа
			args[i] = get_arg(ptr , DIR_SIZE_BYTE);
			ptr += DIR_SIZE_BYTE;
		}
		else if (type_args[i] == IND_CODE)
		{		// нет определение отрицательного числа
			args[i] = get_arg(ptr , IND_SIZE_BYTE);
			ptr += IND_SIZE_BYTE;
		}
		else
		{
			ft_printf("Invalid argument %d in ld at %d position arena\n", i + 1, carriage->program_counter);
			return (0);
		}
		i++;
	}
	ft_printf("args[0] = %x\nargs[1] = %d\n", args[0], args[1]);
	// type_args[0] - тип первого аргумента
	if (type_args[0] == DIR_CODE)
	{
		carriage->regs[args[1]] = args[0];
	}
	else if (type_args[0] == IND_CODE)
	{
		if ((int32_t)(carriage->program_counter + args[0]) < 0)
			ptr = arena + MEM_SIZE + carriage->program_counter + args[0] % IDX_MOD;	
		else
			ptr = arena + carriage->program_counter + 2 + (int32_t)args[0] % IDX_MOD;
		carriage->regs[args[1]] = *ptr;
	}
	carriage->program_counter += OPCODE_SIZE + TYPE_ARGS_SIZE;
	i = 0;
	while (i < g_op_tab[carriage->opcode].col_args)
	{
		if (type_args[i] == REG_CODE)
			carriage->program_counter += REG_SIZE_BYTE;
		else if (type_args[i] == DIR_CODE)
			carriage->program_counter += DIR_SIZE_BYTE;
		else if (type_args[i] == IND_CODE)
			carriage->program_counter += IND_SIZE_BYTE;
		i++;
	}
	return (1);
}
// 1	2	3
// 01	10	11
// 8	16	32
// 2^3	2^4	2^5
// 2+1	2+2	2+3