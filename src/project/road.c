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

bool	ft_die(t_philo *philo)
{
	long long	actual_time;

	if (ft_simulation_is_ended(philo) == true)
		return (true);
	pthread_mutex_lock(&philo->philo_mutex);
	actual_time = set_time(philo->table);
	if (actual_time - philo->last_meal_time > philo->table->time_to_die || philo->table->numb_philo == 1)
	{
		if (ft_simulation_is_ended(philo))
			return (true);
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
//	printf("%s%lld %d is sleeping%s\n", BLUE, set_time(philo->table) - philo->table->start_simulation, philo->id, RESET);
	// Sleep
	pthread_mutex_unlock(&philo->table->table_mutex);
	pthread_mutex_unlock(&philo->philo_mutex);
	ft_usleep(philo->table->time_to_sleep, philo->table);
	return (true);
}

bool ft_eat(t_philo *philo)
{
	if (ft_simulation_is_ended(philo))
		return (false);
	// Takes fork
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->left_fork->fork);
		ft_mutex_print(philo, FORK, set_time(philo->table) - philo->table->start_simulation);
		//printf("%s%lld %d has taken a fork%s\n", YELLOW, set_time(philo->table) - philo->table->start_simulation, philo->id, RESET);
		pthread_mutex_lock(&philo->right_fork->fork);
		ft_mutex_print(philo, FORK, set_time(philo->table) - philo->table->start_simulation);
	//	printf("%s%lld %d has taken a fork%s\n", YELLOW, set_time(philo->table) - philo->table->start_simulation, philo->id, RESET);
	}
	else
	{
		//printf("%s%lld %d has taken a fork%s\n", YELLOW, set_time(philo->table) - philo->table->start_simulation, philo->id, RESET);
		pthread_mutex_lock(&philo->right_fork->fork);
		ft_mutex_print(philo, FORK, set_time(philo->table) - philo->table->start_simulation);
		//printf("%s%lld %d has taken a fork%s\n", YELLOW, set_time(philo->table) - philo->table->start_simulation, philo->id, RESET);
		pthread_mutex_lock(&philo->left_fork->fork);
		ft_mutex_print(philo, FORK, set_time(philo->table) - philo->table->start_simulation);
	}
	if (ft_simulation_is_ended(philo))
	{
		pthread_mutex_unlock(&philo->left_fork->fork);
		pthread_mutex_unlock(&philo->right_fork->fork);
		return (false);
	}
	// Eating
	pthread_mutex_lock(&philo->philo_mutex);
	philo->last_meal_time = set_time(philo->table); // Set up at what time philo ate
	ft_mutex_print(philo, EAT, set_time(philo->table) - philo->table->start_simulation);
	//printf("%s%lld %d is eating%s\n", YELLOW, set_time(philo->table) - philo->table->start_simulation, philo->id, RESET);
	philo->iAte++;
	pthread_mutex_unlock(&philo->philo_mutex);

	// Eat
	ft_usleep(philo->table->time_to_eat, philo->table);
	// Free forks
	pthread_mutex_unlock(&philo->right_fork->fork);
	pthread_mutex_unlock(&philo->left_fork->fork);
	return (true);
}