/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42ISTANBUL.COM.TR>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:40:01 by aabduvak          #+#    #+#             */
/*   Updated: 2022/04/15 16:45:57 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	threads_start(t_table *table)
{
	int	i;

	pthread_mutex_init(&table->is_diying, NULL);
	pthread_mutex_init(&table->is_printing, NULL);
	pthread_mutex_init(table->death_check, NULL);
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
	i = -1;
	philo_check_death(table);
	while (++i < table->count && table->count != 1)
		pthread_join(table->philo[i].thread, NULL);
}

void	threads_wait(t_table *table)
{
	int	i;

	time_usleep(100);
	i = -1;
	while (++i < table->count)
		pthread_mutex_destroy(table->forks + i);
	pthread_mutex_destroy(&table->is_printing);
	free(table->death_check);
	pthread_mutex_destroy(table->death_check);
	i = -1;
	while (++i < table->count)
	{
		free((table->philo + i)->last_eat_check);
		free((table->philo + i)->n_eat_check);
		free((table->philo + i)->state_check);
	}
	free(table->philo);
	free(table->forks);
	free(table);
}
