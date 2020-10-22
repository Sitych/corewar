/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_n.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:45:08 by cnails            #+#    #+#             */
/*   Updated: 2020/09/25 19:57:03 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_N_H
# define PARSE_N_H

typedef struct	s_arg
{
	int				index;
	char			*name;
	struct s_arg	*next;
}				t_arg;

typedef struct	s_data
{
	t_arg	*arg;
	int		len;
}				t_data;

int		is_valid_int(int nbr, char *str);
int		is_not_dupl(t_arg *arg, t_arg *end, int nbr);
t_arg	*new_arg(void);
int		first_free_nbr(t_arg *arg, int len);
char	**parse_n(int ac, char **av);

#endif
