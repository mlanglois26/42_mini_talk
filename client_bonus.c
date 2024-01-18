/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:59:59 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/18 15:25:00 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

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

void	ft_get_str_and_eof(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_send_characters_as_binary_signals(pid, str[i]);
		i++;
	}
	ft_send_characters_as_binary_signals(pid, '\n');
	ft_send_characters_as_binary_signals(pid, '\0');
}

void	ft_print_receipt(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message bien recu\n");
}

int	main(int argc, char **argv)
{
	int	pid;

	signal(SIGUSR1, ft_print_receipt);
	if (argc == 3 && argv[2][0] != '\0')
	{
		pid = atoi(argv[1]);
		ft_get_str_and_eof(pid, argv[2]);
	}
	return (0);
}
