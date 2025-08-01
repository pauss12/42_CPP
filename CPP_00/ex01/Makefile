NAME = phoneBook
CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

FILES = PhoneBook.cpp Contact.cpp main.cpp utils.cpp
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