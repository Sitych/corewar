/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag_sign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:06:35 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/05 18:48:18 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	check_spaceback(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

char		*get_sign(t_placeholder placeholder, char *str)
{
	if (placeholder.sign != 0)
	{
		if (placeholder.width == 0 || !check_spaceback(str) ||
		(placeholder.precision >= placeholder.width && placeholder.width != 0))
			return (ft_stradd_front(str, ft_strlen(str) + 1, '-'));
		else
			return (ft_strcat_front(str, "-", placeholder.width - 1, 1));
	}
	return (str);
}

char		*delete_sign(char *str)
{
	size_t i;

	i = 0;
	while (str[i + 1] != '\0')
	{
		str[i] = str[i + 1];
		i++;
	}
	str[i] = '\0';
	return (str);
}
