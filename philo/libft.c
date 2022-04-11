/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabduvak <aabduvak@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 00:52:17 by aabduvak          #+#    #+#             */
/*   Updated: 2022/04/11 00:56:00 by aabduvak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\v'
		|| c == '\n' || c == '\f' || c == '\r');
}

static int	ft_atoi_overflow(int sign)
{
	if (sign < 0)
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{
	unsigned long	nbr;
	int				sign;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	nbr = 0;
	while (ft_isdigit(*str))
	{
		if ((nbr * 10 + (*str - '0')) / 10 != nbr)
			return (ft_atoi_overflow(sign));
		nbr *= 10;
		nbr += *str - '0';
		str++;
	}
	return (sign * nbr);
}
