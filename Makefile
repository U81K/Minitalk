# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 18:17:20 by bgannoun          #+#    #+#              #
#    Updated: 2023/01/19 03:15:04 by bgannoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf
SRC		= 	client.c server.c
OBJ		=	$(SRC:.c=.o)
LIBFT	=	libft/libft.a
PRINTF	=	ft_printf/libftprintf.a

all			:	client server

client		:	client.o $(LIBFT) $(PRINTF)
		$(CC) $(CFLAGS) -o client client.o $(LIBFT) $(PRINTF)

server		:	server.o $(LIBFT) $(PRINTF)
		$(CC) $(CFLAGS) -o server server.o $(LIBFT) $(PRINTF)

$(PRINTF)	:
		cd ft_printf/ && $(MAKE)

$(LIBFT)	:
		cd libft/ && $(MAKE)

clean		:
		$(RM) $(OBJ)
		cd libft/ && $(MAKE) clean
		cd ft_printf/ && $(MAKE) clean

fclean		:	clean
		$(RM) client server $(PRINTF) $(LIBFT)

re			:	fclean all