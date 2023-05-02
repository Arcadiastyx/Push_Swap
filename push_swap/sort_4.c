/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:35:10 by inaranjo          #+#    #+#             */
/*   Updated: 2023/05/02 13:11:30 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_stack *a, int to_find)
{
	int	i;

	i = 0;
	while (a)
	{
		if (*(int *)a->content == to_find)
			return (i);
		a = a->next;
		i++;
	}
	ft_error();
	return (-1);
}

void	find_position_3(int index, t_stack *a, t_stack **b)
{
	if (index == 0)
	{
		rra(a);
		pb(&a, b);
	}
	else if (index == 1)
	{
		rra(a);
		rra(a);
		pb(&a, b);
	}
	else if (index == 2)
	{
		sa(a);
		pb(&a, b);
	}
	else if (index == 3)
		pb(&a, b);
}

void	sort_4(t_stack *a, t_stack *b)
{
	int	pos_0;

	if (is_sorted(a))
		return ;
	pos_0 = find_index(a, 0);
	find_position_3(pos_0, a, &b);
	sort_3(a);
	pa(&a, &b);
}