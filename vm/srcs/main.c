/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:59:31 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/09/07 15:35:10 by qjosmyn          ###   ########.fr       */
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

//remake with valide order champ
t_champion	*valid_champions(char **chmp_file_name, size_t col_champs)
{
	t_champion	*champs;
	t_champion	*head;

	head = parse_champion(chmp_file_name[col_champs - 1], col_champs);
	champs = head;
	while (--col_champs != 0)
	{
		champs->next = parse_champion(chmp_file_name[col_champs - 1], col_champs);
		champs = champs->next;
	}
	return (head);
}

int main(int argc, char **argv)
{
	char *files[3] = {"Car.cor" ,"Car.cor" , "maxidef.cor"}; // for debug
	// char *files[2] = {"Car.cor" , "maxidef.cor"};
	t_vm		*vm;
	size_t		col_champs = (size_t)argc - 1;
	
	col_champs = 3;
	vm = init_vm(col_champs);
	argv[0]++;
	vm->champs = valid_champions(files, col_champs);
	ft_printf("HI!!! \n");
	init_arena(vm);
	arena_print(vm->arena);
	return (0);
}
