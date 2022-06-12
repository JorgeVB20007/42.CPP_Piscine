# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 19:55:35 by jvacaris          #+#    #+#              #
#    Updated: 2022/06/12 22:04:43 by jvacaris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOR_RESET = \033[0m
COLOR_GREEN = \033[0;32m
COLOR_YELLOW = \033[0;33m
COLOR_BLUE = \033[1;34m
COLOR_CYAN = \033[0;36m

SRCS =	main.cpp

NAME = brain

OBJS = $(SRCS:.cpp=.o)

${NAME}:	${SRCS}
			@echo "${COLOR_YELLOW}- Compilation started.${COLOR_RESET}"
			@c++ -Wall -Werror -Wextra ${SRCS} -o ${NAME}
			@echo "${COLOR_GREEN}- Compilation done.${COLOR_RESET}"

all: ${NAME}

clean:
			@echo "${COLOR_CYAN}- Cleaning objects.${COLOR_RESET}"
			@rm -rf ${OBJS}

fclean:		clean
			@echo "${COLOR_CYAN}- Cleaning executable:${COLOR_BLUE}" ${NAME}"${COLOR_RESET}""."
			@rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
