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

/********HEADERS******/
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <pthread.h>

/****VARIABLES****/
# define DIE 1
# define ALIVE 0
# define PHILO_MAX 200

/****COLORS*****/
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

/*******STRUCTURES*******/

typedef struct s_fork
{
	pthread_mutex_t	fork;
}	t_fork;

typedef struct	s_philosopher
{
	int				id;
	unsigned int	time_eaten;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_t		thread;
}	t_philo;

typedef struct s_table
{
	int		count_philo;
	t_philo	philo[PHILO_MAX];
	t_fork	fork[PHILO_MAX];
}	t_table;

/************UTILS**********/
long	set_time();
int		ft_atoi(const char *str);
void	ft_check_args(char **argv);

/************INIT_ARGS**********/
void	ft_init_philo(char **argv, t_table *table);
//void	ft_init_args(char **argv, t_philosopher *philosopher);

/**EXIT**/
void	ft_exiting(int h);
void	ft_end_all(t_table *table);

#endif
