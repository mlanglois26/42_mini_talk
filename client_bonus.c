/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:59:59 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/19 11:04:03 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

int			g_control;

static void	ft_send_characters_as_binary_signals(int pid, char c)
{
	int	bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		g_control = 0;
		if (((int)c >> bit_index) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit_index--;
		while (g_control != 1)
			usleep(10);
	}
}

static void	ft_manage_signals(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message bien recu\n");
	if (signal == SIGUSR2)
		g_control = 1;
}

static void	ft_get_str_and_eof(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		signal(SIGUSR2, ft_manage_signals);
		signal(SIGUSR1, ft_manage_signals);
		ft_send_characters_as_binary_signals(pid, str[i]);
		i++;
	}
	ft_send_characters_as_binary_signals(pid, '\n');
	ft_send_characters_as_binary_signals(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3 && argv[2][0] != '\0')
	{
		pid = ft_atoi(argv[1]);
		if (kill(ft_atoi(argv[1]), 0) < 0)
			ft_printf("Error. Invalid PID number.\n");
		else
			ft_get_str_and_eof(pid, argv[2]);
	}
	else
	{
		ft_printf("Error. Something went wrong.\n");
		ft_printf("Accepted format: ./client <PID> <MESSAGE>.\n");
	}
	return (0);
}
