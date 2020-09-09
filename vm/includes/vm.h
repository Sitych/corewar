/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:52:46 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/09/09 19:15:17 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "libftprintf.h"

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

///"live", 1, {T_DIR}, 1, 10, "alive", 0, 0
// typedef struct s_opt
// {
// 	int		tab_index; // index in op_tab (op.c)
// 	int		op; // продумать представление операции
// }				t_opt;

typedef struct s_op			t_op;
typedef struct s_champion	t_champion;
typedef struct s_vm			t_vm;
typedef struct s_carriage	t_carriage;

struct s_carriage
{
	int32_t					regs[REG_NUMBER];
	int						cycle_to_die;
	int						command;
	int						carry;
	uint8_t					*position;
	t_carriage				*next;
};

struct						s_vm
{
	uint8_t					arena[MEM_SIZE];
	uint32_t				dump_cycle_to_die;
	
	t_champion				*champs;
	size_t					col_champs;
	t_carriage				*cursor;
};


struct						s_op
{
	char	*name_oper;
	int		col_arg;
	int		*type_arg;
	int		opcode;
	int		cycle_to_die;
	char	*comment;
	int		change_carry;
	int		code_type_arg;
};

struct						s_champion
{
	t_header	header;
	int			id;
	uint8_t		*code; // пока просто запиши весь код чемпиона сюда
	t_champion	*next;
};

void						ft_exit(char *str);
t_champion					*init_champ(int id);
t_vm						*init_vm(size_t col_champs);
void						init_arena(t_vm *vm);
t_carriage					*init_carrige(int id);
t_champion					*parse_champion(char *chmp_file_name, int id);
t_champion					*valid_champions(char **chmp_file_name, size_t col_champs);
t_carriage					*valid_cursor(t_champion *players);

#endif
