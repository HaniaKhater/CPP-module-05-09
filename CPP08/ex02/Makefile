# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hania <hania@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 23:28:46 by hania             #+#    #+#              #
#    Updated: 2023/04/26 06:28:32 by hania            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	MutantStack

COMPILER	=	c++

CFLAGS		=	-g3 -Wall -Wextra -Werror -std=c++98

INCS		=   ./MutantStack.hpp\

SRCS		=	./main.cpp\
			./MutantStack.cpp\

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
