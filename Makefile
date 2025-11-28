# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afomin afomin@student.42kl.edu.my          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/24 19:01:24 by afomin            #+#    #+#              #
#    Updated: 2025/11/28 16:09:53 by afomin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBC = ar -rcs
RM = rm -f

FILES = stack_functions.c utils.c push_swap.c args_functions.c

OBJS = $(FILES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: ${NAME}

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)
	
bonus: $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
