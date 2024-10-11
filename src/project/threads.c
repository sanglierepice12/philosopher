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

static void	ft_simulation_call(t_philo *philo)
{
	long long	time;

	while (!ft_simulation_is_ended(philo->table))
	{
		ft_eat(philo);
		ft_sleep(philo);
		time = set_time() - philo->table->start_simulation;
		ft_mutex_print(philo, THINK, time);
		usleep(50);
	}
}

void	*ft_philo_road(void *data)
{
	t_philo		*philo;

	philo = (t_philo *)data;
	philo->last_meal_time = set_time();
	pthread_mutex_lock(&philo->table->time_mutex);
	gettimeofday(&philo->death_time, NULL);
	ft_add_ms_time_val(&philo->death_time, philo->table->time_to_die);
	pthread_mutex_unlock(&philo->table->time_mutex);
	pthread_mutex_lock(&philo->table->start_mutex);
	pthread_mutex_unlock(&philo->table->start_mutex);
	if (philo->id % 2 == 0 && philo->table->numb_philo != 1)
	{
		ft_mutex_print(philo, THINK, set_time() - \
			philo->table->start_simulation);
		ft_usleep(philo->table->time_to_eat * 0.5f);
	}
	ft_simulation_call(philo);
	return (data);
}

void	ft_join_threads(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->numb_philo)
	{
		if (pthread_join(table->philo[i].thread, NULL))
			ft_exiting(1, table);
		i++;
	}
}

void	ft_init_threads(t_table *table)
{
	int		i;

	pthread_mutex_lock(&table->start_mutex);
	i = 0;
	while (i < table->numb_philo)
	{
		gettimeofday(&table->philo[i].death_time, NULL);
		ft_add_ms_time_val(&table->philo[i].death_time, \
			(long)table->time_to_die);
		if (pthread_create(&table->philo[i].thread, NULL, \
			ft_philo_road, &table->philo[i]))
			ft_exiting(1, table);
		i++;
	}
	usleep(50);
	table->start_simulation = set_time();
	pthread_mutex_unlock(&table->start_mutex);
}
