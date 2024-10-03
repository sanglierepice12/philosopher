/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:16:22 by gsuter            #+#    #+#             */
/*   Updated: 2024/08/29 14:16:22 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosopher.h"

void	ft_init_philo(char **argv, t_table *table)
{
	int		i;

	table->count_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->max_eat = ft_atoi(argv[5]);
	table->alive = true;
	table->begin_time = 0;
	if (pthread_mutex_init(&table->table_var, NULL))
		ft_exiting(0, table);
	i = 0;
	while (i < table->count_philo)
	{
		if (pthread_mutex_init(&table->fork[i].fork, NULL))
			ft_exiting(0, table);
		if (pthread_mutex_init(&table->philo[i].philo_var, NULL))
			ft_exiting(0, table);
		i++;
	}
	i = 0;
	while (i < table->count_philo)
	{
		table->philo[i].table = table;
		table->philo[i].id = i;
		table->philo[i].alive = true;
		table->philo[i].time_eaten = 0;
		table->philo[i].left_fork = &table->fork[i];
		table->philo[i].right_fork = &table->fork[(i + 1) % table->count_philo];
		i++;
	}
}