/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   road.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostr <gostr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:46:52 by gostr             #+#    #+#             */
/*   Updated: 2024/10/02 12:46:52 by gostr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosopher.h"

bool	ft_die(t_philo *philo)
{
	if (set_time(philo->table) - philo->time_eaten > philo->table->time_to_die)
	{
		philo->table->alive = false;
		printf("%sPhilosopher %d is dead at %lld ms%s\n", RED, philo->id, set_time(philo->table) - philo->table->begin_time, RESET);
		//pthread_mutex_unlock(&philo->table->table_var);
		return (true);//ft_exiting(1, philo->table);
	}
	return (false);
	/*philo->table->alive = false;
	printf("%sPhilosopher %d is dead at %lld ms%s\n", RED, philo->id, set_time(philo->table) - philo->table->begin_time, RESET);*/
}

int	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->table_var);
	pthread_mutex_lock(&philo->philo_var);
	if (!philo->table->alive)
		return (ft_unlock_one_all_mutex(philo), 0);
	printf("%sPhilosopher %d sleep at %lld ms%s\n", BLUE, philo->id, set_time(philo->table) - philo->table->begin_time, RESET);

	// Sleep
	ft_usleep(philo, philo->table->time_to_sleep);
	pthread_mutex_unlock(&philo->table->table_var);
	pthread_mutex_unlock(&philo->philo_var);
	return (1);
}

int ft_eat(t_philo *philo)
{
	// Takes fork
	pthread_mutex_lock(&philo->table->table_var);
	pthread_mutex_lock(&philo->philo_var);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->left_fork->fork);
		pthread_mutex_lock(&philo->right_fork->fork);
	}
	else
	{
		pthread_mutex_lock(&philo->right_fork->fork);
		pthread_mutex_lock(&philo->left_fork->fork);
	}

	// Philo still alive ?
	if (!philo->table->alive)
		return (ft_unlock_one_all_mutex(philo), 0);
	printf("%sPhilosophe %d eat at %lld ms%s\n", YELLOW, philo->id, set_time(philo->table) - philo->table->begin_time, RESET);
	philo->time_eaten = set_time(philo->table);

	// Eat
	ft_usleep(philo, philo->table->time_to_eat);
	printf("Philosophe %d eaten at %lld ms\n", philo->id, set_time(philo->table) - philo->time_eaten);
	pthread_mutex_unlock(&philo->table->table_var);
	pthread_mutex_unlock(&philo->right_fork->fork);
	pthread_mutex_unlock(&philo->left_fork->fork);
	pthread_mutex_unlock(&philo->philo_var);

	return (1);
}

void	*ft_philo_road(void *data)
{
	t_philo		*philo;

	philo = (t_philo *)data;
	philo->time_eaten = set_time(philo->table);
	while (philo->table->alive && philo->alive)
	{
		pthread_mutex_lock(&philo->table->table_var);
		if (ft_die(philo)) {
			philo->table->alive = false; // Arrêter tous les philosophes s'il y a une mort
			pthread_mutex_unlock(&philo->table->table_var);
			break ; // Sortir de la boucle si le philosophe est mort
		}
		pthread_mutex_unlock(&philo->table->table_var);
		// Vérifier si le temps total des actions dépasse time_to_die
		/*pthread_mutex_lock(&philo->table->table_var);
		if (set_time(philo->table) - philo->time_eaten > philo->table->time_to_die)
		{
			philo->table->alive = false;
			printf("%sPhilosopher %d is dead at %lld ms%s\n", RED, philo->id, set_time(philo->table) - philo->table->begin_time, RESET);
			pthread_mutex_unlock(&philo->table->table_var);
			break;
		}
		pthread_mutex_unlock(&philo->table->table_var);*/
		// Eat
		if (!ft_eat(philo))
			break ;
		// Sleep
		if (!ft_sleep(philo))
			break ;
		// Think
		if (philo->table->alive && philo->alive)
			printf("%sPhilosopher %d think at %lld ms%s\n", GREEN, philo->id, set_time(philo->table) - philo->table->begin_time, RESET);
	}

	return (NULL);
}
