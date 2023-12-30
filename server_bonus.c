/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:59:47 by malanglo          #+#    #+#             */
/*   Updated: 2023/12/30 14:05:36 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

#define END_TRANSMISSION '\0'

void	ft_handle_message(int signal_value, siginfo_t *info, void *context)
{
	static int	bit;
	static int	c;

    (void)context;
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
    if (signal_value == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (signal_value == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	gestion;

	ft_printf("Le PID du seveur est %d\n", getpid());
	sigemptyset(&gestion.sa_mask);
	gestion.sa_sigaction = &ft_handle_message;
	gestion.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &gestion, NULL);
	sigaction(SIGUSR2, &gestion, NULL);
	while (1)
		pause();
	return (0);
}
