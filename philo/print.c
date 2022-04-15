/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42ISTANBUL.COM.TR>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 00:59:44 by aabduvak          #+#    #+#             */
/*   Updated: 2022/04/15 14:37:21 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *philo, char *message)
{
	if (message != NULL)
	{
		pthread_mutex_lock(&philo->table->is_printing);
		if (!get_death_value(philo->table))
			printf("%zu %zu %s\n", \
				time_get_millis_from_start(philo->table), \
				philo->id, \
				message \
			);
		pthread_mutex_unlock(&philo->table->is_printing);
	}
}

int	print_error(char *where, char *message, int error_code)
{
	printf("philo: %s: %s\n", where, message);
	return (error_code);
}
