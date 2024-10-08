/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostr <gostr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:44:08 by gostr             #+#    #+#             */
/*   Updated: 2024/09/22 14:44:08 by gostr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosopher.h"

void	ft_destroy_mutex(t_table *table)
{
	int	i;

	i = 0;

	while (i < table->numb_philo)
	{
		pthread_mutex_destroy(&table->fork[i].mutex);
		pthread_mutex_destroy(&table->philo[i].philo_mutex);
		i++;
	}
	pthread_mutex_destroy(&table->table_mutex);
}

void	ft_exiting(bool flag, t_table *table)
{
	if (flag)
		ft_destroy_mutex(table);
	exit(EXIT_FAILURE);
}

void	ft_exit_msg(int code, char	*msg)
{
	printf("%s\n", msg);
	exit(code);
}
