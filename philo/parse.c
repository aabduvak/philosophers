/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42ISTANBUL.COM.TR>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 01:17:51 by aabduvak          #+#    #+#             */
/*   Updated: 2022/04/15 16:42:47 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*parse_args(int argc, char **argv)
{
	t_table	*table;

	if (!check_args(argc, argv))
		return (NULL);
	table = (t_table *) malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->count = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc - 1 == MAX_ARGS)
		table->min_to_eat = ft_atoi(argv[MAX_ARGS]);
	else
		table->min_to_eat = -1;
	table->death = 0;
	table->philo = malloc(sizeof(t_philo) * (table->count + 1));
	table->forks = malloc(sizeof(pthread_mutex_t) * (table->count + 1));
	table->time = time_get_now();
	table->death_check = malloc(sizeof(pthread_mutex_t));
	return (table);
}
