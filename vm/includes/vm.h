/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:52:46 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/10/30 17:22:00 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "op.h"
# include "libftprintf.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

# define TRUE 1
# define FALSE 0
# define OPCODE_SIZE	1
# define MAX_ARGS		3
# define TYPE_ARGS_SIZE	1

# define REG_SIZE_BYTE	1
# define DIR_SIZE_BYTE	4
# define IND_SIZE_BYTE	2

# define THR_BITS		0x03

typedef struct s_op			t_op;
typedef struct s_champion	t_champion;
typedef struct s_vm			t_vm;
typedef struct s_carriage	t_carriage;
typedef struct s_arg		t_arg;

struct s_carriage
{
	int32_t					regs[REG_NUMBER];
	uint32_t				cycle_to_die;
	int8_t					live;
	uint8_t					opcode;
	int8_t					carry;
	int32_t					program_counter;
	t_arg					*args;
	t_carriage				*next;
};

struct						s_vm
{
	uint8_t					arena[MEM_SIZE];
	uint32_t				dump_cycle_to_die;
	
	t_champion				*champs;
	size_t					col_champs;
	t_carriage				*carrige;
};


struct						s_champion
{
	t_header	header;
	int			id;
	uint8_t		*code; // пока просто запиши весь код чемпиона сюда
	t_champion	*next;
};

struct						s_arg
{
	uint8_t	type;
	int32_t	value;
};

void						ft_exit(char *str);
t_champion					*init_champ(int id);
t_vm						*init_vm(size_t col_champs);
void						init_arena(t_vm *vm);
t_carriage					*init_carrige(int col_champs, int id);
t_champion					*parse_champion(char *chmp_file_name, int id);
t_champion					*valid_champions(char **chmp_file_name, size_t col_champs);
t_carriage					*valid_carrige(t_champion *players, int col_champs);
int32_t						get_args(t_arg **args, uint8_t *arena, t_carriage *carriage);

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
