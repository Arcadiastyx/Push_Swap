/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:14:40 by inaranjo          #+#    #+#             */
/*   Updated: 2022/11/15 12:52:26 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putpointer(unsigned long int i, t_print *m_input)
{
	char	*base;

	base = "0123456789abcdef";
	if (i >= 16)
	{
		ft_putpointer(i / 16, m_input);
		ft_putpointer(i % 16, m_input);
	}
	else
	{
		ft_putchar(base[i]);
		m_input->len++;
	}
}

void	is_pointer(t_print *m_input)
{
	unsigned long long	ptr;

	ptr = va_arg(m_input->args, unsigned long long);
	ft_putstr("0x");
	m_input->len += 2;
	ft_putpointer(ptr, m_input);
}
