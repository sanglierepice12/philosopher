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

# define DIE 1
# define ALIVE 0

typedef struct s_state
{
	bool	is_die;
	bool	fork;
}	t_state;

typedef struct s_philosopher
{
	t_state		state;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	int			need_eat;
	long		start_time;
}	t_philosopher;

/*----------UTILS----------*/
long	set_time();
int		ft_atoi(const char *str);
void	ft_check_args(char **argv);

/*----------INIT_ARGS----------*/
void	ft_init_args(char **argv, t_philosopher *philosopher);

#endif
