/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unixtime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:27:21 by snorcros          #+#    #+#             */
/*   Updated: 2020/02/05 16:27:39 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_utime	new_unixtime(void)
{
	t_utime	t;

	t.hour = 0;
	t.minute = 0;
	t.second = 0;
	t.day = 1;
	t.month = 1;
	t.year = 1970;
	return (t);
}

void	set_unixtotime(t_utime *utime, int unix_time)
{
	utime->year += unix_time / 31556926;
	unix_time %= 31556926;
	utime->month += unix_time / 2629743;
	unix_time %= 2629743;
	utime->day += unix_time / 86400;
	unix_time %= 86400;
	utime->hour += unix_time / 3600;
	unix_time %= 3600;
	utime->minute += unix_time / 60;
	unix_time %= 60;
	utime->second += unix_time;
}

t_utime	unix_to_struct(int unix_time)
{
	t_utime	time;

	time = new_unixtime();
	set_unixtotime(&time, unix_time);
	return (time);
}
