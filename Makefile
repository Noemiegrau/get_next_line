
NAME	=	get_next_line.a

SRC	=	get_next_line.c get_next_line_utils.c \

OBJ	=	$(SRC:.c=.o)

CC	=	cc

FLAGS	=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean bonus all re