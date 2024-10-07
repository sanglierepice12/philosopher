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

void	ft_init_table(char **argv, t_table *table)
{
	table->numb_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->max_meal = ft_atoi(argv[5]);
	else
		table->max_meal = -1;
	table->simulation_on = true;
	table->start_simulation = 0;
}

static void	ft_init_mutex(t_table *table)
{
	int		i;

	if (pthread_mutex_init(&table->table_mutex, NULL))
		ft_exiting(0, table);
	i = 0;
	while (i < table->numb_philo)
	{
		if (pthread_mutex_init(&table->fork[i].fork, NULL))
			ft_exiting(0, table);
		if (pthread_mutex_init(&table->philo[i].philo_mutex, NULL))
			ft_exiting(0, table);
		i++;
	}
}

void	ft_init_philo(t_table *table)
{
	int		i;

	ft_init_mutex(table);
	i = 0;
	while (i < table->numb_philo)
	{
		table->philo[i].table = table;
		table->philo[i].id = i;
		table->philo[i].iAte = 0;
		/*table->philo[i].alive = true;*/
		table->philo[i].last_meal_time = 0;
		table->philo[i].left_fork = &table->fork[i];
		table->philo[i].right_fork = &table->fork[(i + 1) % table->numb_philo];
		i++;
	}
	if (table->numb_philo == 1)
	{
		printf("%sPhilosopher 0 has taken a fork%s\n", YELLOW, RESET);
		ft_usleep(table->time_to_eat);
	}
}