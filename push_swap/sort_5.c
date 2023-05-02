/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 06:35:23 by inaranjo          #+#    #+#             */
/*   Updated: 2023/05/02 13:11:41 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_position_0(int index, t_stack *a, t_stack **b)
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
		ra(a);
		ra(a);
		pb(&a, b);
	}
	else if (index == 3)
	{
		ra(a);
		pb(&a, b);
	}
	else if (index == 4)
		pb(&a, b);
}

void	find_position_1(int index, t_stack *a, t_stack **b)
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
	{
		pb(&a, b);
	}
}

void    sort_5(t_stack *a, t_stack *b)
{	
	int	pos_0;
	int	pos_1;

	if (is_sorted(a))
		return ;
	pos_0 = find_index(a, 0);
	find_position_0(pos_0, a, &b);
	pos_1 = find_index(a, 1);
	find_position_1(pos_1, a, &b);
	sort_3(a);
	pa(&a, &b);
	pa(&a, &b);
}