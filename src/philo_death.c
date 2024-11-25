/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:09:16 by kpourcel          #+#    #+#             */
/*   Updated: 2024/11/25 14:15:18 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_death(t_data *data, t_philo *philo, int i)
{
	while (++i < data->nbr_philo && !(data->is_dead))
	{
		pthread_mutex_lock(&(data->mutex_sim));
		if ((get_time() - philo[i].time_since_meal) > data->ttd)
		{
			print_philo_status(data, i + 1, "is dead");
			data->is_dead = 1;
		}
		pthread_mutex_unlock(&(data->mutex_sim));
		usleep(100);
	}
}

void	death_checker(t_data *data, t_philo *philo)
{
	int		i;

	while (1)
	{
		i = -1;
		philo_death(data, philo, i);
		if (data->is_dead)
			break ;
		i = 0;
		pthread_mutex_lock(&(data->mutex_sim));
		while (data->meal_limit != -1 && i < data->nbr_philo
			&& philo[i].meals >= data->meal_limit)
			i++;
		if (i == data->nbr_philo)
		{
			data->check_eat = 1;
			pthread_mutex_unlock(&(data->mutex_sim));
			end_simulation(data);
			pthread_mutex_lock(&(data->mutex_sim));
		}
		pthread_mutex_unlock(&(data->mutex_sim));
	}
}
