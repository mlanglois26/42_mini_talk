/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:08:42 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/17 19:47:17 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	ft_decrypt_message(int signal_value)
{
	static int	bit_index;
	static int	c;

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
}

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
