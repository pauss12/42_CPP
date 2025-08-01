NAME = account
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

FILES = Account.cpp tests.cpp 
		
OBJS = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo " Compilation finished! 👍"

clean:
	@rm -f $(OBJS)
	@echo "Cleaning finished! 🧹"

fclean: clean
	@rm -f $(NAME)
	@echo " Deleting finished! 🗑"

re: fclean all

.PHONY: all clean fclean re