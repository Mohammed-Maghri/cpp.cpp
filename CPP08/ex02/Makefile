SRC  = main.cpp
OBJS = $(SRC=.o:.cpp)
NAME = cont
RM = rm -rf 
CC = c++ -std=c++98
CFLAGS = -Wall -Wextra -Werror 

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

%.o : %.cpp MutantStack.hpp
	$(CC) $(CFLAGS) $(SRC) -c $< -o $@

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all 