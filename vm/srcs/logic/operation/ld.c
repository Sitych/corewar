/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dima <dima@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:54:42 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/10/26 15:44:09 by dima             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"
#include <math.h>

static uint32_t		swap_bit_32(uint32_t byte)
{
	uint8_t	c;
	uint8_t	*buf;
	int		i;

	i = 0;
	buf = (uint8_t*)&byte;
	while (i < 4 / 2)
	{
		c = buf[i];
		buf[i] = buf[3 - i];
		buf[3 - i] = c;
		i++;
	}
	return (*(uint32_t*)buf);
}

static uint32_t		swap_bit_16(uint16_t byte)
{
	uint8_t	c;
	uint8_t	*buf;
	int		i;

	i = 0;
	ft_printf("byte = %d\n", byte);
	buf = (uint8_t*)&byte;
	while (i < 2 / 2)
	{
		c = buf[i];
		buf[i] = buf[1 - i];
		buf[1 - i] = c;
		i++;
	}
	byte = *(uint32_t*)buf - 1;
	byte ^= 0xFFFFFFFF;
	return (-byte);
}

int32_t		take_arg(const uint8_t *ptr, uint8_t size)
{
	int32_t	arg;
	int32_t	i;

	arg = 0;
	i = 0;
	while (i < size)
	{
		arg |= *(ptr + i);
		if (i != size - 1)
			arg << CHAR_BIT * (i + 1);
		i++;
	}
	if (size == IND_SIZE_BYTE)
	
	return (arg);
}

void		get_params(t_arg *args, uint8_t *arena, t_carriage *carriage)
{
	int32_t i;
	int32_t	shift;
	uint8_t	*ptr;

	ptr = arena + carriage->program_counter + OPCODE_SIZE;
	shift = 0;
	i = 0;
	while (i < g_op_tab[carriage->opcode - 1].col_args)
	{
		args[i].type = (*ptr >> (CHAR_BIT - (i + 1) * 2)) & 0x03; 
		if (args[i].type == REG_CODE)
			args[i].value = take_arg(ptr + shift, REG_SIZE_BYTE);
		else if (args[i].type == IND_CODE)
			args[i].value = take_arg(ptr + shift, IND_SIZE_BYTE);
		else if (args[i].type == DIR_CODE)
			args[i].value = take_arg(ptr + shift, DIR_SIZE_BYTE);
		else
			return (0);
		shift += pow(2, 2 + args[i].type);
		i++;
	}
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
			args[i] = (uint32_t)(*(uint8_t*)ptr);
			ptr += REG_SIZE_BYTE;
		}
		else if (type_args[i] == DIR_CODE)
		{		// нет определение отрицательного числа
			args[i] = (uint32_t)(*(uint32_t*)ptr);
			ptr += DIR_SIZE_BYTE;
		}
		else if (type_args[i] == IND_CODE)
		{		// нет определение отрицательного числа
			args[i] = (uint32_t)(*(uint16_t*)ptr);
			ptr += IND_SIZE_BYTE;
		}
		else
		{
			ft_printf("Invalid argument %d in ld at %d position arena\n", i + 1, carriage->program_counter);
			return (0);
		}
		i++;
	}
	ft_printf("args[0] = %d\nargs[1] = %d\n", args[0], args[1]);
	// type_args[0] - тип первого аргумента
	if (type_args[0] == DIR_CODE)
	{
		carriage->regs[args[1]] = swap_bit_32(args[0]);
	}
	else if (type_args[0] == IND_CODE)
	{
		args[0] = swap_bit_16((uint32_t)args[0]);
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
