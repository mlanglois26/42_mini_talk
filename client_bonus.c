/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:59:59 by malanglo          #+#    #+#             */
/*   Updated: 2023/12/30 11:14:24 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

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

void ft_print_receipt(int signal_value)
{
    if (signal_value == SIGUSR1)
        ft_printf("Le bit recu = 1\n");
    if (signal_value == SIGUSR2)
        ft_printf("Le bit recu = 0\n");
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	signal(SIGUSR1, ft_print_receipt);
    signal(SIGUSR1, ft_print_receipt);
    if (argc == 3)
	{
		pid = atoi(argv[1]);
		i = 0;
        while (argv[2][i] != '\0')
		{
			ft_send_characters_as_binary_signals(pid, argv[2][i++]);
		}
		ft_send_characters_as_binary_signals(pid, '\n');
	}
	return (0);
}


