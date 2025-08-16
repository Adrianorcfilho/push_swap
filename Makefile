# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/25 21:52:46 by adrocha-          #+#    #+#              #
#    Updated: 2025/08/16 21:29:12 by adrocha-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -g -Wall -Wextra -Werror 
RM = rm -f

SRC = main.c \
parsing.c \
free_error_exit.c \
utils.c \
stack.c \
swap.c \
push.c \
rotate.c \
reverse.c \
radix.c \
3_to_5_cases.c \

	
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

r:
	make re && ./push_swap 25 0 -30

.PHONY: all clean fclean re