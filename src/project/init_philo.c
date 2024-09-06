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

void	*print_done()
{
	printf("%sdone\n%s", RED, RESET);
	return (NULL);
}

void	init_threads_philosophers(t_philosopher *philosopher)
{
	int	i;

	i = 0;
	while (i < philosopher[i].total_philo)
	{
		pthread_create(&philosopher[i].thread, NULL, print_done, &philosopher[i]);
		i++;
	}
}

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
}