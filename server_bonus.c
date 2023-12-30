/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:59:47 by malanglo          #+#    #+#             */
/*   Updated: 2023/12/30 12:48:43 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

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

int	main(void)
{
	struct sigaction	gestion;

	gestion.sa_sigaction = &ft_handle_message;
	gestion.sa_flags = SA_SIGINFO;
	
    sigemptyset(&gestion.sa_mask);
	
    ft_printf("Le PID du seveur est %d\n", getpid());
	
    sigaction(SIGUSR1, &gestion, NULL);
	sigaction(SIGUSR2, &gestion, NULL);
	
    while (1)
		pause();
	return (0);
}
