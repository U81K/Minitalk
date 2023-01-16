# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 18:17:20 by bgannoun          #+#    #+#              #
#    Updated: 2023/01/17 00:31:28 by bgannoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
FLAGS = -Wall -Wextra -Werror
RM = rm -fr

all:$(CLIENT) $(SERVER)

$(CLIENT):
	cd libft && make all
	CC $(FLAGS) libft/libft.a -o client client.c

$(SERVER):
	CC $(FLAGS) -o server server.c

clean:
	$(RM) client
	$(RM) server

fclean:
	$(RM) client
	$(RM) server
	
re: fclean all