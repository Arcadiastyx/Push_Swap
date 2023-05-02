/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:16:02 by inaranjo          #+#    #+#             */
/*   Updated: 2023/04/27 16:10:17 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{	
	int		*temp_ptr;
	int		remove_first;
	t_stack	*copy;

	remove_first = 0;
	ft_printf("pa\n");
	if (!b || !*b)
		return ;
	temp_ptr = malloc(sizeof(int));
	if (!temp_ptr)
		return ;
	*temp_ptr = *(int *)ft_lstlast(*b)->content;
	ft_lstadd_back(a, ft_lstnew((void *)temp_ptr));
	copy = *b;
	while (copy->next && copy->next->next)
		copy = copy->next;
	if (ft_lstsize(*b) == 1)
		remove_first = 1;
	ft_lstdelone(ft_lstlast(*b), free);
	if (remove_first == 1)
		*b = NULL;
	else
		copy->next = NULL;
}

void	pb(t_stack **a, t_stack **b)
{
	int		*temp_ptr;
	t_stack	*copy;

	ft_printf("pb\n");
	if (!a || !*a)
		return ;
	temp_ptr = malloc(sizeof(int));
	if (!temp_ptr)
		return ;
	*temp_ptr = *(int *)ft_lstlast(*a)->content;
	ft_lstadd_back(b, ft_lstnew((void *)temp_ptr));
	copy = *a;
	while (copy->next && copy->next->next)
		copy = copy->next;
	ft_lstdelone(ft_lstlast(*a), free);
	copy->next = NULL;
}

void	rra(t_stack *a)
{
	int		temp;

	temp = *(int *) a->content;
	while (a->next)
	{
		*(int *)(a->content) = *(int *)(a->next->content);
		a = a->next;
	}
	*(int *)a->content = temp;
	ft_printf("rra\n");
}

void	ra(t_stack *a)
{
	int		temp;
	int		temp_pres;

	temp_pres = *(int *) ft_lstlast(a)->content;
	while (a)
	{	
		temp = *(int *)(a->content);
		*(int *)(a->content) = temp_pres;
		temp_pres = temp;
		a = a->next;
	}
	ft_printf("ra\n");
}

void	sa(t_stack *a)
{	
	int		top_value;

	top_value = *(int *) ft_lstlast(a)->content;
	while (a && a->next && a->next->next)
		a = a->next;
	*(int *) a->next->content = *(int *) a->content;
	*(int *) a->content = top_value;
	ft_printf("sa\n");
}