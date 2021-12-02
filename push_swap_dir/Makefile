# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamori <velvelhype@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 03:20:19 by kamori            #+#    #+#              #
#    Updated: 2021/11/23 04:47:58 by kamori           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Werror -Wall -Wextra
CFLAGS =
SRCS = checks.c \
pre_error_check.c \
controls.c \
prepare_list.c \
push_swap.c \
sorts.c \
quick_sort_2.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

run: all
	./$(NAME) 3 2 1

debug: CFLAGS+= -fsanitize=address
debug: re
N = 100
R = 100
ARG:= $(shell python3 -c 'import random; random.seed($(R)); print(*random.sample([i for i in range(0, 100)], $(N)))')

test: re
	cd ./push_swap_tester && python3 push_swap_tester.py -l 100 -c 300

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all