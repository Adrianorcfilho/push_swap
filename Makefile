# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrocha- <adrocha-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/25 21:52:46 by adrocha-          #+#    #+#              #
#    Updated: 2025/08/17 17:10:08 by adrocha-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -g -Wall -Wextra -Werror 
RM = rm -f

SRCS_DIR = srcs

SRCS_FILES = main.c \
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

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME) rm -r $(OBJ_DIR)

re: fclean all

r:
	@make re && ./push_swap 25 0 -30

.PHONY: all clean fclean re