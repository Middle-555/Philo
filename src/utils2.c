/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:00:24 by kpourcel          #+#    #+#             */
/*   Updated: 2024/11/22 14:00:41 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// malloc + check
void	*safe_malloc(size_t size)
{
	void	*dst;

	dst = malloc(size);
	if (!dst)
		error_msg("Malloc error");
	return (dst);
}

// tv_sec = numbers of second since 1rst january 1970
// tv_usec = numbers of microsecond since the last second
// everything is converd to milliseconds.
long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	one_philo_case(long ttd)
{
	long long	current_time;

	current_time = get_time();
	printf("%4lli 1 has taken a fork\n", current_time);
	usleep(ttd * 1000);
	current_time = get_time();
	printf("%4lli 1 is dead\n", current_time + ttd);
	error_msg("Philo 1 is dead");
}
