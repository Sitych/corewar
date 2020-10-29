/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:00:59 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/10/29 17:58:12 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_carriage	*init_carrige(int col_champs, int id)
{
	t_carriage	*carrige;

	if ((carrige = (t_carriage*)ft_memalloc(sizeof(t_carriage))) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	if ((carrige->args = (t_arg*)ft_memalloc(sizeof(t_arg) * MAX_ARGS)) == NULL)
		ft_exit("ERROR: MALLOC ERROR");
	carrige->opcode = 0;
	carrige->cycle_to_die = 0;
	carrige->program_counter = MEM_SIZE / col_champs * (id - 1);
	ft_memset(carrige->regs, 0, REG_NUMBER);
	carrige->regs[0] = -id;
	carrige->carry = 0;
	carrige->live = 0;
	carrige->next = NULL;
	return (carrige);
}

t_champion	*init_champ(int id)
{
	t_champion	*champ;

	if ((champ = (t_champion*)ft_memalloc(sizeof(t_champion))) == NULL)
		ft_exit("ERROR: MALLOC");
	champ->code = NULL;
	champ->id = id;
	champ->next = NULL;
	return (champ);
}

t_vm		*init_vm(size_t col_champs)
{
	t_vm	*vm;

	if ((vm = (t_vm*)ft_memalloc(sizeof(t_vm))) == NULL)
		ft_exit("ERROR: MALLOC\n");
	vm->champs = NULL;
	vm->carrige = NULL;
	vm->col_champs = col_champs;
	ft_memset(vm->arena, 0, MEM_SIZE);
	return (vm);
}

void		init_arena(t_vm *vm)
{
	t_champion	*champ;
	size_t		i;

	champ = vm->champs;
	i = 0;
	while (champ)
	{
		ft_memmove(&(vm->arena[i * MEM_SIZE / vm->col_champs]), champ->code, \
													champ->header.prog_size);
		champ = champ->next;
		i++;
	}
}