/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:53:48 by kpourcel          #+#    #+#             */
/*   Updated: 2024/11/22 16:27:19 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_arguments(int argc, char **argv)
{
	int		i;
	long	value;
	long	ttd;

	if (argc < 5 || argc > 6)
		error_msg("Incorrect number of arguments.");
	i = 1;
	while (i < argc)
	{
		value = ft_atol(argv[i]);
		if (value <= 0)
			error_msg("Arguments must be greater than 0.");
		i++;
	}
	if (ft_atol(argv[1]) == 1)
	{
		ttd = ft_atol(argv[2]);
		one_philo_case(ttd);
	}
	return (1);
}
