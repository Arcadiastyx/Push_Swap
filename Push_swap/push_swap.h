/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:40:03 by inaranjo          #+#    #+#             */
/*   Updated: 2023/03/31 12:35:48 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				data;
	int				current;
	struct s_stack	*next;
}t_stack;


/*---------Errors_on_args------------*/
int	check_error_arg(int ac, char **av);
int	only_nb_allow(char *av);
int	only_twoo_nb_allow(char **av, int index);

/*----------manage_t-list-------------*/
t_stack *create_list(int ac, char **av);
t_stack	*create_node(char *av);
void	free_list(t_stack *list);

/*----------Push_A && Push_B---------*/
void    push(t_stack **top_a, t_stack **top_b);
void	pa(t_stack **stacks);
void	pb(t_stack **stacks);

/*-----------Swap_A_B_Both------------*/
void	swap(t_stack **top);
void	sa(t_stack **stacks);
void	sb(t_stack **stacks);
void	ss(t_stack **stacks);

/*-----------Rotate_A_B_Both----------*/
void	rotate(t_stack **top);
void	ra(t_stack **stacks);
void	rb(t_stack **stacks);
void	rr(t_stack **stacks);

/*--------Rotate_Bot->Top_A_B_Both---------*/
void	rerotate(t_stack **top);
void	rra(t_stack **stacks);
void	rrb(t_stack **stacks);
void	rrr(t_stack **stacks);

/*-----------Get_order_list---------------*/
int	check_order_a(t_stack **stacks, int count);
t_stack *last_data_list(t_stack **stacks)

/*-------------print---------------*/
void print_list(t_stack *begin_list);


#endif
