/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:44:09 by inaranjo          #+#    #+#             */
/*   Updated: 2023/03/31 11:12:15 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void    push(t_stack **top_a, t_stack **top_b)
{
    t_stack *tmp;

    if(*top_b == NULL)
        return ;
    tmp = *top_a; 
    *top_a = *top_b;
    *top_b = (*top_b)->next;
    (*top_a)->next = tmp;
}

void pa(t_stack **stacks)
{
    push(&stacks[0], &stacks[1]);
    ft_printf("pa\n");
   
}

void pb(t_stack **stacks)
{
    push(&stacks[1], &stacks[0]);
    ft_printf("pb\n");
}