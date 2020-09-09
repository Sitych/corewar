/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 15:02:09 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/05 17:00:01 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define BLACK "\033[30;1m"
# define PURPLE "\033[36;1m"
# define RED "\033[31;1m"
# define GREEN "\033[32;1m"
# define YELLOW "\033[33;1m"
# define BLUE "\033[34;1m"
# define MAGENTA "\033[35;1m"
# define CYAN "\033[36;1m"
# define WHITE "\033[37;1m"
# define EOC "\033[6;0m"

typedef struct	s_color
{
	char *color_name;
	char *macros;
}				t_color;

t_color			g_colors[] =
{
	{"black", BLACK},
	{"purple", PURPLE},
	{"red", RED},
	{"green", GREEN},
	{"yellow", YELLOW},
	{"blue", BLUE},
	{"magenta", MAGENTA},
	{"cyan", CYAN},
	{"white", WHITE},
	{"eoc", EOC},
	{"zero", EOC},
};
#endif
