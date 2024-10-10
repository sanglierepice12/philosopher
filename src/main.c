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
		if (table.philo[i].i_ate == table.philo->table->max_meal)
		{
			table.philo_ate_max++;
			printf("ate max = %d\n", table.philo_ate_max);
			printf("max meal = %d\n", table.max_meal);
			printf("max meal = %d\n", table.numb_philo);
			if (table.philo_ate_max == table.numb_philo)
				table.simulation_on = false;
		}
		if (i + 1 == table.numb_philo)
			i = 0;
		else
			i++;
	}
	ft_join_threads(&table);
	ft_destroy_mutex(&table);
	return (0);
}
