/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:27:22 by gsuter            #+#    #+#             */
/*   Updated: 2024/10/08 16:27:22 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosopher.h"

void	ft_mutex_print(t_philo *philo, t_STATUS STATUS, long long time)
{
	pthread_mutex_lock(&philo->table->print_mutex);
	if (ft_simulation_is_ended(philo->table) && STATUS != DEAD)
	{
		pthread_mutex_unlock(&philo->table->print_mutex);
		return ;
	}
	if (STATUS == FORK)
		printf("%s%lld %d has taken a fork%s\n", YELLOW, time, \
			philo->id + 1, RESET);
	else if (STATUS == EAT)
		printf("%s%lld %d is eating%s\n", YELLOW, time, philo->id + 1, RESET);
	else if (STATUS == SLEEP)
		printf("%s%lld %d is sleeping%s\n", BLUE, time, philo->id + 1, RESET);
	else if (STATUS == THINK)
		printf("%s%lld %d is thinking%s\n", GREEN, time, philo->id + 1, RESET);
	else if (STATUS == DEAD)
	{
		philo->table->simulation_on = false;
		printf("%s%lld %d died%s\n", RED, time, philo->id + 1, RESET);
	}
	pthread_mutex_unlock(&philo->table->print_mutex);
}
