/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:07:38 by inaranjo          #+#    #+#             */
/*   Updated: 2023/03/28 17:00:55 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_error_arg(int ac, char **av)
{
   int i;

    i = 1;
    while (i < ac)
    {
        if (only_nb_allow(av[i]) == 0 || only_twoo_nb_allow(av, i) == 0)
        {
            return (0);
        }
        i++;
    }
    return (1);
}

int only_nb_allow(char *av)
{
    int i;

    i = 0;
    while (av[i] != '\0')
    {   
        if ((av[i] >= '0' && av[i] <= '9') || (i == 0 && av[i] == '-'))
        {
            i++;
        }
        else 
        {
            return (0);
        }
    }
    if(ft_atoi(av) > INT_MAX || ft_atoi(av) < INT_MIN)
        return(0);
    return(1);
}

int only_twoo_nb_allow(char **av, int index)
{
    int i;

    i = 1;
   while (i < index)
    {
        if (ft_strncmp(av[index], av[i], ft_strlen(av[index])) == 0)
        {
            return (0);
        }
        i++;
    }
    return (1);
}