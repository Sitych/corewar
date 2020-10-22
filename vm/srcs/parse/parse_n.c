/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnails <cnails@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 10:44:06 by cnails            #+#    #+#             */
/*   Updated: 2020/09/25 19:54:34 by cnails           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_n.h"

static int		ret_len(int ac, char **av)
{
	int		i;
	int		len;

	i = 1;
	len = 0;
	while (i < ac)
	{
		if (av[i][0] == '-')
			i++;
		else
			len++;
		i++;
	}
	return (len);
}

static int		parse_position(int i, t_data *data, t_arg *arg, char **av)
{
	if (av[i + 1] && is_valid_int(ft_atoi(av[i + 1]), av[i + 1]))
	{
		arg->index = ft_atoi(av[i + 1]);
		if (arg->index < data->len && av[i + 2] &&\
		is_not_dupl(data->arg, arg, arg->index) && arg->index >= 0)
			arg->name = ft_strdup(av[i + 2]);
		else
			ft_exit("invalid options\n");
		return (2);
	}
	else
		ft_exit("invalid options\n");
	return (0);
}

static void		parse_arg(int ac, char **av, t_data *data)
{
	int		i;
	t_arg	*arg;

	arg = new_arg();
	data->arg = arg;
	i = 1;
	while (i < ac)
	{
		if (!strcmp(av[i], "-n"))
			i += parse_position(i, data, arg, av);
		else
		{
			arg->index = -1;
			arg->name = strdup(av[i]);
		}
		i++;
		if (i < ac)
		{
			arg->next = new_arg();
			arg = arg->next;
		}
	}
}

static t_data	*parse_options_n(int ac, char **av)
{
	t_data	*data;
	t_arg	*head;

	data = (t_data *)ft_memalloc(sizeof(t_data));
	data->len = ret_len(ac, av);
	parse_arg(ac, av, data);
	head = data->arg;
	while (head)
	{
		if (head->index == -1)
			head->index = first_free_nbr(data->arg, data->len);
		head = head->next;
	}
	return (data);
}

char			**parse_n(int ac, char **av)
{
	t_data	*data;
	t_arg	*tmp;
	char	**str;

	data = parse_options_n(ac, av);
	if (!(str = (char **)ft_memalloc(sizeof(char *) * (data->len + 1))))
		ft_exit("no memory\n");
	while (data->arg)
	{
		tmp = data->arg->next;
		str[data->arg->index] = data->arg->name;
		free(data->arg);
		data->arg = tmp;
	}
	free(data);
	return (str);
}
