/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:34:14 by inaranjo          #+#    #+#             */
/*   Updated: 2023/05/02 12:58:54 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort(t_stack *a, t_stack *b)
{
	int	size;

	size = ft_lstsize(a);
	if (size <= 5)
	{
		if (size == 1)
			return ;
		else if (size == 2)
		{
			if (!(is_sorted(a)))
				ra(a);
		}
		else if (size == 3)
			sort_3(a);
		else if (size == 4)
			sort_4(a, b);
		else if (size == 5)
			sort_5(a, b);
	}
   	else
		radix_sort(a, b, size);
}