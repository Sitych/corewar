/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkingsbl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 19:34:54 by pkingsbl          #+#    #+#             */
/*   Updated: 2020/09/04 19:35:05 by pkingsbl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "asm.h"

int		check_label(char *label)
{
	int 	i;
	int 	j;

	i = 0;
	while (label[i] != LABEL_CHAR)
	{
		j = 0;
		while (LABEL_CHARS[j] != '\0' && LABEL_CHARS[j] != label[i]) {
			printf("%c", label[i]);
			j++;
		}
		if (LABEL_CHARS[j] == '\0')
			return (1);
		i++;
	}
	return (0);
}


