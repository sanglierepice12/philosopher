/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:06:24 by gsuter            #+#    #+#             */
/*   Updated: 2024/08/28 17:06:24 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosopher.h"

void	ft_mutex_print(t_philo *philo, E_STATUS STATUS, long long time)
{
	/*if (ft_simulation_is_ended(philo))
		return ;*/
	pthread_mutex_lock(&philo->print_mutex);
	if (STATUS == FORK)
		printf("%s%lld %d has taken a fork%s\n", YELLOW, time, philo->id + 1, RESET);
	if (STATUS == EAT)
		printf("%s%lld %d is eating%s\n", YELLOW, time, philo->id + 1, RESET);
	if (STATUS == SLEEP)
		printf("%s%lld %d is sleeping%s\n", BLUE, time, philo->id + 1, RESET);
	if (STATUS == THINK)
		printf("%s%lld %d is thinking%s\n", GREEN, time, philo->id + 1, RESET);
	if (STATUS == DEAD)
		printf("%s%lld %d died%s\n", RED, time, philo->id + 1, RESET);
	pthread_mutex_unlock(&philo->print_mutex);
}

long long	set_time(t_table *table)
{
	struct timeval	time;
	long long		actual_time;

	pthread_mutex_lock(&table->time_mutex);
	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	actual_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	pthread_mutex_unlock(&table->time_mutex);
	return (actual_time);

}

int	ft_usleep(long long milliseconds, t_table *table)
{
	long long	start;

	start = set_time(table);
	while ((set_time(table) - start) < milliseconds)
		usleep(50);
	return (0);
}
