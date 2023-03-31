/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:10:43 by inaranjo          #+#    #+#             */
/*   Updated: 2022/11/15 15:15:06 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putbase10(unsigned int i, t_print *m_input)
{
	char	*base;

	base = "0123456789";
	if (i >= 10)
	{
		ft_putbase10(i / 10, m_input);
		ft_putbase10(i % 10, m_input);
	}
	else
	{
		ft_putchar(base[i]);
		m_input->len++;
	}
}

void	ft_puthexamin(unsigned int i, t_print *m_input)
{
	char	*base;

	base = "0123456789abcdef";
	if (i >= 16)
	{
		ft_puthexamin(i / 16, m_input);
		ft_puthexamin(i % 16, m_input);
	}
	else
	{
		ft_putchar(base[i]);
		m_input->len++;
	}
}

void	ft_puthexamaj(unsigned int i, t_print *m_input)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (i >= 16)
	{
		ft_puthexamaj(i / 16, m_input);
		ft_puthexamaj(i % 16, m_input);
	}
	else
	{
		ft_putchar(base[i]);
		m_input->len++;
	}
}
