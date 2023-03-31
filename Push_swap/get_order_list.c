/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_order_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:51:08 by inaranjo          #+#    #+#             */
/*   Updated: 2023/03/31 12:35:51 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_order_a(t_stack **stacks, int count)
{
    t_stack *tmp;
    int i;
    
    tmp = *stacks;
    i = 1;
    if (tmp == NULL || tmp->next == NULL)
        return (1);
    while (tmp->data < tmp->next->data)
    {
        tmp = tmp->next;
        i++;
        if (tmp->next == NULL || i == count)
            return (1);
    }
    return (0);
}

t_stack *last_data_list(t_stack **stacks)
{
    t_stack *tmp; 

    tmp = *stacks;
    while(tmp->next != NULL)
    { 
        tmp = tmp->next;
    }
    return(tmp);
}