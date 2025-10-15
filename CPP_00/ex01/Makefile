# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 21:06:27 by pmendez-          #+#    #+#              #
#    Updated: 2025/10/15 21:06:29 by pmendez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phoneBook
CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

FILES = PhoneBook.cpp Contact.cpp main.cpp Utils.cpp
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
