# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afomin afomin@student.42kl.edu.my          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/24 19:01:24 by afomin            #+#    #+#              #
#    Updated: 2025/12/01 19:02:02 by afomin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
TEST_NAME = push_swap_test
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

FILES = stack_push.c stack_rotate.c stack_utils.c \
		utils.c push_swap.c args_functions.c

all: ${NAME}

$(NAME): $(FILES)
	$(CC) main.c $(FILES) -o $(NAME)
	
test: $(FILES)
	$(CC) test.c $(FILES) -o $(TEST_NAME)

clean:
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)

fclean:
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)

re: clean all

.PHONY: all test clean fclean re
