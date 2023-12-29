/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:08:34 by malanglo          #+#    #+#             */
/*   Updated: 2023/12/29 13:12:51 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	send_characters_as_binary_signals(int pid, char c)
{
	int	bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		if (((int)c >> bit_index) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit_index--;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	if (argc == 3)
	{
		pid = atoi(argv[1]);
		message = (char *)argv[2];
		while (*message)
			send_characters_as_binary_signals(pid, *message++);
	}
	return (0);
}
