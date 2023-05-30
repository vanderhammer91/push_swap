# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 16:27:24 by ivanderw          #+#    #+#              #
#    Updated: 2023/05/30 21:49:53 by ivanderw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SOURCE  =  	sources/push_swap.c										\
			sources/operations/ft_pa.c								\
			sources/operations/ft_rr.c								\
			sources/operations/ft_rrr.c								\
			sources/operations/ft_ss.c								\
			sources/sorting_algorithms/cost_sort.c					\
			sources/sorting_algorithms/cost_utilities.c				\
			sources/sorting_algorithms/ft_refresh_current_costs.c	\
			sources/sorting_algorithms/ft_refresh_current_targets.c	\
			sources/sorting_algorithms/rr_utilities.c				\
			sources/sorting_algorithms/rrr_utilities.c				\
			sources/utilities/check_utils.c							\
			sources/utilities/ft_atoi.c								\
			sources/utilities/ft_get_maxdex.c						\
			sources/utilities/ft_get_middex.c						\
			sources/utilities/ft_get_mindex.c						\
			sources/utilities/ft_get_steps_to_top.c					\
			sources/utilities/ft_is_sorted.c						\
			sources/utilities/ft_lstadd_back.c						\
			sources/utilities/ft_lstadd_front.c						\
			sources/utilities/ft_lstlast.c							\
			sources/utilities/ft_lstnew.c							\
			sources/utilities/ft_lstnew_plus_index.c				\
			sources/utilities/ft_lstremove_back.c					\
			sources/utilities/ft_lstremove_front.c					\
			sources/utilities/ft_lstsize.c							\
			sources/utilities/ft_print_status.c						\
			sources/utilities/ft_printbr.c							\
			sources/utilities/ft_printf.c							\
			sources/utilities/ft_printf_printadd_length.c			\
			sources/utilities/ft_printf_printchar_length.c			\
			sources/utilities/ft_printf_printdecimal_length.c		\
			sources/utilities/ft_printf_printhex_length.c			\
			sources/utilities/ft_printf_printstr_length.c			\
			sources/utilities/ft_printf_printunsigned_length.c		\
			sources/utilities/ft_putchar.c							\
			sources/utilities/ft_short_sort.c						\
			sources/utilities/ft_strdup.c							\
			sources/utilities/ft_strlen.c							\
			sources/utilities/ft_strncmp.c							\
			sources/utilities/ft_substr.c							\

$(NAME): 
	$(CC) $(FLAGS) $(SOURCE) -o $(NAME)

OBJS = ${SOURCE:.c=.o}

all: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
