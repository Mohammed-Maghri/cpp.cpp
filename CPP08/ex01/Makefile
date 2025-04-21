SRC  = main.cpp  Span.cpp
OBJS = $(SRC=.o:.cpp)
NAME = cont
RM = rm -rf 
CC = c++ 
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

%.o : %.cpp Span.hpp
	$(CC) $(CFLAGS) $(SRC) -c $< -o $@

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all 