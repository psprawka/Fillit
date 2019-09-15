# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/12 18:33:48 by psprawka          #+#    #+#              #
#    Updated: 2019/09/15 22:26:54 by psprawka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fillit
CFLAGS = -Wall -Werror -Wextra

HEAD = fillit.h

SRCS = srcs/valid_mino.c \
	srcs/solver.c \
	srcs/rest.c \
	srcs/main.c \

LIBS = Libft/libft.a	


all: $(NAME)

$(LIBS):
	@make -C Libft

$(NAME): $(LIBS)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBS) -I. -o $(NAME)

clean:
	@make -C Libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C Libft fclean

re: fclean all

.PHONY = all clean fclean re
	


	
