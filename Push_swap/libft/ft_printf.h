/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:26:53 by inaranjo          #+#    #+#             */
/*   Updated: 2022/11/16 13:32:22 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>

/*la struct va gerer la va_list (en memoire dynamique) sur tout le code.*/
typedef struct s_print
{
	va_list	args;
	int		len;
}				t_print;

/*fonction principal: role cree de la memoire+anlayser args pour print */
t_print	*ft_initialise_memory_input(t_print *m_input);
void	ft_scan_input(char c, t_print *m_input);
int		ft_printf(const char *input, ...);

/* fonction d-analyse: role verifier les arguments demande pour execution*/
void	is_char(t_print *m_input);
void	is_str(t_print *m_input);
void	is_pointer(t_print *m_input);
void	is_int(t_print *m_input);
void	is_uint(t_print *m_input);
void	is_hexmin(t_print *m_input);
void	is_hexmaj(t_print *m_input);
void	is_perc(t_print *m_input);
/* fonction utilitaire : role supporter les fonctions d-analyse
 * pour l-affichage des args*/
t_print	*ft_malloc(t_print *m_input);
void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_strchr(const char *s, int c);
void	ft_putpointer(unsigned long int i, t_print *m_input);
void	ft_putnbr(long int nb);
void	ft_putbase10(unsigned int i, t_print *m_input);
void	ft_puthexamin(unsigned int i, t_print *m_input);
void	ft_puthexamaj(unsigned int i, t_print *m_input);

#endif 
