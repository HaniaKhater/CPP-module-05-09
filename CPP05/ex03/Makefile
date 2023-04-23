# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hania <hania@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 23:28:46 by hania             #+#    #+#              #
#    Updated: 2023/04/23 07:52:24 by hania            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Intern

COMPILER	=	c++

CFLAGS	= -g3	-Wall -Wextra -Werror -std=c++98

INCS	= ./Bureaucrat.hpp\
		./AForm.hpp\
		./ShrubberyCreationForm.hpp\
		./RobotomyRequestForm.hpp\
		./PresidentialPardonForm.hpp\
		./Intern.hpp\

SRCS	=	./main.cpp\
		./Bureaucrat.cpp\
		./AForm.cpp\
		./ShrubberyCreationForm.cpp\
		./RobotomyRequestForm.cpp\
		./PresidentialPardonForm.cpp\
		./Intern.cpp

OBJS	=	$(SRCS:.cpp=.o)

.cpp.o:
			${COMPILER} ${CFLAGS} -c $< -o $(<:.cpp=.o)

all:		$(NAME)

$(NAME):	$(INCS) $(OBJS)
		$(COMPILER) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME)
	rm -rf *_shrubbery

re:			fclean all

.PHONY:		all clean fclean re
