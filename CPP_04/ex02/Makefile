NAME = abstractAnimal
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MDD -MP

FILES = Animal.cpp main.cpp Dog.cpp Cat.cpp Brain.cpp
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(FILES:.cpp=.o)))
DEPS = $(addprefix $(OBJ_DIR)/, $(notdir $(FILES:.cpp=.d)))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo " Compilation finished! 👍"

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
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
