/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:27:00 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/17 16:55:28 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_BONUS_H
# define MINI_TALK_BONUS_H

# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>

// server.c
void	ft_decrypt_message(int signal_value);

// client.c
void	ft_send_characters_as_binary_signals(int pid, char c);

// utils.c
int		ft_atoi(const char *nptr);

// bonus
void	ft_print_receipt(int signal_value);
void	ft_handle_message(int signal_value, siginfo_t *info, void *context);

#endif
