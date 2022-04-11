/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:56:49 by aabduvak          #+#    #+#             */
/*   Updated: 2022/04/12 02:19:38 by aabduvak         ###   ########.fr       */
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
}

void	philo_eat(t_philo *philo)
{
	philo_use_fork(philo, pthread_mutex_lock, HAS_TAKEN_A_FORK);
	philo->last_eat = time_get_millis_now();
	philo->state = EATING;
	print(philo, IS_EATING);
	time_usleep(philo->table->time_to_eat);
	philo->n_eat++;
	philo_use_fork(philo, pthread_mutex_unlock, NULL);
}

void	philo_sleep(t_philo *philo)
{
	philo->state = SLEEPING;
	print(philo, IS_SLEEPING);
	time_usleep(philo->table->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	philo->state = THINKING;
	print(philo, IS_THINKING);
}
