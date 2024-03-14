# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amagoury <amagoury@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 21:21:11 by amagoury          #+#    #+#              #
#    Updated: 2024/03/03 16:23:36 by amagoury         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SNAME = server
CNAME = client
SRC1 = client.c util.c
SRC2 = server.c util.c
SRC1_BONUS = client_bonus.c util.c
SRC2_BONUS = server_bonus.c util.c
CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ1 = $(SRC1:.c=.o) 
OBJ2 = $(SRC2:.c=.o)

all: $(SNAME) $(CNAME)

$(CNAME): $(OBJ1)
	$(CC) $(OBJ1) -o $(CNAME)

$(SNAME): $(OBJ2)
	$(CC) $(OBJ2) -o $(SNAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ1) $(OBJ2)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:
	$(CC) $(CFLAGS) $(SRC1_BONUS) -o client
	$(CC) $(CFLAGS) $(SRC2_BONUS) -o server