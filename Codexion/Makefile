NAME = library.a

SOURCES = parser.c

OBJECTS = $(SOURCES:%.c=%.o)

CC = cc

MAIN_FILE = main.c

CFLAGS = -Wall -Wextra -Werror

COMPRESS = ar rcs

RM = rm -f

all: $(NAME)
	$(CC) $(MAIN_FILE) $(NAME)
	$(RM) $(OBJECTS) $(NAME)
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