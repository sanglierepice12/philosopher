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

	/*if (ft_simulation_is_ended(philo) == true)
		return (true);*/
	pthread_mutex_lock(&philo->philo_mutex);
	actual_time = set_time(philo->table);
	if (actual_time - philo->last_meal_time > philo->table->time_to_die || philo->table->numb_philo == 1)
	{
		if (ft_simulation_is_ended(philo))
		{
			pthread_mutex_lock(&philo->philo_mutex);
			return (true);
		}
		pthread_mutex_lock(&philo->table->table_mutex);
		philo->table->simulation_on = false;
		actual_time = actual_time - philo->table->start_simulation;
		ft_mutex_print(philo, DEAD, actual_time);
		pthread_mutex_unlock(&philo->table->table_mutex);
		pthread_mutex_unlock(&philo->philo_mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo->philo_mutex);
	return (false);
}