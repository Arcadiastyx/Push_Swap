/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:11:28 by inaranjo          #+#    #+#             */
/*   Updated: 2023/05/02 13:10:52 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_nb(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (!(str[i] >= '0' && str[i] <= '9')
			&& !(str[i] == '+' || str[i] == '-'))
		{
			ft_error();
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{	
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i + 1] == '-' || str[i + 1] == '+')
			{
				ft_error();
				return (0);
			}
			else if (str[i + 1] == '\0' || str[i] == '\0')
			{
				ft_error();
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	check_double(t_input *args)
{
	int	i;
	int	j;

	i = 0;
	while (i < args->size)
	{
		j = i + 1;
		while (j < args->size)
		{
			if (args->array[i] == args->array[j])
			{
				ft_error();
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_mod(char *str)
{
	int		i;
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res * sign > INT_MAX || res * sign < INT_MIN)
		ft_error();
	return (res * sign);
}

int	check_args_process(char *str)
{
    if (!(check_nb(str)))
        return (0);
    if (!(check_sign(str)))
        return (0);
    return (1);
}