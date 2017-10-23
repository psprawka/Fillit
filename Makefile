# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/12 18:33:48 by psprawka          #+#    #+#              #
#    Updated: 2017/10/15 15:02:27 by jchung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fillit
CFLAGS = -Wall -Werror -Wextra

HEAD = fillit.h

SRCS = valid_mino.c \
	solver.c \
	rest.c \
	main.c \

LIBS = libft/libft.a	


all: $(NAME)

$(LIBS):
	@make -C libft

$(NAME): $(LIBS)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBS) -I. -o $(NAME)

clean:
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY = all clean fclean re
	


	
