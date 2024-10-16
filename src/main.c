/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:27:52 by gsuter            #+#    #+#             */
/*   Updated: 2024/08/28 15:27:52 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	main(int arc, char **argv)
{
	t_table	table;
	int		i;

	if (arc < 5 || arc > 6)
		return (printf("Wrong argument number\n"));
	ft_check_args(argv);
	ft_init_table(argv, &table);
	ft_init_philo(&table);
	ft_init_threads(&table);
	i = 0;
	while (!ft_simulation_is_ended(&table))
	{
		ft_die(&table.philo[i]);
		/*if (table.philo[i].i_ate == table.philo->table->max_meal && !table.philo[i].has_eaten_max)
		{
			table.philo[i].has_eaten_max = true;
			table.philo_ate_max++;
			if (table.philo_ate_max == table.numb_philo)
				table.simulation_on = false;
		}*/
		pthread_mutex_lock(&table.eater_mutex);
		if (table.philo_ate_max == table.numb_philo)
			table.simulation_on = false;
		pthread_mutex_unlock(&table.eater_mutex);
		i = (i + 1) % table.numb_philo;
	}
	ft_join_threads(&table);
	ft_destroy_mutex(&table);
	return (0);
}
