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

void	*ft_philo_road(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(&philo->right_fork->fork);
	pthread_mutex_lock(&philo->left_fork->fork);
	printf("%scoucou\n%s", BLUE, RESET);
	sleep(4);
	pthread_mutex_unlock(&philo->right_fork->fork);
	pthread_mutex_unlock(&philo->left_fork->fork);
	return (NULL);
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

void	ft_init_philo(char **argv, t_table *table)
{
	int		i;

	table->count_philo = ft_atoi(argv[1]);
	i = 0;
	while (i < table->count_philo)
	{
		if (pthread_mutex_init(&table->fork[i].fork, NULL))
			ft_exiting(2);
		i++;
	}
	i = 0;
	while (i < table->count_philo)
	{
		table->philo[i].id = i;
		table->philo[i].time_eaten = 0;
		table->philo[i].left_fork = &table->fork[i];
		table->philo[i].right_fork = &table->fork[(i + 1) % table->count_philo];
		i++;
	}
	ft_init_threads(table);
}


























/*
void	ft_init_args(char **argv, t_philosopher *philosopher)
{
	int		i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philosopher[i].total_philo = ft_atoi(argv[1]);
		philosopher[i].id = i + 1;
		philosopher[i].state.is_die = ALIVE;
		philosopher[i].state.fork = 1;
		philosopher[i].time_to_die = ft_atoi(argv[2]);
		philosopher[i].time_to_eat = ft_atoi(argv[3]);
		philosopher[i].time_to_sleep = ft_atoi(argv[4]);
		if (argv[5])
			philosopher[i].need_eat = ft_atoi(argv[5]);
		philosopher[i].start_time = set_time();
		if (pthread_mutex_init(&philosopher[i].fork, NULL))
			exit(EXIT_FAILURE);
		i++;
	}
}*/
