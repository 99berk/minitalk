CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

PRINTF_SRC = ft_printf.c ft_print_ptr.c ft_print_hex.c ft_put_utils.c
PRINTF_HEADER = ft_printf.h
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)

OBJECTS = $(PRINTF_OBJ)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c $(PRINTF_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
