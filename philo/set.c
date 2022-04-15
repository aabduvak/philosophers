/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42ISTANBUL.COM.TR>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:31:26 by aabduvak          #+#    #+#             */
/*   Updated: 2022/04/15 16:32:04 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_death_value(t_table *table, int value)
{
	pthread_mutex_lock(table->death_check);
	table->death = value;
	pthread_mutex_unlock(table->death_check);
}

void	set_state(t_philo *philo, t_state value)
{
	pthread_mutex_lock(philo->state_check);
	philo->state = value;
	pthread_mutex_unlock(philo->state_check);
}

void	set_last_meal(t_philo *philo, size_t value)
{
	pthread_mutex_lock(philo->last_eat_check);
	philo->last_eat = value;
	pthread_mutex_unlock(philo->last_eat_check);
}

void	set_n_eat(t_philo *philo, int value)
{
	pthread_mutex_lock(philo->n_eat_check);
	philo->n_eat = value;
	pthread_mutex_unlock(philo->n_eat_check);
}
