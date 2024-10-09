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
	pthread_mutex_lock(&philo->table->table_mutex);
	if (philo->table->simulation_on == false)
	{
		pthread_mutex_unlock(&philo->table->table_mutex);
		return (false);
	}
	ft_mutex_print(philo, SLEEP, set_time(philo->table) - \
		philo->table->start_simulation);
	pthread_mutex_unlock(&philo->table->table_mutex);
	if (ft_usleep(philo->table->time_to_sleep, philo->table))
		return (false);
	return (true);
}

bool	ft_eat_follow(t_philo *philo)
{
	pthread_mutex_lock(&philo->philo_mutex);
	ft_mutex_print(philo, EAT, set_time(philo->table) - \
		philo->table->start_simulation);
	philo->last_meal_time = set_time(philo->table);
	pthread_mutex_unlock(&philo->philo_mutex);
	if (ft_usleep(philo->table->time_to_eat, philo->table))
		return (false);
	/*pthread_mutex_lock(&philo->philo_mutex);
	philo->i_ate++;
	pthread_mutex_unlock(&philo->philo_mutex);*/
	pthread_mutex_lock(&philo->right_fork->mutex);
	philo->right_fork->id = 0;
	pthread_mutex_unlock(&philo->right_fork->mutex);
	pthread_mutex_lock(&philo->left_fork->mutex);
	philo->left_fork->id = 0;
	pthread_mutex_unlock(&philo->left_fork->mutex);
	return (true);
}

bool	ft_eat(t_philo *philo)
{
	if (ft_simulation_is_ended(philo))
		return (false);
	while (!ft_l_fork_tester(philo))
	{
		usleep(50);
		/*if (ft_die(philo) || ft_simulation_is_ended(philo))
			return (false);*/
	}
	while (!ft_r_fork_tester(philo))
	{
		usleep(50);
		/*if (ft_die(philo) || ft_simulation_is_ended(philo))
			return (false);*/
	}
	if (ft_simulation_is_ended(philo))
		return (false);
	if (!ft_eat_follow(philo))
		return (false);
	return (true);
}
