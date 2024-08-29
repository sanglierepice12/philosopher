/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:27:52 by gsuter            #+#    #+#             */
/*   Updated: 2024/08/28 15:27:52 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	main(int arc, char **argv)
{
	t_philosopher	philosopher[200];
	if (arc < 5 || arc > 6)
		return (printf("Wrong argument number\n"));
	ft_check_args(argv);
	ft_init_args(argv, philosopher);


	//PRINT INFOS PHILO
	int i = 0;
	while (i < ft_atoi(argv[1]))
	{
		printf("philo [%d]\n----\ndie = %lu\neat = %lu\nsleep = %lu\n", i,
			   philosopher[i].time_to_die, philosopher[i].time_to_eat,
			   philosopher[i].time_to_sleep);
		if (arc > 5)
			printf("needeat = %d\n---\n", philosopher[i].need_eat);
		printf("isdie = %d\n\n", philosopher[i].state.is_die);
		printf("fork = %d\n\n", philosopher[i].state.fork);
		i++;
	}
	//


	return (0);
}

//
// init les philo
//->faire attendre les threads avec une var
// init les thread
// cree routine
