/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42ISTANBUL.COM.TR>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 00:56:49 by aabduvak          #+#    #+#             */
/*   Updated: 2022/04/15 15:16:21 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_use_fork(t_philo *philo,
			int (*mutex_action)(), char *message)
{
	set_state(philo, TAKING);
	mutex_action(philo->lfork);
	print(philo, message);
	mutex_action(philo->rfork);
	print(philo, message);
	set_state(philo, INITIAL);
}

void	philo_eat(t_philo *philo)
{
	philo_use_fork(philo, pthread_mutex_lock, HAS_TAKEN_A_FORK);
	set_last_meal(philo, time_get_millis_now());
	print(philo, IS_EATING);
	set_state(philo, EATING);
	time_usleep(philo->table->time_to_eat);
	set_state(philo, INITIAL);
	philo->n_eat++;
	philo_use_fork(philo, pthread_mutex_unlock, NULL);
}

void	philo_sleep(t_philo *philo)
{
	print(philo, IS_SLEEPING);
	set_state(philo, SLEEPING);
	time_usleep(philo->table->time_to_sleep);
	set_state(philo, INITIAL);
}

void	philo_think(t_philo *philo)
{
	set_state(philo, THINKING);
	print(philo, IS_THINKING);
	set_state(philo, INITIAL);
}
