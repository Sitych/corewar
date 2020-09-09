/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_champion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:59:25 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/09/02 16:52:55 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		swap_bit(char *byte)
{
	char	c;
	int		i;

	i = 0;
	while (i < 4 / 2)
	{
		c = byte[i];
		byte[i] = byte[3 - i];
		byte[3 - i] = c;
		i++;
	}
}

static t_header	init_header(int fd)
{
	t_header	champ;

	if (read(fd, &champ.magic, 4) < 0)
		ft_exit("ERROR: READ MAGIC HEADER");
	swap_bit((char*)(&champ.magic));
	if (read(fd, champ.prog_name, PROG_NAME_LENGTH) < 0)
		ft_exit("ERROR: READ NAME");
	lseek(fd, 4, SEEK_CUR);
	if (read(fd, &champ.prog_size, 4) < 0)
		ft_exit("ERROR: READ CHAMP SIZE");
	swap_bit((char*)(&champ.prog_size));
	if (read(fd, champ.comment, COMMENT_LENGTH) < 0)
		ft_exit("ERROR: READ COMMENT");
	lseek(fd, 4, SEEK_CUR);
	return (champ);
}

static void		check_champion(t_header head, char *filename)
{
	if (head.magic != COREWAR_EXEC_MAGIC)
	{
		ft_printf("Error: File %s has an invalid header\n", filename);
		exit(1);
	}
	if (head.prog_size > CHAMP_MAX_SIZE)
	{
		ft_printf("Error: File %s has too large ", filename);
		ft_printf("a code (%d bytes > 682 bytes)\n", head.prog_size);
		exit(1);
	}
}

t_champion		*parse_champion(char *chmp_file_name, int id)
{
	int			fd;
	t_champion	*champ;

	fd = open(chmp_file_name, O_RDONLY);
	if (fd < 0)
	{
		perror(chmp_file_name);
		exit(1);	
	}
	champ = init_champ(id);
	champ->header = init_header(fd);
	check_champion(champ->header, chmp_file_name);
	if ((champ->code = ft_memalloc(champ->header.prog_size + 1)) == NULL)
		ft_exit("ERROR: MALLOC");
	if ((read(fd, champ->code, champ->header.prog_size + 1)) < 0)
		ft_exit("ERROR: READ CODE");
	close(fd);
	return (champ);
}
