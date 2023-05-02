/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:26:03 by inaranjo          #+#    #+#             */
/*   Updated: 2023/05/02 13:11:22 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	while (a->next != NULL)
	{
		if (*(int *) a->content < *(int *) a->next->content)
		{
			return (0);
		}
		a = a->next;
	}
	return (1);
}

void    sort_3(t_stack *a)
{
	int	elem_0;
	int	elem_1;
	int	elem_2;

	elem_0 = *(int *) a->content;
	elem_1 = *(int *) a->next->content;
	elem_2 = *(int *) a->next->next->content;
	if (is_sorted(a))
		return ;
	if ((elem_0 < elem_1) && (elem_1 < elem_2))
	{
		ra(a);
		sa(a);
	}
	else if ((elem_0 > elem_1) && (elem_2 > elem_0))
		ra(a);
	else if ((elem_1 > elem_0) && (elem_0 > elem_2))
	{
		rra(a);
		sa(a);
	}
	else if ((elem_0 > elem_2) && (elem_2 > elem_1))
		sa(a);
	else if ((elem_1 > elem_2) && (elem_2 > elem_0))
		rra(a);
}