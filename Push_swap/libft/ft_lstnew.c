/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 09:23:59 by msanjuan          #+#    #+#             */
/*   Updated: 2023/03/17 15:11:41 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(long int data)
{
	t_list	*new_block;

	new_block = (t_list *)malloc(sizeof(t_list));
	if (!(new_block))
		return (NULL);
	new_block->number = data;
	new_block->next = NULL;
	return (new_block);
}
