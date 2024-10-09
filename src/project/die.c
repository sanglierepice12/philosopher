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

bool	ft_die(t_philo *philo)
{
	long long	actual_time;

	pthread_mutex_lock(&philo->philo_mutex);
	actual_time = set_time(philo->table);
	if (actual_time - philo->last_meal_time > philo->table->time_to_die \
		|| philo->table->numb_philo == 1)
	{
		if (ft_simulation_is_ended(philo))
		{
			pthread_mutex_unlock(&philo->philo_mutex);
			return (true);
		}
		pthread_mutex_lock(&philo->table->table_mutex);
		actual_time = actual_time - philo->table->start_simulation;
		ft_mutex_print(philo, DEAD, actual_time);
		philo->table->simulation_on = false;
		pthread_mutex_unlock(&philo->table->table_mutex);
		pthread_mutex_unlock(&philo->philo_mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo->philo_mutex);
	return (false);
}

/*
void	ft_monitor_checker(t_table *table)
{
	int	i;

	i = 0;
	while (!ft_simulation_is_ended(&table->philo[i]) && \
		*/
/*table->philo->i_ate != table->philo->table->max_meal && \*//*

			table->numb_philo != 1)
	{
		//pthread_mutex_lock(&table->philo[i].philo_mutex);
		*/
/*if (table->philo->i_ate == table->philo->table->max_meal)
			break ;*//*

		//pthread_mutex_unlock(&table->philo[i].philo_mutex);
		ft_die(&table->philo[i]);
		if (table->philo->i_ate == table->philo->table->max_meal)
			break ;
		i++;
		if (i + 1 == table->numb_philo)
			i = 0;
	}
}*/
