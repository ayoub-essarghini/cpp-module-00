NAME=phonebook
INCLUDES=phonebook.hpp
SRCS=phonebook.cpp contact.cpp main.cpp

CFLAGS= -Wall -Wextra -Werror -std=c++98

OBJS=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(INCLUDES) $(OBJS)
	c++ $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "DONE ✅"

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re:clean all

.PHONY: all clean fclean re