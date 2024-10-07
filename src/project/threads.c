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

void	*ft_philo_road(void *data)
{
	t_philo		*philo;
	long long	time;

	philo = (t_philo *)data;
	pthread_mutex_lock(&philo->philo_mutex);
	philo->last_meal_time = set_time(philo->table);
	pthread_mutex_unlock(&philo->philo_mutex);
	while (philo->iAte != philo->table->max_meal)
	{
		if (ft_simulation_is_ended(philo) || ft_die(philo))
			return (data);
		if (!ft_eat(philo) || ft_simulation_is_ended(philo) || ft_die(philo))
			return (data);
		if (!ft_sleep(philo) || ft_simulation_is_ended(philo) || ft_die(philo))
			return (data);
		if (!ft_simulation_is_ended(philo))
		{
			pthread_mutex_lock(&philo->table->table_mutex);
			time = set_time(philo->table) - philo->table->start_simulation;
			ft_mutex_print(philo, THINK, time);
			pthread_mutex_unlock(&philo->table->table_mutex);
			usleep(500);
		}
	}
	return (data);
}

void	ft_join_threads(t_table *table)
{
	int			i;

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

	table->start_simulation = set_time(table);
	i = 0;
	while (i < table->numb_philo)
	{
		if (pthread_create(&table->philo[i].thread, NULL, ft_philo_road, &table->philo[i]))
			ft_exiting(1, table);
		i++;
	}
}