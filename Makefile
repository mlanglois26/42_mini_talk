# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 13:10:28 by malanglo          #+#    #+#              #
#    Updated: 2023/12/29 14:42:39 by malanglo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mini_talk

SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER_SRC = server.c
CLIENT_SRC = client.c

all: $(NAME)

$(NAME): ${SERVER} ${CLIENT}

$(SERVER):
		$(CC) $(CFLAGS) $(SERVER_SRC) -o $(SERVER)

$(CLIENT):
		$(CC) $(CFLAGS) $(CLIENT_SRC) -o $(CLIENT)

clean:
		rm -f $(SERVER) $(CLIENT)

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re