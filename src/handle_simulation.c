/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_simulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:37:42 by kpourcel          #+#    #+#             */
/*   Updated: 2024/11/22 15:42:13 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	end_simulation(t_data *data)
{
	t_philo *philo;
	int		i;

	i = 0;
	philo = data->philos;
	while (i < data->nbr_philo)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
	i = 0;
	while (++i < data->nbr_philo)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->mutex_eat));
	pthread_mutex_destroy(&(data->mutex_print));
	free(data->forks);
	free(data->philos);
	exit (0);
}
