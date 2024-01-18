# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 13:10:28 by malanglo          #+#    #+#              #
#    Updated: 2024/01/18 10:30:23 by malanglo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SRCS = client.c server.c utils.c
OBJS := $(SRCS:%.c=%.o)

BSRCS = client_bonus.c server_bonus.c utils_bonus.c
BOBJS := $(BSRCS:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./ft_printf
RM = rm -f

all: $(NAME)

$(NAME): server client

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

server: server.o
	make -C ft_printf
	$(CC) $(CFLAGS) $^ -L./ft_printf -lftprintf -o server

client: client.o utils.o
	make -C ft_printf
	$(CC) $(CFLAGS) $^ -L./ft_printf -lftprintf -o client

bonus: server_bonus client_bonus

server_bonus: server_bonus.o
	make -C ft_printf
	$(CC) $(CFLAGS) $^ -L./ft_printf -lftprintf -o server_bonus

client_bonus: client_bonus.o utils_bonus.o
	make -C ft_printf
	$(CC) $(CFLAGS) $^ -L./ft_printf -lftprintf -o client_bonus

clean:
	make clean -C ft_printf
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) server client server_bonus client_bonus

re: fclean all

.PHONY: all clean fclean re bonus


