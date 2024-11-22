/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:09:21 by kpourcel          #+#    #+#             */
/*   Updated: 2024/11/22 16:18:03 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	sim_init(t_data *data)
{
	int		i;
	t_philo *philo;
	
	i = 0;
	philo = data->philos;

	data->start = get_time();
	while (i < data->nbr_philo)
	{
		pthread_create(&(philo[i].thread_id), NULL, philo_routine, &(philo[i]));
		pthread_mutex_lock(&(data->mutex_eat));
		philo[i].time_since_meal = get_time();
		pthread_mutex_unlock(&(data->mutex_eat));
		i++;
	}
	death_checker(data, philo);
	end_simulation(data);
}

void	init_data(int argc, char **argv, t_data *data)
{
	data->nbr_philo = ft_atol(argv[1]);
	data->ttd = ft_atol(argv[2]);
	data->tte = ft_atol(argv[3]);
	data->tts = ft_atol(argv[4]);
	data->check_eat = 0;
	data->is_dead = 0;
	if (argc == 6)
		data->meal_limit = ft_atol(argv[5]);
	else
		data->meal_limit = -1;
	data->forks = safe_malloc(sizeof(pthread_mutex_t) * data->nbr_philo);
	data->philos = safe_malloc(sizeof(t_philo) * data->nbr_philo);
	init_mutex(data);
	sim_init(data);
}

void	init_mutex(t_data *data)
{
	int i;

	i = data->nbr_philo;
	pthread_mutex_init(&(data->mutex_print), NULL);
	pthread_mutex_init(&(data->mutex_eat), NULL);
	while (--i >= 0)
	{
		pthread_mutex_init(&(data->forks[i]), NULL);
		data->philos[i].philo_id = i + 1;
		data->philos[i].meals = 0;
		if (data->philos[i].philo_id % 2 == 0) 
		{
			data->philos[i].left_fork = i;
			data->philos[i].right_fork = (i + 1) % data->nbr_philo;
		}
		else
		{
			data->philos[i].left_fork = (i + 1) % data->nbr_philo;
			data->philos[i].right_fork = i;
		}
		data->philos[i].time_since_meal = 0;
		data->philos[i].data = data;
	}
}
