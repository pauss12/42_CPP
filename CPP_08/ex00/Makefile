NAME = easyfind
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP
OBJ_DIR = obj

FULL_NAME = tester_full
FULL_SRC = tester_full.cpp

FILES = main.cpp

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(FILES:.cpp=.o)))
DEPS = $(addprefix $(OBJ_DIR)/, $(notdir $(FILES:.cpp=.d)))

all: $(NAME)

makefull: $(FULL_NAME)
	@./$(FULL_NAME)

$(FULL_NAME): $(OBJ_DIR)/tester_full.o | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) $(OBJ_DIR)/tester_full.o -o $(FULL_NAME)

$(OBJ_DIR)/tester_full.o: $(FULL_SRC) | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $(FULL_SRC) -o $(OBJ_DIR)/tester_full.o

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS) 
	@$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)
	@echo " Compilation finished! 👍"

$(OBJ_DIR)/%.o: %.cpp $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
-include $(DEPS)

clean:
	@rm -f $(OBJS) $(DEPS) $(OBJ_DIR)/tester_full.o
	@rm -f $(OBJ_DIR)/tester_full.d 2> /dev/null || true
	@rm -rf $(OBJ_DIR) 2> /dev/null || true
	@echo "Cleaning finished! 🧹"

fclean: clean
	@rm -f $(NAME) $(FULL_NAME)
	@echo " Deleting finished! 🗑"

re: fclean all

.PHONY: all clean fclean re makefull