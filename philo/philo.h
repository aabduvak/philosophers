/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:34:04 by aabduvak          #+#    #+#             */
/*   Updated: 2022/04/11 01:39:16 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

/* ************************* DEFINES ************************** */

# define MIN_ARGS			4
# define MAX_ARGS			5

# define HAS_TAKEN_A_FORK	"has taken a fork"
# define IS_EATING			"is eating"
# define IS_SLEEPING		"is sleeping"
# define IS_THINKING		"is thinking"
# define HAS_DIED			"died"

/* ************************* STRUCT ************************** */

typedef enum e_state
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
	TAKING,
}	t_state;

typedef struct s_philo
{
	size_t			id;
	pthread_t		thread;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;

	int				eating;
	size_t			last_eat;
	int				n_eat;
	int				sleeping;
	t_state			state;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	pthread_mutex_t	*forks;
	t_philo			*philos;
	size_t			count;

	size_t			time_to_sleep;
	size_t			time_to_eat;
	size_t			time_to_die;
	int				min_to_eat;
	int				death;

	struct timeval	time;
	pthread_mutex_t	is_diying;
	pthread_mutex_t	is_printing;
}	t_table;

/* ************************* LIBFT FUNCTIONS ************************** */

int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_isspace(int c);

/* ************************* ARG CHECKER ************************** */

int				check_negative(const char *str);
int				check_int(const char *str);
int				check_args(int argc, char **argv);

/* ************************* PARSE ************************** */

t_table			*parse_args(int argc, char **argv);

/* ************************* PRINT ************************** */

int				print_error(char *where, char *message, int error_code);

/* ************************* TIME ************************** */

struct timeval	time_get_now(void);
size_t			time_get_millis(struct timeval time);
size_t			time_get_millis_now(void);
size_t			time_get_millis_from_start(t_table *table);
void			time_usleep(size_t	usec);

#endif