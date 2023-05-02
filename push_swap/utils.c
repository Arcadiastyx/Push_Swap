/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:25:19 by inaranjo          #+#    #+#             */
/*   Updated: 2023/05/02 13:12:02 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	free_args(t_input *parse)
{
	int	i;

	i = -1;
	if (parse->str_tab)
	{
		while (parse->str_tab[++i])
			free(parse->str_tab[i]);
		free(parse->str_tab);
	}
	free(parse->array);
}

void free_stack(t_stack *list)
{
    t_stack *tmp;

    while(list != NULL)
    {
        tmp = list->next;
        free (list);
        list = tmp;
    }
}

void	print_stack(t_stack *stack, char *stack_name)
{
	printf("------- %s ------\n", stack_name);
	printf("| BOTTOM |\n");
	while (stack)
	{
		printf("%d\n", *(int *) stack->content);
		stack = stack->next;
	}
	printf("| TOP |\n");
}