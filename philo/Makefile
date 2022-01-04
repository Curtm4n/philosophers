# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 21:32:37 by cdapurif          #+#    #+#              #
#    Updated: 2021/10/07 22:07:52 by cdapurif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS =	main.c \
		error.c \
		utils.c \
		utils2.c \
		init.c \
		simulation.c \
		cycle.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
