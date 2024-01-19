/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:23:34 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/19 11:02:02 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	ft_handle_message(int signal_value, siginfo_t *data, void *context)
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
		bit_index = 0;
		c = 0;
	}
	kill(data->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	data;

	ft_printf("Le PID du seveur est %d\n", getpid());
	sigemptyset(&data.sa_mask);
	data.sa_flags = SA_SIGINFO;
	data.sa_sigaction = &ft_handle_message;
	sigaction(SIGUSR1, &data, NULL);
	sigaction(SIGUSR2, &data, NULL);
	while (1)
		pause();
	return (0);
}
