# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bakgun <bakgun@student.42kocaeli.com.tr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/10 17:00:19 by bakgun            #+#    #+#              #
#    Updated: 2023/09/10 17:00:22 by bakgun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SRCLIENT =   client.c
OBJSCLIENT = $(SRCLIENT:.c=.o)

SRCSERVER = server.c
OBJSERVER = $(SRCSERVER:.c=.o)

SRCLIENT_BONUS = client_bonus.c
OBJSCLIENT_BONUS = $(SRCLIENT_BONUS:.c=.o)

SRCSERVER_BONUS = server_bonus.c
OBJSERVER_BONUS = $(SRCSERVER_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
LIB = ./ft_printf/libftprintf.a 

all: $(NAME)

$(NAME): $(OBJSERVER) $(OBJSCLIENT)
	@make -C ./ft_printf
	@gcc -o server $(SRCSERVER) $(CFLAGS) $(LIB)
	@gcc -o client $(SRCLIENT) $(CFLAGS) $(LIB)

bonus: $(OBJSERVER_BONUS) $(OBJSCLIENT_BONUS)
	@make -C ./ft_printf
	@gcc -o server $(SRCSERVER_BONUS) $(CFLAGS) $(LIB)
	@gcc -o client $(SRCLIENT_BONUS) $(CFLAGS) $(LIB)

clean:
	rm -f $(OBJSERVER) $(OBJSCLIENT) $(OBJSERVER_BONUS) $(OBJSCLIENT_BONUS)
	rm -f ./ft_printf/*.o

fclean: clean
	rm -f server client
	rm -f ./ft_printf/*.o ./ft_printf/*.a

re: fclean all

.PHONY: all clean fclean re
