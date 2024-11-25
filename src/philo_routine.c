/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:42:28 by kpourcel          #+#    #+#             */
/*   Updated: 2024/11/25 14:15:45 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_routine(void *philo)
{
	t_philo		*philosopher;
	t_data		*data;
	int			i;

	i = 0;
	philosopher = (t_philo *)philo;
	data = philosopher->data;
	if (philosopher->philo_id % 2 == 0)
		usleep(1500);
	pthread_mutex_lock(&(data->mutex_sim));
	while (!(data->is_dead) && !(data->check_eat))
	{
		pthread_mutex_unlock(&(data->mutex_sim));
		eat(philosopher);
		pthread_mutex_lock(&(data->mutex_sim));
		print_philo_status(data, philosopher->philo_id, "is sleeping");
		pthread_mutex_unlock(&(data->mutex_sim));
		philo_wait(data->tts, data);
		pthread_mutex_lock(&(data->mutex_sim));
		print_philo_status(data, philosopher->philo_id, "is thinking");
		i++;
	}
	pthread_mutex_unlock(&(data->mutex_sim));
	return (NULL);
}

void	eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&(data->forks[philo->left_fork]));
	pthread_mutex_lock(&(data->mutex_sim));
	print_philo_status(data, philo->philo_id, "has taken left fork");
	pthread_mutex_unlock(&(data->mutex_sim));
	pthread_mutex_lock(&(data->forks[philo->right_fork]));
	pthread_mutex_lock(&(data->mutex_sim));
	print_philo_status(data, philo->philo_id, "has taken right fork");
	print_philo_status(data, philo->philo_id, "is eating");
	philo->time_since_meal = get_time();
	pthread_mutex_unlock(&(data->mutex_sim));
	philo_wait(data->tte, data);
	pthread_mutex_lock(&(data->mutex_sim));
	(philo->meals)++;
	pthread_mutex_unlock(&(data->mutex_sim));
	pthread_mutex_unlock(&(data->forks[philo->right_fork]));
	pthread_mutex_unlock(&(data->forks[philo->left_fork]));
}

void	philo_wait(long time, t_data *data)
{
	long	i;

	i = get_time();
	pthread_mutex_lock(&(data->mutex_sim));
	while (!(get_time() - i >= time) && !(data->is_dead))
	{
		pthread_mutex_unlock(&(data->mutex_sim));
		usleep(50);
		pthread_mutex_lock(&(data->mutex_sim));
	}
	pthread_mutex_unlock(&(data->mutex_sim));
}
