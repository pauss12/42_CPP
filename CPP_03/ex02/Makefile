# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/17 21:38:16 by pmendez-          #+#    #+#              #
#    Updated: 2025/10/18 19:19:30 by pmendez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FragTrap
CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

FILES = main.cpp ClapTrap.cpp FragTrap.cpp

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
