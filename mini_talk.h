/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:09:05 by malanglo          #+#    #+#             */
/*   Updated: 2023/12/29 16:58:05 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

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

#endif
