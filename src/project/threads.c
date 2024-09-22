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

void	ft_exiting(int h)
{
	printf ("%d\n", h);
	perror("");
	exit(EXIT_FAILURE);
}

void	ft_init_threads(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->count_philo)
	{
		if (pthread_create(&table->philo[i].thread, NULL, ft_philo_road, &table->philo[i]))
			ft_exiting(1);
		i++;
	}
}

void	ft_end_all(t_table *table)
{
	int	i;
	long	time;

	ft_init_threads(table);
	i = 0;
	while (i < table->count_philo)
	{
		if (pthread_join(table->philo[i].thread, NULL))
			ft_exiting(3);
		i++;
		time = set_time();
		printf("%stime = %lu\n%s", GREEN, time, RESET);
	}
	i = 0;
	while (i < table->count_philo)
	{
		pthread_mutex_destroy(&table->fork[i].fork);
		i++;
	}
}