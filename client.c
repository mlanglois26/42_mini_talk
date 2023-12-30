/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:08:34 by malanglo          #+#    #+#             */
/*   Updated: 2023/12/30 10:41:47 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

// apres avoir envoye chaque bit le client attend grace au usleep qui permet au server de proceder les signaux recus

void	ft_send_characters_as_binary_signals(int pid, char c)
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
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			ft_send_characters_as_binary_signals(pid, argv[2][i++]);
		}
		ft_send_characters_as_binary_signals(pid, '\n');
	}
	return (0);
}
