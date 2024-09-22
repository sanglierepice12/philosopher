/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:06:24 by gsuter            #+#    #+#             */
/*   Updated: 2024/08/28 17:06:24 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosopher.h"

long	set_time(t_table *table)
{
	struct	timeval tv;
	struct	timezone tz;

	if (gettimeofday(&tv,&tz))
		ft_exiting();
	return (tv.tv_sec * 1000 + tv.tv_usec / 10000 - table->begin_time);
}

void	ft_usleep(t_philo *philo, long time)
{
	long	time_begin;

	time_begin = set_time(philo->table);
	while (set_time(philo->table) - time_begin < time)
		usleep(500);
}
