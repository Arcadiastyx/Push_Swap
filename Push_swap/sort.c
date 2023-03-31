/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:12:34 by inaranjo          #+#    #+#             */
/*   Updated: 2023/03/31 12:35:43 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*
1.Si le dernier élément de la pile A est entre le premier et le deuxième élément,on effectue une opération
 "sa" (swap A : échange les deux premiers éléments de la pile A) suivie d'une opération
 "ra" (rotate A : déplace le premier élément de la pile A à la fin).

2.Sinon, si le premier élément de la pile A est plus grand que le dernier élément, on effectue une opération 
 "ra" (rotate A : déplace le premier élément de la pile A à la fin).

3.Sinon, si le premier élément de la pile A est plus grand que le deuxième élément, on effectue une opération
 "sa" (swap A : échange les deux premiers éléments de la pile A).*/

void sort3(t_stack **stacks)
{
        while (check_order_a(&stacks[0], 3) != 1)
        {
            if (last_data_list(&stacks[0])->current > stacks[0]->current && last_data_list(&stacks[0])->current < stacks[0]->next->current)
            {
                sa(stacks);
                ra(stacks);
            }
            else if (stacks[0]->current > last_data_list(&stacks[0])->current)
                ra(stacks);
            else if (stacks[0]->current > stacks[0]->next->current)
                sa(stacks);
        }
}