/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:59:31 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/09/09 18:44:32 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vm.h"

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
	char *files[2] = {"Car.cor" , "maxidef.cor"};
	t_vm		*vm;
	size_t		col_champs = (size_t)argc - 1;
	
	col_champs = 2;
	vm = init_vm(col_champs);
	argv[0]++;
	vm->champs = valid_champions(files, col_champs);
	vm->cursor = valid_cursor(vm->champs);
	init_arena(vm);
	arena_print(vm->arena);
	while (vm->cursor)
	{
		ft_printf("%d\n", vm->cursor->regs[0]);
		vm->cursor = vm->cursor->next;
	}
	return (0);
}
