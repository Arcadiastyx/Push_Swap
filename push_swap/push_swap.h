/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:05:17 by inaranjo          #+#    #+#             */
/*   Updated: 2023/05/02 13:10:08 by inaranjo         ###   ########.fr       */
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

typedef struct s_input
{
    int             size;
    int             *array;
    char            **str_tab;
}   t_input;

typedef t_list  t_stack;

/*check-args*/
int check_nb(char *str);
int check_sign(char *str);
int check_args_process(char *str);
int check_double(t_input *args);
int	ft_atoi_mod(char *str);

/*manage_stack*/
void	free_error_index(t_input	*args);
t_stack	*create_stack_index(t_input *parse, int **index_tab);
t_stack	*create_stack(t_input *args);
t_stack	*parse_args(int argc, char **argv);
void	over_check(t_input *args);

/*operations*/
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rra(t_stack *a);
void	ra(t_stack *a);
void	sa(t_stack *a);

/*sort_logic*/
void    sort(t_stack *a, t_stack *b);
int     is_sorted(t_stack *a);
void    sort_3(t_stack *a);
int     find_index(t_stack *a, int to_find);
void	find_position_3(int index, t_stack *a, t_stack **b);
void	sort_4(t_stack *a, t_stack *b);
void	find_position_0(int index, t_stack *a, t_stack **b);
void	find_position_1(int index, t_stack *a, t_stack **b);
void	sort_5(t_stack *a, t_stack *b);
void	push_pa(t_stack **a, t_stack **b, int *size_b);
void	radix_sort(t_stack *a, t_stack *b, int size);

/*utils*/
void	ft_error(void);
void	free_args(t_input *parse);
void	print_stack(t_stack *stack, char *stack_name);

#endif 