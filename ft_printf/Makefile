NAME = libftprintf.a

SOURCES = ft_printf.c ft_printf_utils.c

OBJECTS = $(SOURCES:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
COMPRESS = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	$(COMPRESS) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
