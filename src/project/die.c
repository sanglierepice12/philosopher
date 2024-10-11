/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:44:40 by gsuter            #+#    #+#             */
/*   Updated: 2024/10/08 14:44:40 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosopher.h"

//todo add ms to timeval

void	ft_add_ms_time_val(struct timeval *tv, long milliseconds)
{
	tv->tv_sec += milliseconds / 1000;
	milliseconds %= 1000;
	tv->tv_usec += milliseconds * 1000;
	if (tv->tv_usec >= 1000000)
	{
		tv->tv_sec += tv->tv_usec / 1000000;
		tv->tv_usec %= 1000000;
	}
}

static bool	ft_compare_time_val(struct timeval tv1, struct timeval tv2)
{
	if (tv1.tv_sec > tv2.tv_sec)
		return (true);
	if (tv1.tv_sec < tv2.tv_sec)
		return (false);
	if (tv1.tv_usec / 1000 > tv2.tv_usec / 1000)
		return (true);
	if (tv1.tv_usec / 1000 < tv2.tv_usec / 1000)
		return (false);
	return (false);
}

void	ft_die(t_philo *philo)
{
	long long		actual_time;
	struct timeval	tv_actual;

	gettimeofday(&tv_actual, NULL);
	pthread_mutex_lock(&philo->table->time_mutex);
	if (ft_compare_time_val(tv_actual, philo->death_time))
	{
		pthread_mutex_unlock(&philo->table->time_mutex);
		if (ft_simulation_is_ended(philo->table))
			return ;
		actual_time = set_time() - philo->table->start_simulation;
		printf("%lld | %lld", (tv_actual.tv_sec * 1000 + tv_actual.tv_usec / 1000) - philo->table->start_simulation, (philo->death_time.tv_sec * 1000 + philo->death_time.tv_usec / 1000) - philo->table->start_simulation);
		pthread_mutex_lock(&philo->table->table_mutex);
		ft_mutex_print(philo, DEAD, actual_time);
		pthread_mutex_unlock(&philo->table->table_mutex);
	}
	else
		pthread_mutex_unlock(&philo->table->time_mutex);

}
