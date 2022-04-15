/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42ISTANBUL.COM.TR>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:40:01 by aabduvak          #+#    #+#             */
/*   Updated: 2022/04/15 02:44:51 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	threads_start(t_table *table)
{
	size_t	i;

	pthread_mutex_init(&table->is_diying, NULL);
	pthread_mutex_init(&table->is_printing, NULL);
	i = -1;
	while (++i < table->count)
		philo_init(table->philo + i, table, i);
	i = -1;
	while (++i < table->count)
		philo_forks_init(table->philo + i, table, i);
	i = -1;
	while (++i < table->count)
		pthread_create(&table->philo[i].thread, NULL, \
				philo_routine, table->philo + i);
	philo_check_death(table);
}

void	threads_wait(t_table *table)
{
	size_t	i;

	time_usleep(100);
	i = -1;
	while (++i < table->count)
		pthread_mutex_destroy(table->forks + i);
	pthread_mutex_destroy(&table->is_printing);
	free(table->philo);
	free(table->forks);
	free(table);
}
