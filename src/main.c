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

	if (arc < 5 || arc > 6)
		return (printf("Wrong argument number\n"));
	ft_check_args(argv);
	ft_init_table(argv, &table);
	ft_init_philo(&table);
	ft_init_threads(&table);
	int i = 0;
	while (!ft_simulation_is_ended(&table.philo[i]))
	{
		ft_die(table.philo);
		i++;
		if (i + 1 == table.numb_philo)
			i = 0;
	}
	ft_join_threads(&table);
	ft_destroy_mutex(&table);
	printf("%sEND OF THE SIMULATION%s", MAGENTA, RESET);
	return (0);
}