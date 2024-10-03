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
	struct	timeval tv;
	struct	timezone tz;

	if (gettimeofday(&tv,&tz))
		ft_exiting(1, table);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(t_philo *philo, long long time)
{
	long long	begin;

	begin = set_time(philo->table);
	//pthread_mutex_lock(&philo->table->table_var);
	if (ft_die(philo))
		return ;
	/*if (set_time(philo->table) - philo->time_eaten > philo->table->time_to_die)
	{
		ft_die(philo);
		*//*philo->table->alive = false;
		printf("%sPhilosopher %d is dead at %lld ms%s\n", RED, philo->id, set_time(philo->table) - philo->table->begin_time, RESET);*//*
		//pthread_mutex_unlock(&philo->table->table_var);
		return ;//ft_exiting(1, philo->table);
	}*/
	//pthread_mutex_unlock(&philo->table->table_var);
	while (philo->table->alive)
	{
		if (set_time(philo->table) - begin >= time)
			break ;
		usleep(50);
	}
}
