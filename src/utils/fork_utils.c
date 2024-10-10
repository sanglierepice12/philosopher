/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:21:18 by gsuter            #+#    #+#             */
/*   Updated: 2024/10/08 14:21:18 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosopher.h"

bool	ft_l_fork_tester(t_philo *philo)
{
	if (philo->left_fork->id == 0)
	{
		pthread_mutex_lock(&philo->left_fork->mutex);
		philo->left_fork->id = 1;
		ft_mutex_print(philo, FORK, set_time(philo->table) - \
			philo->table->start_simulation);
		pthread_mutex_unlock(&philo->left_fork->mutex);
	}
	else
		return (false);
	return (true);
}

bool	ft_r_fork_tester(t_philo *philo)
{
	if (philo->right_fork->id == 0)
	{
		pthread_mutex_lock(&philo->right_fork->mutex);

		philo->right_fork->id = 1;
		ft_mutex_print(philo, FORK, set_time(philo->table) - \
			philo->table->start_simulation);
		pthread_mutex_unlock(&philo->right_fork->mutex);
	}
	else
		return (false);
	return (true);
}
