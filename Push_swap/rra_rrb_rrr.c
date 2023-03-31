/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:22:03 by inaranjo          #+#    #+#             */
/*   Updated: 2023/03/31 12:35:46 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rerotate(t_stack **top)
{
    t_stack *tmp1;
    t_stack *tmp2;

    if (*top == NULL || (*top)->next == NULL)
        return ;
    tmp1 = *top;
    while (tmp1->next->next != NULL)
    {
        tmp1 = tmp1->next;
    }
    tmp2 = tmp1->next;
    tmp1->next = NULL;
    tmp1 = *top;
    *top = tmp2;
    tmp2->next = tmp1;
    
}

void rra(t_stack **stacks)
{
    rerotate(&stacks[0]);
    ft_printf("rra\n");
}

void rrb(t_stack **stacks)
{
    rerotate(&stacks[1]);
    ft_printf("rrb\n");
}

void rrr(t_stack **stacks)
{
    rerotate(&stacks[0]);
    rerotate(&stacks[1]);
    ft_printf("rrr\n");
}

