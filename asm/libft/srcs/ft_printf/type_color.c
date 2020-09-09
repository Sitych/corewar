/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:22:41 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/05 16:22:46 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "colors.h"

char	*ft_colour(va_list ap)
{
	char	*str;
	char	*buf;
	size_t	i;

	i = 0;
	buf = ft_strmap(va_arg(ap, char *), (char (*)(char))ft_tolower);
	str = ft_strnew(10);
	while (g_colors[i].color_name[0] != 'z')
	{
		if (ft_strcmp(g_colors[i].color_name, buf) == 0)
			str = ft_strcpy(str, g_colors[i].macros);
		i++;
	}
	if (buf)
		free(buf);
	return (str);
}
