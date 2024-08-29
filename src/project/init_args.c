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

void	ft_check_args(char **argv)
{
	if (!ft_atoi(argv[1]))
		exit(1);
	if (!ft_atoi(argv[2]))
		exit(1);
	if (!ft_atoi(argv[3]))
		exit(1);
	if (!ft_atoi(argv[4]))
		exit(1);
	if (argv[5] && !ft_atoi(argv[5]))
		exit(1);
}

void	ft_init_args(char **argv)
{
	t_philosopher	philosopher;
	size_t			i;

	ft_check_args(argv);
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philosopher.time_to_die = ft_atoi(argv[2]);
		philosopher.time_to_eat = ft_atoi(argv[3]);
		philosopher.time_to_sleep = ft_atoi(argv[4]);
		if (argv[5])
			philosopher.need_eat = ft_atoi(argv[5]);
	}
}