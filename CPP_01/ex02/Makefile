NAME = reference
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP
OBJS_DIR = obj
FILES = main.cpp

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(FILES:.cpp=.o)))
DEPS = $(addprefix $(OBJS_DIR)/, $(notdir $(FILES:.cpp=.d)))

all: $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS) 
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo " Compilation finished! 👍"

$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
-include $(DEPS)

clean:
	@rm -f $(OBJS) $(DEPS)
	@rmdir --ignore-fail-on-non-empty $(OBJS_DIR) 2> /dev/null || true
	@echo "Cleaning finished! 🧹"

fclean: clean
	@rm -f $(NAME)
	@echo " Deleting finished! 🗑"

re: fclean all

.PHONY: all clean fclean re