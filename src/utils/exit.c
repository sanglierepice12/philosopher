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

void	ft_unlock_one_all_mutex(t_philo *philo)
{
	pthread_mutex_unlock(&philo->philo_var);
	pthread_mutex_unlock(&philo->table->table_var);
	pthread_mutex_unlock(&philo->right_fork->fork);
	pthread_mutex_unlock(&philo->left_fork->fork);
}

void	ft_destroy_mutex(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->count_philo)
	{
		pthread_mutex_destroy(&table->fork[i].fork);
		pthread_mutex_destroy(&table->philo[i].philo_var);
		i++;
	}
	pthread_mutex_destroy(&table->table_var);
}

void	ft_exiting(bool flag, t_table *table)
{
	if (flag)
		ft_destroy_mutex(table);
	perror("");
	exit(EXIT_FAILURE);
}

void	ft_exit_msg(int code, char	*msg)
{
	printf("%s\n", msg);
	exit(code);
}
