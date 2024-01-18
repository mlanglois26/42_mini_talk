/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:59:47 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/18 20:22:16 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

void	ft_handle_message(int signal_value, siginfo_t *action, void *context)
{
	static int	bit_index;
	static int	c;

	(void)context;
	if (signal_value == SIGUSR1)
		c += 1 << (7 - bit_index);
	else if (signal_value == SIGUSR2)
		c += 0 << (7 - bit_index);
	bit_index++;
	if (bit_index == 8)
	{
		write(1, &c, 1);
		if (c == 0)
			kill(action->si_pid, SIGUSR1);
		bit_index = 0;
		c = 0;
	}
	kill(action->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	action;

	ft_printf("Le PID du seveur bonus est %d\n", getpid());
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = &ft_handle_message;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
