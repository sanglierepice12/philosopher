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
# define PHILOSOPHER_H

/**HEADERS**/
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <pthread.h>

typedef enum T_STATUS
{
	FORK,
	EAT,
	SLEEP,
	DEAD,
	THINK
}	t_STATUS;

/**STRUCTURES**/
typedef struct s_fork
{
	int						id;
	pthread_mutex_t			mutex;
}	t_fork;

typedef struct s_philosopher
{
	struct timeval			death_time;
	pthread_t				thread;
	int						id;
	int						i_ate;
	long long				last_meal_time;
	t_fork					*left_fork;
	t_fork					*right_fork;
	struct s_table			*table;
}	t_philo;

typedef struct s_table
{
	bool					simulation_on;
	int						numb_philo;
	long long				time_to_die;
	long long				time_to_eat;
	long long				time_to_sleep;
	int						max_meal;
	int						philo_ate_max;
	long long				start_simulation;
	pthread_mutex_t			end_simulation_mutex;
	pthread_mutex_t			print_mutex;
	pthread_mutex_t			start_mutex;
	pthread_mutex_t			time_mutex;
	pthread_mutex_t			table_mutex;
	t_fork					fork[200];
	t_philo					philo[200];
}	t_table;

/**UTILS**/
long long					set_time(void);
int							ft_usleep(long long milliseconds);
int							ft_atoi(const char *str);
void						ft_check_args(char **argv);
bool						ft_simulation_is_ended(t_table *table);
void						ft_mutex_print(t_philo *philo, t_STATUS STATUS, \
								long long time);
bool						ft_l_fork_tester(t_philo *philo);
bool						ft_r_fork_tester(t_philo *philo);
void						ft_add_ms_time_val(struct timeval *tv, \
								long milliseconds);

/**INIT_ARGS**/
void						ft_init_table(char **argv, t_table *table);
void						ft_init_philo(t_table *table);

/**THREADS**/
void						ft_init_threads(t_table *table);
void						*ft_philo_road(void *data);
void						ft_join_threads(t_table *table);
void						ft_eat(t_philo *philo);
void						ft_die(t_philo *philo);
void						ft_sleep(t_philo *philo);

/**EXIT**/
void						ft_exiting(bool flag, t_table *table);
void						ft_exit_msg(int code, char	*msg);
void						ft_destroy_mutex(t_table *table);

/**COLORS**/
# define RESET	"\033[0m"
# define BLACK	"\033[30m"
# define RED		"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN	"\033[36m"
# define WHITE	"\033[37m"

#endif