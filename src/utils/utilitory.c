/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostr <gostr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:22:40 by gostr             #+#    #+#             */
/*   Updated: 2024/08/29 18:22:40 by gostr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosopher.h"

bool	ft_simulation_is_ended(t_table *table)
{
	pthread_mutex_lock(&table->end_simulation_mutex);
	if (table->simulation_on)
	{
		pthread_mutex_unlock(&table->end_simulation_mutex);
		return (false);
	}
	pthread_mutex_unlock(&table->end_simulation_mutex);
	return (true);
}

void	ft_check_args(char **argv)
{
	if (!ft_atoi(argv[1]))
		ft_exit_msg(1, "Invalid philosophers number");
	if (!ft_atoi(argv[2]))
		ft_exit_msg(1, "Invalid time to die");
	if (!ft_atoi(argv[3]))
		ft_exit_msg(1, "Invalid time to eat");
	if (!ft_atoi(argv[4]))
		ft_exit_msg(1, "Invalid time to sleep");
	if (argv[5])
	{
		if (!ft_atoi(argv[5]))
			ft_exit_msg(1,
				"Invalid number of times each philosopher must eat");
	}
}
