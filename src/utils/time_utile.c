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

long long	set_time(t_table *table)
{
	struct timeval	time;
	long long		actual_time;

	pthread_mutex_lock(&table->time_mutex);
	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	actual_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	pthread_mutex_unlock(&table->time_mutex);
	(void)table;
	return (actual_time);
}

int	ft_usleep(long long milliseconds, t_table *table)
{
	long long	start;

	start = set_time(table);
	while ((set_time(table) - start) < milliseconds)
	{
		if (ft_simulation_is_ended(table->philo))
			return (1);
		usleep(50);
	}
	return (0);
}
