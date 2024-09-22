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
	struct	timeval tv;
	struct	timezone tz;

	if (gettimeofday(&tv,&tz))
		ft_exiting();
	return (tv.tv_sec * 1000 + tv.tv_usec / 10000);
}

void	ft_usleep(t_philo *philo, long long time)
{
	long long	begin;

	begin = set_time();
	while (philo->alive == true)
	{
		if (set_time() - begin >= time)
			break ;
		usleep(50);
	}
}
