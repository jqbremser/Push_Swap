# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 11:50:33 by jbremser          #+#    #+#              #
#    Updated: 2024/02/23 14:26:46 by jbremser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap.a

CFLAGS = -Wall -Wextra -Werror

#Source files
CFILES =	push_swap.c \
			error_handling.c \

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