/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 01:17:51 by aabduvak          #+#    #+#             */
/*   Updated: 2022/04/11 01:31:41 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*parse_args(int argc, char **argv)
{
	t_table	*table;

	if (!check_args(argc, argv))
		return (NULL);
	table = (t_table *) malloc(sizeof(table));
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
	table->philos = (t_philo *) malloc(sizeof(t_philo) * table->count);
	table->philos = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * \
		table->count);
	table->time = time_get_now();
	return (table);
}
