/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   road.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostr <gostr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:46:52 by gostr             #+#    #+#             */
/*   Updated: 2024/10/02 12:46:52 by gostr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosopher.h"

bool	ft_sleep(t_philo *philo)
{
	if (ft_simulation_is_ended(philo))
		return (false);
	pthread_mutex_lock(&philo->philo_mutex);
	pthread_mutex_lock(&philo->table->table_mutex);
	if (philo->table->simulation_on == false)
	{
		pthread_mutex_unlock(&philo->table->table_mutex);
		pthread_mutex_unlock(&philo->philo_mutex);
		return (false);
	}
	ft_mutex_print(philo, SLEEP, set_time(philo->table) - philo->table->start_simulation);
	pthread_mutex_unlock(&philo->table->table_mutex);
	pthread_mutex_unlock(&philo->philo_mutex);
	ft_usleep(philo->table->time_to_sleep, philo->table);
	return (true);
}

bool ft_eat(t_philo *philo)
{
	if (ft_simulation_is_ended(philo))
		return (false);
//	if (philo->id % 2 == 0)
//	{
	while (!ft_l_fork_tester(philo))
	{
		printf("b");
		if (ft_die(philo) || ft_simulation_is_ended(philo))
			return (false);
	}
	while (!ft_r_fork_tester(philo))
	{
		printf("a");
		if (ft_die(philo) || ft_simulation_is_ended(philo))
		{
			return (false);
		}
	}
//	}
//	else
//	{
//		while (!ft_r_fork_tester(philo))
//		{
//			//printf("CCC");
//			if (ft_die(philo) || ft_simulation_is_ended(philo))
//				return (false);
//		}
//		/*while (!ft_l_fork_tester(philo))
//		{
//		//	printf("gggg");
//			if (ft_die(philo) || ft_simulation_is_ended(philo))
//				return (false);
//		}*/
//	}
	if (ft_simulation_is_ended(philo))
	{
		pthread_mutex_unlock(&philo->left_fork->mutex);
		pthread_mutex_unlock(&philo->right_fork->mutex);
		return (false);
	}
	pthread_mutex_lock(&philo->philo_mutex);
	philo->last_meal_time = set_time(philo->table); // Set up at what time philo ate
	ft_mutex_print(philo, EAT, set_time(philo->table) - philo->table->start_simulation);
	philo->iAte++;
	pthread_mutex_unlock(&philo->philo_mutex);

	ft_usleep(philo->table->time_to_eat, philo->table);
	pthread_mutex_unlock(&philo->right_fork->mutex);
	pthread_mutex_unlock(&philo->left_fork->mutex);
	return (true);
}