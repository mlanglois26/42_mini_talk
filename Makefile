# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 13:10:28 by malanglo          #+#    #+#              #
#    Updated: 2023/12/30 12:29:10 by malanglo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = mini_talk
# SERVER = server
# CLIENT = client

# CC = cc
# CFLAGS = -Wall -Wextra -Werror -I./ft_printf
# ADD_FLAGS = -L./ft_printf -lftprintf

# SERVER_SRC = server.c
# CLIENT_SRC = client.c
# UTILS_SRC = utils.c

# SERVER_OBJ = $(SERVER_SRC:.c=.o)
# CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
# UTILS_OBJ = $(UTILS_SRC:.c=.o)

# all: $(SERVER) $(CLIENT)

# $(NAME): $(SERVER) $(CLIENT)

# $(SERVER): $(SERVER_OBJ)
# 	$(CC) $(CFLAGS) $^ -o $(SERVER) $(ADD_FLAGS)

# $(CLIENT): $(CLIENT_OBJ) $(UTILS_OBJ)
# 	$(CC) $(CFLAGS) $^ -o $(CLIENT) $(ADD_FLAGS)

# clean:
# 	rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(UTILS_OBJ)

# fclean: clean
# 	rm -f $(SERVER) $(CLIENT) 

# re: fclean all

# .PHONY: all clean fclean re


SRCS = client.c server.c utils.c
OBJS := $(SRCS:%.c=%.o)
BSRCS = client_bonus.c server_bonus.c utils_bonus.c
BOBJS := $(BSRCS:%.c=%.o)
NAME = minitalk

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I./ft_printf

all: $(NAME)

$(NAME): server client

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


server: server.o
	make -C ft_printf
	$(CC) $(CFLAGS) $^ -L./ft_printf -lftprintf -o server

client: client.o
	make -C ft_printf
	$(CC) $(CFLAGS) $^ -L./ft_printf -lftprintf -o client


server_bonus: server_bonus.o
	make -C ft_printf
	$(CC) $(CFLAGS) $^ -L./ft_printf -lftprintf -o server_bonus

client_bonus: client_bonus.o
	make -C ft_printf
	$(CC) $(CFLAGS) $^ -L./ft_printf -lftprintf -o client_bonus


clean:
	make clean -C ft_printf
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) server client server_bonus client_bonus

re: fclean all

bonus: server_bonus client_bonus

.PHONY: all clean fclean re bonus