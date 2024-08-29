/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostr <gostr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:22:40 by gostr             #+#    #+#             */
/*   Updated: 2024/08/29 18:22:40 by gostr            ###   ########.fr       */
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