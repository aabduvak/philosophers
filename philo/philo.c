/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:51:04 by aabduvak          #+#    #+#             */
/*   Updated: 2022/04/12 02:04:51 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_philo *philo, t_table *table, int id)
{
	philo->id = id + 1;
	philo->table = table;
	philo->n_eat = 0;
	philo->state = INITIAL;
	philo->last_eat = time_get_millis_now();
	pthread_mutex_init(&table->forks[id], NULL);
}

void	philo_forks_init(t_philo *philo, t_table *table, int id)
{
	if (id - 1 < 0)
		philo->lfork = table->forks + (table->count - 1);
	else
		philo->lfork = table->forks + (id - 1);
	philo->rfork = table->forks + id;
}

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	if (philo->id % 2 == 0)
		time_usleep(10);
	while (!philo->table->death)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

size_t	philo_check_eat(t_table *table)
{
	size_t	i;

	if (table->min_to_eat < 0)
		return (0);
	i = -1;
	while (++i < table->count)
	{
		if (table->philo[i].n_eat < table->min_to_eat)
			return (0);
	}
	return (1);
}

void	philo_check_death(t_table *table)
{
	size_t	i;

	if (table->count == 1)
		print(table->philo, HAS_DIED);
	while (table->count > 1)
	{
		i = -1;
		while (++i < table->count)
		{
			if (table->philo[i].state == EATING)
				continue ;
			pthread_mutex_lock(&table->is_diying);
			if (time_get_millis_now() - \
			table->philo[i].last_eat >= table->time_to_die)
			{
				print(table->philo + i, HAS_DIED);
				table->death = 1;
				return ;
			}
			pthread_mutex_unlock(&table->is_diying);
		}
		if (philo_check_eat(table))
			break ;
	}
	table->death = 1;
}
