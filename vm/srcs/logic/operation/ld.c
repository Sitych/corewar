/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 15:54:42 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/10/30 17:22:09 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		op_ld(uint8_t *arena, t_carriage *carriage)
{
	uint8_t		*ptr;
	int32_t		shift;
	t_arg		*args;

	ptr = arena + carriage->program_counter + OPCODE_SIZE;
	args = carriage->args;
	shift = get_args(&args, arena, carriage);
	if (shift == 0)
		return (0);
	ft_printf("args[0] = %d\nargs[1] = %d\n", args[0].value, args[1].value);
	carriage->regs[args[1].value] = args[0].value;
	carriage->program_counter += OPCODE_SIZE + TYPE_ARGS_SIZE + shift;
	return (1);
}
