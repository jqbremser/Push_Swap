# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 11:50:33 by jbremser          #+#    #+#              #
#    Updated: 2024/03/07 17:48:34 by jbremser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror -g #del g flag before eval

#Source files
CFILES =	push_swap.c \
			error_handling.c \
			push_swap_utils.c \
			rotate.c \
			r_rotate.c \
			swap.c \
			push.c \
			sort.c \
			init_a.c \
			init_b.c

LIBFT = LibFT/libft.a \

all: libft $(NAME)

$(NAME): $(CFILES) $(LIBFT)
	cc $(CFLAGS) $(LIBFT) $(CFILES) -o $(NAME)

libft:
	make -C libft

clean: 
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make clean -C libft
	
re: fclean all

.PHONY : all clean fclean re