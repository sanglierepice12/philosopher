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

bool	ft_simulation_is_ended(t_philo *philo)
{
	bool	flag;

	flag = true;
	pthread_mutex_lock(&philo->table->table_mutex);
	if (philo->table->simulation_on)
	{
		pthread_mutex_unlock(&philo->table->table_mutex);
		return (flag = false, flag);
	}
	pthread_mutex_unlock(&philo->table->table_mutex);
	return (flag);
}

void	ft_check_args(char **argv)
{
	if (!ft_atoi(argv[1]))
		ft_exit_msg(1, "Invalid philosophers number\n");
	if (!ft_atoi(argv[2]))
		ft_exit_msg(1, "Invalid time to die\n");
	if (!ft_atoi(argv[3]))
		ft_exit_msg(1, "Invalid time to eat\n");
	if (!ft_atoi(argv[4]))
		ft_exit_msg(1, "Invalid time to sleep\n");
	if (argv[5])
	{
		if (!ft_atoi(argv[5]))
			ft_exit_msg(1,
				"Invalid number of times each philosopher must eat\n");
		if (ft_atoi(argv[5]) > 200)
			ft_exit_msg(1, "Invalid number of philo\n");
	}
}
