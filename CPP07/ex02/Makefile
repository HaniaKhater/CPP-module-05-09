# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hania <hania@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 23:28:46 by hania             #+#    #+#              #
#    Updated: 2023/04/25 08:46:14 by hania            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Array

COMPILER	=	c++

CFLAGS		=	-g3 -Wall -Wextra -Werror -std=c++98

INCS		=   ./Array.hpp\

SRCS		=	./main.cpp\

OBJS		=	$(SRCS:.cpp=.o)

.cpp.o:
			${COMPILER} ${CFLAGS} -c $< -o $(<:.cpp=.o)

all:		$(NAME)

$(NAME):	$(INCS) $(OBJS)
		$(COMPILER) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
