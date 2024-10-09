/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:26:11 by gsuter            #+#    #+#             */
/*   Updated: 2024/08/29 14:26:11 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosopher.h"

int	ft_isdigit(int nb)
{
	if (nb > 47 && nb < 58)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		result;
	ssize_t	i;
	int		minus;

	minus = 1;
	i = -1;
	result = 0;
	while (++i, (str[i] > 8 && str[i] < 14) || str[i] == 32)
		;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (str[i])
		return (0);
	return (result * minus);
}
