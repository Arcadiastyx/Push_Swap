/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:33:10 by inaranjo          #+#    #+#             */
/*   Updated: 2023/05/02 13:09:32 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_error_index(t_input	*args)
{
	free_args(args);
	ft_error();
}

t_stack	*create_stack_index(t_input *parse, int **index_tab)
{
	int		i;
	t_stack	*a;
	t_list	*tmp;

	a = NULL;
	i = -1;
	while (++i < parse->size)
	{
		tmp = ft_lstnew(index_tab[i]);
		ft_lstadd_front(&a, tmp);
	}
	return (a);
}

t_stack	*create_stack(t_input *args)
{
	int			**index_tab;
	t_stack		*a;
	int			i;
	int			j;
	int			count_above;

	a = NULL;
	index_tab = malloc(sizeof(int *) * args->size);
	if (!index_tab)
		free_error_index(args);
	i = -1;
	while (++i < args->size)
	{
		count_above = 0;
		j = -1;
		while (++j < args->size)
			if (args->array[i] > args->array[j])
				count_above++;
		index_tab[i] = malloc(sizeof(int));
		*index_tab[i] = count_above;
	}
	a = create_stack_index(args, index_tab);
	free(index_tab);
	return (a);
}

t_stack	*parse_args(int argc, char **argv)
{
	t_input	args;
	t_stack	*a;

	if (argc == 2)
	{
		args.size = 0;
		args.str_tab = ft_split(argv[1], ' ');
		while (args.str_tab[args.size] != 0)
			args.size++;
		over_check(&args);
	}
	else if (argc > 2)
	{
		args.size = (argc - 1);
		args.str_tab = (argv + 1);
		over_check(&args);
		args.str_tab = NULL;
	}
	else
		return (0);
	a = create_stack(&args);
	free_args(&args);
	return (a);
}

void	over_check(t_input *args)
{
	int	i;

	i = 0;
	while (args->str_tab[i] != 0)
	{
		if (!check_args_process(args->str_tab[i]))
			ft_error();
		i++;
	}
	i = 0;
	args->array = malloc(sizeof(int) * args->size);
	while (args->str_tab[i] != 0)
	{
		args->array[i] = ft_atoi_mod(args->str_tab[i]);
		i++;
	}
	if (!check_double(args))
		ft_error();
	i = 0;
}