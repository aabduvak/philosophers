/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42ISTANBUL.COM.TR>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:56:49 by aabduvak          #+#    #+#             */
/*   Updated: 2022/04/15 02:51:14 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_use_fork(t_philo *philo,
			int (*mutex_action)(), char *message)
{
	philo->state = TAKING;
	mutex_action(philo->lfork);
	print(philo, message);
	mutex_action(philo->rfork);
	print(philo, message);
	philo->state = INITIAL;
}

void	philo_eat(t_philo *philo)
{
	philo_use_fork(philo, pthread_mutex_lock, HAS_TAKEN_A_FORK);
	philo->last_eat = time_get_millis_now();
	print(philo, IS_EATING);
	philo->state = EATING;
	time_usleep(philo->table->time_to_eat);
	philo->state = INITIAL;
	philo->n_eat++;
	philo_use_fork(philo, pthread_mutex_unlock, NULL);
}

void	philo_sleep(t_philo *philo)
{
	print(philo, IS_SLEEPING);
	philo->state = SLEEPING;
	time_usleep(philo->table->time_to_sleep);
	philo->state = INITIAL;
}

void	philo_think(t_philo *philo)
{
	philo->state = THINKING;
	print(philo, IS_THINKING);
	philo->state = INITIAL;
}
