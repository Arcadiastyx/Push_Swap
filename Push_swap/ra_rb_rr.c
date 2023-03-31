/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:16:35 by inaranjo          #+#    #+#             */
/*   Updated: 2023/03/31 11:21:17 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*La fonction ra effectue cette opération sur la pile 0 (stacks[0]), la fonction rb sur la pile 1 (stacks[1]),
et la fonction rr sur les deux piles (stacks[0] et stacks[1]).
void rotate(node **head)
*/
void rotate(t_stack **top)
{
    t_stack *tmp1;
    t_stack *tmp2;

    if (*top == NULL || (*top)->next == NULL)
        return ;
    tmp1 = *top;
    *top = (*top)->next;
    tmp2 = *top;
    while(tmp2->next != NULL)
    {
        tmp2 = tmp2->next;
    }
    tmp2->next = tmp1;
    tmp1->next = NULL;
}

void ra(t_stack **stacks)
{  
    rotate(&stacks[0]);
    ft_printf("ra\n");
}

void rb(t_stack **stacks)
{
    rotate(&stacks[1]);
    ft_printf("rb\n");
}

void rr(t_stack **stacks)
{
    rotate(&stacks[0]);
    rotate(&stacks[1]);
	  ft_printf("rr\n");
}