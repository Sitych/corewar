/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:59:31 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/10/24 17:12:13 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vm.h"
// # include "operation.h"

void		ft_exit(char *str)
{
	perror(str);
	exit (EXIT_FAILURE);
}

void	champ_print(t_champion *ptr)
{
	unsigned int i;

	i = 0;
	ft_printf("Magic header: %x\nNAME: %s\nProg size: %x\nComment: %s\nCode:\n", ptr->header.magic, ptr->header.prog_name, ptr->header.prog_size, ptr->header.comment);
	while (i < ptr->header.prog_size)
	{
		ft_printf("%.2x", (0xff & ptr->code[i]));
		if (i % 2 != 0)
			ft_putstr(" ");
		if ((i + 1) % 16 == 0 && i != 0)
			ft_putstr("\n");
		i++;
	}
}

void	arena_print(uint8_t *arena)
{
	size_t	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%.2x", (0xff & arena[i]));
		if (i % 2 != 0)
			ft_putstr(" ");
		if ((i + 1) % 64 == 0 && i != 0)
			ft_putstr("\n");
		i++;
	}
}

int main(int argc, char **argv)
{
	// char *files[3] = {"vm/maxidef.cor", "vm/Car.cor" ,"vm/Car.cor" }; // for debug
	char *files[2] = {"maxidef.cor", "Car.cor" };
	t_vm		*vm;
	size_t		col_champs = (size_t)argc - 1;
	
	col_champs = 2;
	vm = init_vm(col_champs);
	argv[0]++;
	vm->champs = valid_champions(files, col_champs);
	init_arena(vm);
	vm->cursor = valid_cursor(vm->champs, col_champs);
	arena_print(vm->arena);
	// while (vm->cursor)
	// {
	// 	ft_printf("%d\n%d\n", vm->cursor->program_counter, vm->cursor->regs[0]);
	// 	vm->cursor = vm->cursor->next;
	// }
	// op_live(vm->arena, vm->cursor);
	vm->cursor->opcode = 2;
	op_ld(vm->arena, vm->cursor);
	ft_printf("pc = %d\nregs = %d\n",*(vm->arena + vm->cursor->program_counter), vm->cursor->regs[5]);
	// ft_printf("%p\n%p\n", vm->cursor->program_counter + MEM_SIZE - 1, &(vm->arena[MEM_SIZE - 1]));
	// ft_printf("%d\n%d\n", *(vm->cursor->program_counter + MEM_SIZE - 1), vm->arena[MEM_SIZE - 1]);
	return (0);
}
