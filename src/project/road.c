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

static void	ft_philo_is_full(t_philo *philo)
{
	if (philo->i_ate == philo->max_eat)
	{
		philo->has_eaten_max = true;
		pthread_mutex_lock(&philo->table->eater_mutex);
		philo->table->philo_ate_max++;
		pthread_mutex_unlock(&philo->table->eater_mutex);
	}
}

void	ft_eat(t_philo *philo)
{
	while (!ft_l_fork_tester(philo))
		usleep(50);
	while (!ft_r_fork_tester(philo))
		usleep(50);
	pthread_mutex_lock(&philo->table->time_mutex);
	gettimeofday(&philo->death_time, NULL);
	ft_add_ms_time_val(&philo->death_time, philo->table->time_to_die);
	philo->last_meal_time = philo->death_time.tv_usec;
	pthread_mutex_unlock(&philo->table->time_mutex);
	ft_mutex_print(philo, EAT, set_time() - \
		philo->table->start_simulation);
	ft_usleep(philo->table->time_to_eat);
	philo->i_ate++;
	ft_philo_is_full(philo);
	pthread_mutex_lock(&philo->right_fork->mutex);
	philo->right_fork->id = 0;
	pthread_mutex_unlock(&philo->right_fork->mutex);
	pthread_mutex_lock(&philo->left_fork->mutex);
	philo->left_fork->id = 0;
	pthread_mutex_unlock(&philo->left_fork->mutex);
}
