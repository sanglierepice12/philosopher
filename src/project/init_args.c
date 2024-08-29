/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:16:22 by gsuter            #+#    #+#             */
/*   Updated: 2024/08/29 14:16:22 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosopher.h"

void	ft_init_args(char **argv, t_philosopher *philosopher)
{
	int		i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philosopher[i].time_to_die = ft_atoi(argv[2]);
		philosopher[i].time_to_eat = ft_atoi(argv[3]);
		philosopher[i].time_to_sleep = ft_atoi(argv[4]);
		if (argv[5])
			philosopher[i].need_eat = ft_atoi(argv[5]);
		philosopher[i].start_time = set_time();
		philosopher[i].state.is_die = ALIVE;
		if (i == 2)
			philosopher[i].state.is_die = DIE;
		philosopher[i].state.fork = 1;
		i++;
	}
}