/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:08:42 by malanglo          #+#    #+#             */
/*   Updated: 2023/12/29 14:43:11 by malanglo         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		printf("Server PID = %d\n", pid);
		signal(SIGUSR1, ft_decrypt_message);
		signal(SIGUSR2, ft_decrypt_message);
		while (1)
			pause();
	}
	return (0);
}
