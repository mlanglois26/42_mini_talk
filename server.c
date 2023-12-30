/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:08:42 by malanglo          #+#    #+#             */
/*   Updated: 2023/12/30 11:15:40 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

// cette fonction extrait les bits 1 ou 0 du signal recu et appends it au charactere qui est recu
// 1 char = 8 bit lorsque c est complet on passe au charactere suivant 

void	ft_decrypt_message(int signal_value)
{
	static int	bit;
	static int	c;

	if (signal_value == SIGUSR1)
	{
		c += 1 << (7 - bit);
	}
	else if (signal_value == SIGUSR2)
	{
		c += 0 << (7 - bit);
	}
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

// on set up le signal handlers pour sgusr1 et sgusr2 en utilisant la fnction signal
// puis on rentre dans une boucle infinie et attend les isgnaux grace a pause


int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_printf("Le PID du Server est = %d\n", pid);
		signal(SIGUSR1, ft_decrypt_message);
		signal(SIGUSR2, ft_decrypt_message);
		while (1)
			pause();
	}
	return (0);
}
