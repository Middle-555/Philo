/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:11:14 by kpourcel          #+#    #+#             */
/*   Updated: 2024/11/25 14:14:32 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <limits.h>
# include <assert.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef pthread_mutex_t	t_mtx;
typedef struct s_data	t_data;

/**
 * @brief Structure représentant un philosophe.
 */
typedef struct s_philo
{
	int					philo_id;
	int					left_fork;
	int					right_fork;
	long				meals;
	long				time_since_meal;
	pthread_t			thread_id;
	t_data				*data;
}						t_philo;

/**
 * @brief Structure contenant les données globales.
 *
 * TTS = Time to sleep, TTE = Time to eat, TTD = Time to die.
 */
typedef struct s_data
{
	//t_fork				*forks;
	t_philo				*philos;
	int					check_eat;
	int					is_dead;
	long				tts;
	long				tte;
	long				ttd;
	long				meal_limit;
	long				nbr_philo;
	pthread_mutex_t		mutex_print;
	pthread_mutex_t		mutex_sim;
	pthread_mutex_t		*forks;
	long				start;
}						t_data;

// checking_error.c
int			check_arguments(int argc, char **argv);

// data.c
void		sim_init(t_data *data);
void		init_data(int argc, char **argv, t_data *data);
void		init_mutex(t_data *data);

// handle_simulation.c
void		end_simulation(t_data *data);

// philo_death.c
void		philo_death(t_data *data, t_philo *philo, int i);
void		death_checker(t_data *data, t_philo *philo);

//philo_routine.c
void		*philo_routine(void *philo);
void		eat(t_philo *philo);
void		philo_wait(long time, t_data *data);

// utils.c
void		error_msg(char *str);
int			ft_isdigit(int c);
int			ft_isdigit_str(char *str);
int			ft_isspace(char c);
long		ft_atol(const char *str);

// utils2.c
long long	get_time(void);
void		*safe_malloc(size_t size);
void		cleanup(t_data *data);
void		one_philo_case(long ttd);
void		print_philo_status(t_data *data, int nb, char *str);

#endif
