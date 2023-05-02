/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:20:11 by inaranjo          #+#    #+#             */
/*   Updated: 2023/03/10 14:20:02 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "minitalk.h"

/*#include <sys/siginfo.h>

union sigval {
	int sival_int;
	void *sival_ptr;
};
typedef struct {
	int si_signo;
	int si_code;
	union sigval si_value;
	int si_errno;
	pid_t si_pid;
	uid_t si_uid;
	void *si_addr;
	int si_status;
	int si_band;
} siginfo_t;*/

/*1.initialisation des variables : 
	i = a l index qui du char reçu par l emetteur
	bit = va gerer le nombre de bit autorise pour un char a savoir 8
  2.si le signal reçu est SIGUSR1, elle effectue un calcul de decalage de bits
  	pour definir le correpondant a la position bit dans la variable i sur 1
	(l'opérateur de décalage binaire à gauche << pour déplacer le nombre 0x01)
	(l'opérateur binaire OR |= est utilisé pour combiner la valeur précédente
	 de i avec la nouvelle valeur calculée pour définir le bit à 1)
  3. si le bit a atteind les 8 bit alors : 
     et que si la valeur de mon index i est a 0 donc = '\0'(fin du string-char)
	 dans ce cas le receptuer envoie a l emetteur via le SIGRS2 que les 8 bit 
	 on bien ete recptionner que le suivant peut etre lu
  4. affiche la valeur de i donc de mon char un par un. ex : h-e-l-l-o
  5. renisialisation des bit et i a 0 pour lire le prochain char */
void	recepteur(int sig, siginfo_t *info, void *stock_sig)
{
	static int	bit;
	static int	i;

	(void) *stock_sig;
	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (i == 0)
			kill(info->si_pid, SIGUSR2);
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	act;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("PID :%d\n", pid);
	act.sa_sigaction = recepteur;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	while (ac == 1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause ();
	}
	return (0);
}

/*SA_SIGINFO (depuis Linux 2.2)
    Le gestionnaire de signal prend trois arguments, pas un. Dans
    ce cas.*/

/*le signal SIGUSR1 :
   est utilisé pour transmettre des bits de données.
   Chaque fois que le processus récepteur reçoit un signal SIGUSR1,
   il interprète cela comme la réception d'un bit de valeur 1.
  le signal SIGUSR2 : 
  	l'envoi du signal SIGUSR2 ne comporte pas de données associées
	(contrairement à l'envoi des signaux SIGUSR1 qui transmettent des bits), 
il sert uniquement de confirmation de réception pour le processus émetteur.*/

/* getpid() : 
	renvoie l'ID de processus (PID) du processus appelant.*/

/*L'appel système sigaction():
 est utilisé pour modifier l'action entreprise par
 un processus à la réception d'un signal spécifique. (Voir signal(7) pour un
 aperçu des signaux.)*/

/*Ces fonctions permettent la manipulation
           d'ensembles de signaux POSIX.
sigemptyset() : 
	initialise l'ensemble de signaux donné par set à vide, 
	avec tous les signaux exclus de l'ensemble.*/

/*Un signal POSIX est un mécanisme utilisé
  dans les systèmes d'exploitation POSIX 
(Portable Operating System Interface) tels que Linux,
Unix et macOS pour permettre
à un processus de communiquer avec un autre processus
ou avec le système d'exploitation lui-même.*/

/*En général, cette technique de communication entre processus via des signaux
est appelée communication par signalisation.
Dans ce cas, le signal SIGUSR1 est utilisé pour transmettre des données
et le signal SIGUSR2 est utilisé pour indiquer la fin de la transmission.
*/
