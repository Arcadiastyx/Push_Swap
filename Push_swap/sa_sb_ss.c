/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:13:32 by inaranjo          #+#    #+#             */
/*   Updated: 2023/03/31 11:16:58 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void swap(t_stack **top)
{
    t_stack *tmp;

    // Vérifie qu'il y a plus d'un élément sur la pile.
    // Si c'est le cas, il n'y a rien à échanger, donc la fonction se termine.
    if (*top == NULL || (*top)->next == NULL)
        return ;
  
    tmp = *top;// Stocke le premier élément de la pile dans une variable temporaire `tmp`. (3 est dans une varaible tmp)
    *top = (*top)->next;// Assigne le deuxième élément de la pile comme nouveau premier élément.( 2 viens prendre la premier place)
    tmp->next = (*top)->next;// Met à jour le pointeur `next` de `tmp` pour qu'il pointe vers le troisième élément de la pile.
    (*top)->next = tmp;// Met à jour le pointeur `next` du nouveau premier élément de la pile
    return ;
}

void sa(t_stack **stacks)
{
    swap(&stacks[0]);
    write(1, "sa\n", 3);
}

void sb(t_stack **stacks)
{
    swap(&stacks[1]);
    write(1, "sb\n", 3);
}

void ss(t_stack **stacks)
{
    swap(&stacks[0]);
    swap(&stacks[1]);
    write(1, "ss\n", 3);
}