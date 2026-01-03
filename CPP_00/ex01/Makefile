# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 21:06:27 by pmendez-          #+#    #+#              #
#    Updated: 2026/01/03 14:21:59 by pmendez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phoneBook
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP
OBJ_DIR = obj

FILES = PhoneBook.cpp Contact.cpp main.cpp Utils.cpp

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(FILES:.cpp=.o)))
DEPS = $(addprefix $(OBJ_DIR)/, $(notdir $(FILES:.cpp=.d)))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS) 
	@$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)
	@echo " Compilation finished! 👍"

$(OBJ_DIR)/%.o: %.cpp $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
-include $(DEPS)

clean:
	@rm -f $(OBJS) $(DEPS)
	@rmdir --ignore-fail-on-non-empty $(OBJ_DIR) 2> /dev/null || true
	@echo "Cleaning finished! 🧹"

fclean: clean
	@rm -f $(NAME)
	@echo " Deleting finished! 🗑"

re: fclean all

.PHONY: all clean fclean re