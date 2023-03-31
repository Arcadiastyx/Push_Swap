/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:31:08 by inaranjo          #+#    #+#             */
/*   Updated: 2022/11/15 14:53:23 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	is_hexmin(t_print *m_input)
{
	int	hexmin;

	hexmin = va_arg(m_input->args, unsigned int);
	ft_puthexamin(hexmin, m_input);
}

void	is_hexmaj(t_print *m_input)
{
	int	hexmaj;

	hexmaj = va_arg(m_input->args, unsigned int);
	ft_puthexamaj(hexmaj, m_input);
}
