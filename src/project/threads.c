/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostr <gostr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:20:48 by gostr             #+#    #+#             */
/*   Updated: 2024/09/20 18:20:48 by gostr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosopher.h"

void	ft_init_threads(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->count_philo)
	{
		if (pthread_create(&table->philo[i].thread, NULL, ft_philo_road, &table->philo[i]))
			ft_exiting();
		i++;
	}
}

void	ft_join_threads(t_table *table)
{
	int			i;
	/*long		time_now;*/

	ft_init_threads(table);
	i = 0;
	while (i < table->count_philo)
	{
		table->begin_time = set_time(table);
	/*	time_now = set_time(table);*/
		if (pthread_join(table->philo[i].thread, NULL))
			ft_exiting();
		/*if (time_now - table->philo[i].time_eaten > table->philo[i].time_to_eat)
		{
			printf("%sstop\ntime = %lu\n%s", GREEN, time_now - table->philo[i].time_eaten, RESET);
			break ;
		}*/
		i++;
	}
	i = 0;
	while (i < table->count_philo)
	{
		pthread_mutex_destroy(&table->fork[i].fork);
		pthread_mutex_destroy(&table->philo[i].philo_var);
		i++;
	}
}