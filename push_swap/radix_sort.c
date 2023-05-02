/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 06:45:18 by inaranjo          #+#    #+#             */
/*   Updated: 2023/05/02 12:56:22 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_pa(t_stack **a, t_stack **b, int *size_b)
{
	int	j;

	j = -1;
	while (++j < *size_b)
	{
		pa(a, b);
	}
}

void	radix_sort(t_stack *a, t_stack *b, int size)
{
	int	i;
	int	j;
	int	elem;
	int	size_b;

	i = -1;
	while (++i < 32)
	{
		if (is_sorted(a))
			return ;
		size_b = 0;
		j = -1;
		while (++j < size)
		{
			elem = *(int *) ft_lstlast(a)->content;
			if ((elem >> i) & 1)
				ra(a);
			else
			{
				pb(&a, &b);
				size_b++;
			}
		}
		push_pa(&a, &b, &size_b);
	}
}