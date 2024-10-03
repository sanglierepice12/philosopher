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
		ft_exit_msg(1, "Wrong argument");
	if (!ft_atoi(argv[2]))
		ft_exit_msg(1, "Wrong argument");
	if (!ft_atoi(argv[3]))
		ft_exit_msg(1, "Wrong argument");
	if (!ft_atoi(argv[4]))
		ft_exit_msg(1, "Wrong argument");
	if (argv[5] && !ft_atoi(argv[5]))
		ft_exit_msg(1, "Wrong argument");
}