SRC = PmergeMe.cpp rec.cpp Dmerge.cpp
OBJS = ${SRC:.cpp=.o}
CC =  c++ -std=c++98
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
NAME = PmergeMe
RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp PmergeMe.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJS)

fclean : clean 
	$(RM) $(NAME)

re : clean all
