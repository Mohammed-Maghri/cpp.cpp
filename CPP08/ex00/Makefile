SRC  = main.cpp 
OBJS = $(SRC=.c:.cpp)
NAME = cont
RM = rm -rf 
CC = c++ 
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) $(SRC) -c $< -o $@

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all 