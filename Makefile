# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 18:17:20 by bgannoun          #+#    #+#              #
#    Updated: 2023/01/12 20:09:50 by bgannoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
FLAGS = -Wall -Wextra -Werror
RM = rm -fr

all:$(CLIENT) $(SERVER)

$(CLIENT):
	CC $(FLAGS) -o client client.c

$(SERVER):
	CC $(FLAGS) -o server server.c

clean:
	$(RM) client
	$(RM) server

fclean:
	$(RM) client
	$(RM) server
	
re:
	$(RM) client
	$(RM) server