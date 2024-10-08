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
	while (!ft_simulation_is_ended(&table.philo[i]) && table.philo->iAte != table.philo->table->max_meal)
	{
		//printf("END");
		ft_die(&table.philo[i]);
		i++;
		if (i + 1 == table.numb_philo)
			i = 0;
	}
	//printf("END");
	ft_join_threads(&table);
	//printf("END2222");
	ft_destroy_mutex(&table);
	printf("END3333");
	printf("%sEND OF THE SIMULATION%s", MAGENTA, RESET);
	return (0);
}