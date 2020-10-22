/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:52:46 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/10/22 22:54:06 by qjosmyn          ###   ########.fr       */
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

# define TRUE 1
# define FALSE 0
# define OPCODE_SIZE	1
# define MAX_ARGS		3

typedef struct s_op			t_op;
typedef struct s_champion	t_champion;
typedef struct s_vm			t_vm;
typedef struct s_carriage	t_carriage;

struct s_carriage
{
	int32_t					regs[REG_NUMBER];
	int						cycle_to_die;
	int						live;
	uint8_t					opcode;
	int						carry;
	int					program_counter;
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
t_carriage					*init_carrige(int col_champs, int id);
t_champion					*parse_champion(char *chmp_file_name, int id);
t_champion					*valid_champions(char **chmp_file_name, size_t col_champs);
t_carriage					*valid_cursor(t_champion *players, int col_champs);


int			op_live(uint8_t *arena, t_carriage *carriage);
int			op_ld(uint8_t *arena, t_carriage *carriage);
int			op_st(uint8_t *arena, t_carriage *carriage);
int			op_add(uint8_t *arena, t_carriage *carriage);
int			op_sub(uint8_t *arena, t_carriage *carriage);
int			op_and(uint8_t *arena, t_carriage *carriage);
int			op_or(uint8_t *arena, t_carriage *carriage);
int			op_xor(uint8_t *arena, t_carriage *carriage);
int			op_zjmp(uint8_t *arena, t_carriage *carriage);
int			op_ldi(uint8_t *arena, t_carriage *carriage);
int			op_sti(uint8_t *arena, t_carriage *carriage);
int			op_fork(uint8_t *arena, t_carriage *carriage);
int			op_lld(uint8_t *arena, t_carriage *carriage);
int			op_lldi(uint8_t *arena, t_carriage *carriage);
int			op_lfork(uint8_t *arena, t_carriage *carriage);
int			op_aff(uint8_t *arena, t_carriage *carriage);

#endif
