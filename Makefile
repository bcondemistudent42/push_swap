# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramaroud <ramaroud@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 18:08:48 by ramaroud          #+#    #+#              #
#    Updated: 2025/11/20 13:32:23 by ramaroud         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_ops.c		\
		gnl_utils.c		\
		ramaroud.c		\
		bcondemi.c		\
		main_push_swap.c
OBJS	= $(SRCS:.c=.o)

BONUS	= ft_ops.c		\
		gnl.c			\
		gnl_utils.c		\
		ramaroud.c		\
		main_checker.c
BONUS_OBJS = $(BONUS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
SRC_INCLUDES	= header.h
NAME			= push_swap
BONUS_NAME		= checker

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) -o $(NAME) 

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME) $(BONUS_NAME) .bonus

re:		fclean all

bonus:	.bonus

.bonus:		$(BONUS_OBJS)
			$(CC) $(BONUS_OBJS) -o $(BONUS_NAME)
			touch .bonus

%.o:		%.c header.h
			$(CC) $(CFLAGS) -c $< -o $@

.PHONY:		all clean fclean re bonus
