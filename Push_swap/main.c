/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:33:25 by inaranjo          #+#    #+#             */
/*   Updated: 2023/03/31 11:14:35 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"

void print_list(t_stack *begin_list)
{
    t_stack *list; 

    list = begin_list;
    while(list != NULL)
    { 
        ft_printf("%d\n",list->data);
        list = list->next;
    }
    ft_printf("\n");
}

int main(int ac, char **av)
{
    t_stack *stacks[2];

    if(ac < 2)
    {
        ft_printf("\n");
    }
    if(check_error_arg(ac,av) == 0)
    {
        ft_printf("ERROR:\n args not allowed \n");
        return (0);
    }

    stacks[0] = create_list(ac,av);
    stacks[1] = NULL;

    if(stacks[0] == NULL)
    {
        ft_printf("ERROR:\n list could not be created");
        return(0);
    }

   
    ft_printf("Stack_A\n");
    print_list(stacks[0]);

    ft_printf("\n");

    ft_printf("Stack_B\n\n");
    print_list(stacks[1]);


    free_list(stacks[0]);
    free_list(stacks[1]);


    return(0);  
}

