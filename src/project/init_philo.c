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
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->left_fork->fork);
		pthread_mutex_lock(&philo->right_fork->fork);
	}
	else
	{
		pthread_mutex_lock(&philo->right_fork->fork);
		pthread_mutex_lock(&philo->left_fork->fork);
	}
	pthread_mutex_lock(&philo->philo_var);
	printf("%sje suis philo[%d]\n%s", BLUE, philo->id, RESET);
	ft_usleep(philo, philo->time_to_eat);
	philo->time_eaten = set_time(philo->table);
	pthread_mutex_unlock(&philo->philo_var);
	pthread_mutex_unlock(&philo->right_fork->fork);
	pthread_mutex_unlock(&philo->left_fork->fork);
	return (NULL);
}


void	ft_init_philo(char **argv, t_table *table)
{
	int		i;

	table->count_philo = ft_atoi(argv[1]);
	table->begin_time = 0;
	i = 0;
	while (i < table->count_philo)
	{
		if (pthread_mutex_init(&table->fork[i].fork, NULL))
			ft_exiting();
		if (pthread_mutex_init(&table->philo[i].philo_var, NULL))
			ft_exiting();
		i++;
	}
	i = 0;
	while (i < table->count_philo)
	{
		table->philo[i].table = table;
		table->philo[i].id = i;
		table->philo[i].time_eaten = 0;
		table->philo[i].time_to_eat = ft_atoi(argv[3]);
		table->philo[i].time_to_die = ft_atoi(argv[2]);
		table->philo[i].left_fork = &table->fork[i];
		table->philo[i].right_fork = &table->fork[(i + 1) % table->count_philo];
		i++;
	}
}