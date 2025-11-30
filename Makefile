# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afomin afomin@student.42kl.edu.my          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/24 19:01:24 by afomin            #+#    #+#              #
#    Updated: 2025/11/30 17:19:44 by afomin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

FILES = stack_push.c stack_rotate.c stack_utils.c \
		utils.c push_swap.c args_functions.c

all: ${NAME}

$(NAME): $(FILES)
	$(CC) main.c $(FILES) -o $(NAME)
	
test: $(FILES)
	$(CC) test.c $(FILES) -o $(NAME)

.PHONY: all test
