/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:54:42 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/10/29 17:58:57 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"
#include <math.h>

int			kek(int kek)
{
	static int lol = 0;

	if (kek == 1)
		lol = 1;
	else if (kek == 0)
		lol = 0;
	return (lol);
}

int32_t		ft_size(int code)
{
	if (code == REG_CODE)
		return (1);
	else if (code == IND_CODE)
		return (2);
	else if (code == DIR_CODE)
		return (4);
	return (0);
}

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
		kek(1);
	while (i < size)
	{
		arg |= *(ptr + i);
		if (i != size - 1)
			arg = arg << CHAR_BIT;
		i++;
	}
	if (type == IND_CODE)
		arg = (int32_t)((int16_t)arg);
	return (arg);
}

int32_t		get_params(t_arg **args, uint8_t *arena, t_carriage *carriage)
{
	int32_t i;
	int32_t	shift;
	uint8_t	*ptr;

	ptr = arena + carriage->program_counter + OPCODE_SIZE;
	shift = 1;
	i = 0;
	while (i < g_op_tab[carriage->opcode - 1].col_args)
	{
		(*args)[i].type = (*ptr >> (CHAR_BIT - (i + 1) * 2)) & THR_BITS;
		(*args)[i].value = get_arg(ptr + shift, (*args)[i].type);
		if ((*args)[i].type == IND_CODE)
		{
			if ((carriage->program_counter + (*args)[i].value) < 0)
				(*args)[i].value = *(arena + MEM_SIZE + 
						carriage->program_counter + (*args)[i].value % IDX_MOD);	
			else
				(*args)[i].value = *(arena + carriage->program_counter + 
													(*args)[i].value % IDX_MOD);
		}
		shift += ft_size((*args)[i].type);
		i++;
	}
	return (shift);
}

// нет проверки типа аргументов на валидность
int		op_ld(uint8_t *arena, t_carriage *carriage)
{
	uint8_t		*ptr;
	int32_t		shift;
	t_arg		*args;

	ptr = arena + carriage->program_counter + OPCODE_SIZE;
	args = carriage->args;
	shift = get_params(&args, arena, carriage);
	ft_printf("args[0] = %d\nargs[1] = %d\n", args[0].value, args[1].value);
	// type_args[0] - тип первого аргумента
	carriage->regs[args[1].value] = args[0].value;
	carriage->program_counter += OPCODE_SIZE + TYPE_ARGS_SIZE + shift;
	return (1);
}

// 1	2	3
// 01	02	03
// 1	4	2
// 8	32	16
