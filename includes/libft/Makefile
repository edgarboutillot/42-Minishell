NAME = libft.a
CC = gcc
SRCS = 	$(wildcard *.c)

OBJS = $(SRCS:.c=.o)
TOTAL_FILES = $(words $(SRCS))
COMPLETED_FILES = 0
FLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@
	$(eval COMPLETED_FILES=$(shell echo $$(($(COMPLETED_FILES)+1))))

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all