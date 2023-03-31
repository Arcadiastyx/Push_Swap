/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:59:21 by inaranjo          #+#    #+#             */
/*   Updated: 2022/11/16 14:26:31 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*ft_initialise_memory_input(t_print *m_input)
{
	m_input->len = 0;
	return (m_input);
}

void	ft_scan_input(char c, t_print *m_input)
{
	if (c == 'c')
		is_char(m_input);
	else if (c == 's')
		is_str(m_input);
	else if (c == 'p')
		is_pointer(m_input);
	else if (c == 'd' || c == 'i')
		is_int(m_input);
	else if (c == 'u')
		is_uint(m_input);
	else if (c == 'x')
		is_hexmin(m_input);
	else if (c == 'X')
		is_hexmaj(m_input);
	else if (c == '%')
		is_perc(m_input);
}

int	ft_printf(const char *input, ...)
{
	t_print	*m_input;
	int		i;
	int		tmp;

	m_input = (t_print *)malloc(sizeof(t_print));
	if (m_input == NULL)
		return (-1);
	m_input = ft_initialise_memory_input(m_input);
	i = -1;
	va_start(m_input->args, input);
	while (input[++i])
	{
		if (input[i] == '%' && ft_strchr("cspdiuxX%", input[i + 1]))
			ft_scan_input(input[i++ + 1], m_input);
		else
		{
			ft_putchar(input[i]);
			m_input->len++;
		}
	}
	tmp = (m_input->len);
	free(m_input);
	return (tmp);
}

/*int	main(void)
{
	int	c;
	c = 'a';	

	char s[] = "Hello World ";

	int nb;
	nb = 100;

	int nb1;
	nb1 = 1;

	unsigned int nb2;
	nb2 = 666;

	unsigned int c1;
	c1 = 'm';

	unsigned int c2;
	c2 = 'M';

	ft_printf("%c\n",c);
	ft_printf("%s\n",s);
	ft_printf("%p\n",s);
	printf("original printf control : %p\n",s);
	ft_printf("%d\n", nb);
	printf("original printf control : %d\n", nb);
	ft_printf("%i",nb1);
	printf("original printf control : %i\n",nb1);
	ft_printf("%u\n", nb2);
	printf("original printf control : %u\n",nb2);
	ft_printf("%x\n", c1);
	printf("original printf control : %x\n",c1);
	ft_printf("%X\n", c2);
	printf("original printf control : %X\n",c2);
	ft_printf("%%\n");
	printf("original printf control : %%\n");
}*/

/*
• %c Affiche un seul caractère.
• %s Affiche une chaîne de caractères (telle que définie par la convention C).
• %p L’argument de pointeur void * doit être affiché en hexadécimal
.--> affiche l-addresse du pointeur.
• %d Affiche un nombre décimal (base 10).
• %i Affiche un entier en base 10.
• %u Affiche un nombre décimal non signé (base 10).
• %x Affiche un nombre en hexadécimal (base 16) avec des lettres minuscules.
• %X Affiche un nombre en hexadécimal (base 16) avec des lettres majuscules.
• %% Affiche un signe pourcentage.
*/
