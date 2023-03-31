/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:57:05 by inaranjo          #+#    #+#             */
/*   Updated: 2022/11/15 13:16:00 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long int nb)
{
	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

void	is_int(t_print *m_input)
{
	int	nb;

	nb = va_arg(m_input->args, long int);
	if (nb < 0)
	{
		nb = -nb;
		m_input->len++;
		ft_putchar('-');
	}
	ft_putnbr(nb);
	if (nb == 0)
		m_input->len++;
	while (nb != 0)
	{
		nb = nb / 10;
		m_input->len ++;
	}
}

void	is_uint(t_print *m_input)
{
	int	dint;

	dint = va_arg(m_input->args, int);
	ft_putbase10(dint, m_input);
}
