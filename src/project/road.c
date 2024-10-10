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

void	ft_sleep(t_philo *philo)
{
	ft_mutex_print(philo, SLEEP, set_time() - \
		philo->table->start_simulation);
	ft_usleep(philo->table->time_to_sleep);
}

void	ft_eat(t_philo *philo)
{
	while (!ft_l_fork_tester(philo))
		usleep(50);
/*	if (philo->table->numb_philo == 1)
	{
		ft_usleep(philo->table->time_to_die, philo->table);
		ft_die(philo);
		if (ft_simulation_is_ended(philo->table))
			return (false);
	}*/
	while (!ft_r_fork_tester(philo))
		usleep(50);
	gettimeofday(&philo->death_time, NULL);
	ft_add_ms_time_val(&philo->death_time, philo->table->time_to_die);
	philo->last_meal_time = philo->death_time.tv_usec;
	ft_mutex_print(philo, EAT, set_time() - \
		philo->table->start_simulation);
	ft_usleep(philo->table->time_to_eat);
	philo->i_ate++;
	pthread_mutex_lock(&philo->right_fork->mutex);
	philo->right_fork->id = 0;
	pthread_mutex_unlock(&philo->right_fork->mutex);
	pthread_mutex_lock(&philo->left_fork->mutex);
	philo->left_fork->id = 0;
	pthread_mutex_unlock(&philo->left_fork->mutex);
}
