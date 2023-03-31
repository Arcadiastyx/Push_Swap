/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:07:31 by inaranjo          #+#    #+#             */
/*   Updated: 2023/03/28 14:56:29 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_stack *create_list(int ac, char **av)
{
    t_stack *begin_list;
    t_stack *tmp;

    begin_list = NULL; 
    while(ac > 1)
    {
        tmp = create_node(av[ac -1]);
        if(tmp == NULL)
        {
            free_list(begin_list);
            return (NULL);
        }
        tmp->next = begin_list;
        begin_list = tmp; 
        ac--;
    }
    return(begin_list);
}


t_stack *create_node(char *av)
{
    t_stack *node;

    node = malloc(sizeof(t_stack));
    if(!node)
    {
        ft_putstr_fd("Error: Memory allocation failed\n", 2);
        return (NULL);
    }
    node->data = ft_atoi(av);
    node->next = NULL;
    return (node);
}


void free_list(t_stack *list)
{
    t_stack *tmp;

    while(list != NULL)
    {
        tmp = list->next;
        free (list);
        list = tmp;
    }
}


