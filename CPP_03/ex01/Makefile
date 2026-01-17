# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/17 21:38:16 by pmendez-          #+#    #+#              #
#    Updated: 2026/01/17 18:49:32 by pmendez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scavTrap
CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address,leak

FILES = main.cpp ClapTrap.cpp ScavTrap.cpp

OBJS = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	@$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo " Compilation finished! 👍"

clean:
	@rm -f $(OBJS)
	@echo "Cleaning finished! 🧹"

fclean: clean
	@rm -f $(NAME)
	@echo " Deleting finished! 🗑"

re: fclean all

.PHONY: all clean fclean re
