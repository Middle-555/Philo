/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:29:17 by kpourcel          #+#    #+#             */
/*   Updated: 2024/11/22 13:59:59 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * @brief Print an error and exit the program.
 * 
 * @param str 
 */
void	error_msg(char *str)
{
	printf("Error:\n");
	printf("%s\n", str);
	exit(1);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * @brief Check is there is only numbers.
 * 
 * @param c 
 * @return int 
 */

int	ft_isdigit_str(char *str)
{
	if (!*str)
		return (0);
	while (*str)
	{
		if (!(ft_isdigit(*str)))
			return (0);
		str++;
	}
	return (1);
}

/**
 * @brief Check if its space;
 * 
 * @param c 
 * @return int 
 */
int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

/**
 * @brief Modififed version of atol. We exit if the number is negative.
 * 
 * @param str 
 * @return long 
 */

long	ft_atol(const char *str)
{
	long	result;

	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		error_msg("The value needs to be positive");
	if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		if (result > (INT_MAX - (*str - '0')) / 10)
			error_msg("Value must be between 0 and MAX INT");
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0')
		error_msg("Invalid number format");
	return (result);
}
