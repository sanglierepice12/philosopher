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

long long	set_time()
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);

}

int	ft_usleep(long long milliseconds)
{
	long long	start;

	start = set_time();
	while ((set_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

/*void	ft_usleep(t_philo *philo, long long time)
{
	long long	begin;

	begin = set_time(philo->table);
	if (ft_die(philo))
		return ;
	while (philo->table->alive)
	{
		if (set_time(philo->table) - begin >= time)
			break ;
		usleep(50);
	}
}*/
