# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/25 21:52:46 by adrocha-          #+#    #+#              #
#    Updated: 2025/07/25 21:53:07 by adrocha-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
SRC = 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@
 
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re