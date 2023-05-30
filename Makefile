# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 16:27:24 by ivanderw          #+#    #+#              #
#    Updated: 2023/05/24 18:18:06 by ivanderw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SOURCE  =  	sources/utilities/*.c			\
			sources/operations/*.c			\
			sources/sorting_algorithms/*.c	\
			sources/push_swap.c				\

$(NAME):
	$(CC) $(FLAGS) $(SOURCE) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf sources/*.o
	@rm -rf sources/operations/*.o
	@rm -rf sources/sorting_algorithms/*.o
	@rm -rf sources/utilities/*.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
