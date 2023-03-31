/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managechar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:22:41 by inaranjo          #+#    #+#             */
/*   Updated: 2022/11/15 14:53:13 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	is_char(t_print *m_input)
{
	char	c;

	c = va_arg(m_input->args, unsigned int);
	m_input->len += 1;
	ft_putchar(c);
}

void	is_str(t_print *m_input)
{
	char	*str;
	int		i;

	str = va_arg(m_input->args, char *);
	if (str == NULL)
	{
		ft_putstr("(null)");
		m_input->len += 6;
		return ;
	}
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		m_input->len++;
		i++;
	}
}

void	is_perc(t_print *m_input)
{
	ft_putchar('%');
	m_input->len++;
}
