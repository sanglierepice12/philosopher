/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsuter <gsuter@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:39:44 by gsuter            #+#    #+#             */
/*   Updated: 2024/08/28 15:39:44 by gsuter           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

typedef struct s_philinfo
{
	bool	die;
}	t_philinfo;

typedef struct s_philosopher
{
	t_philinfo	*philinfo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		need_eat;
}	t_philosopher;

/*----------INIT_ARGS----------*/
void	ft_init_args(char **argv);

/*----------UTILS----------*/
long	set_time();
int	ft_atoi(const char *str);

#endif
