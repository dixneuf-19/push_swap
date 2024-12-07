SRC = 
OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME):

clean:

fclean: clean

re: fclean all

.PHONY: clean