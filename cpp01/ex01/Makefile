# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 20:41:44 by jvacaris          #+#    #+#              #
#    Updated: 2022/06/12 21:50:03 by jvacaris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOR_RESET = \033[0m
COLOR_GREEN = \033[0;32m
COLOR_YELLOW = \033[0;33m
COLOR_BLUE = \033[1;34m
COLOR_CYAN = \033[0;36m

SRCS =	main.cpp	\
		Zombie.cpp		\
		ZombieHorde.cpp		\
		
SRCS_DIR = ./

INCLUDE =	Zombie.hpp	

INCLUDE_DIR = ./

OBJS_DIR = ./objs/

GCC = clang++

CPP_FLAGS = -Wall -Werror -Wextra -std=c++98

NAME = manyzombies

OBJ_FILES = $(SRCS:.cpp=.o)
OBJ_FILES_INFOLDER = $(addprefix $(OBJS_DIR), $(OBJ_FILES))

all: obj $(NAME)

obj:
	@mkdir -p $(OBJS_DIR)


$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp
	@$(GCC) $(CPP_FLAGS) -I $(INCLUDE_DIR) -o $@ -c $<

$(NAME): $(OBJ_FILES_INFOLDER)
	@echo "$(COLOR_YELLOW)- Compilation started.$(COLOR_RESET)"
	@$(GCC) $(CPP_FLAGS) $(OBJ_FILES_INFOLDER) -o $(NAME)
	@echo "$(COLOR_GREEN)- Compilation done.$(COLOR_RESET)"


clean:
			@echo "$(COLOR_CYAN)- Cleaning objects.$(COLOR_RESET)"
			@rm -rf $(OBJS_DIR)

fclean:		clean
			@echo "$(COLOR_CYAN)- Cleaning executable:$(COLOR_BLUE)" $(NAME)"$(COLOR_RESET)""."
			@rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
