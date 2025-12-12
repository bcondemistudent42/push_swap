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

SRCS	= ft_ops.c					\
		  ramaroud.c					\
		  bcondemi.c

OBJS	= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
SRC_INCLUDES	= header.h
NAME			= push_swap

all:		$(NAME)

$(NAME):	$(OBJS) $(SRC_INCLUDES)
			$(CC) $(OBJS) -o $(NAME) 

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:		fclean all

%.o:		%.c libft.h
			$(CC) $(CFLAGS) -c $< -o $@

.PHONY:		all clean fclean re
