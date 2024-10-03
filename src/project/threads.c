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

void	ft_join_threads(t_table *table)
{
	int			i;

	i = 0;
	while (i < table->count_philo)
	{
		if (pthread_join(table->philo[i].thread, NULL))
			ft_exiting(1, table);
		i++;
	}
}

void	ft_init_threads(t_table *table)
{
	int		i;

	table->begin_time = set_time(table);
	i = 0;
	while (i < table->count_philo)
	{
		table->philo[i].time_eaten = table->begin_time;
		if (pthread_create(&table->philo[i].thread, NULL, ft_philo_road, &table->philo[i]))
			ft_exiting(1, table);
		i++;
	}
}