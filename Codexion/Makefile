NAME = library.a

SOURCES = utils/parser/add_next_coder.c \
		utils/parser/add_previous_coder.c \
		utils/parser/create_coder.c \
		utils/parser/create_circle.c \
		utils/print_functions/print_args.c \
		utils/print_functions/print_circle.c \
		utils/parser/handle_circle.c \
		utils/parser/parser.c \
		utils/auxiliar/create_dongles.c \
		utils/print_functions/print_dongles.c

OBJECTS = $(SOURCES:%.c=%.o)

CC = cc

MAIN_FILE = main.c

CFLAGS = -Wall -Wextra -Werror -pthread

COMPRESS = ar rcs

RM = rm -f


#A1 = -D NUMBER_OF_CODERS=23
#A2 = -D TIME_TO_BURNOUT=23
#A3 = -D TIME_TO_COMPILE=23
#A4 = -D TIME_TO_DEBUG=23
#A5 = -D TIME_TO_REFACTOR=23
#A6 = -D NUMBER_OF_COMPILES_REQUIRED=23
#A7 = -D DONGLE_COOLDOWN=23
#A8 = -D SCHEDULER='"fifosdf"'


#ARGUMENTS = $(A1) $(A2) $(A3) $(A4) $(A5) $(A6) $(A7) $(A8)

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