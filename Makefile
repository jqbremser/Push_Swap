# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 11:37:59 by jbremser          #+#    #+#              #
#    Updated: 2024/03/19 14:02:51 by jbremser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Werror -Wextra

#C files
CFILES =	push_swap.c \
			free_error.c \
			wack_into_a.c \
			push_swap_utils.c \
			sort.c \
			swap.c \
			push.c \
			rotate.c \
			rev_rotate.c \
			set_move.c \
			init.c \
			init_b.c 

OFILES = $(CFILES:.c=.o)
			
LIBFT = LibFT/libft.a 

all: $(NAME)

$(NAME): $(OFILES)
	cd libft && make all 
	cc $(CFLAGS) $(LIBFT) $(OFILES) -o $(NAME)

libft:
	cd libft && make

clean:
	rm -f $(OFILES)
	cd libft  && make clean
	
fclean: clean
		rm -f $(NAME)
		cd libft && make fclean

re: fclean all

.PHONY : all clean fclean re