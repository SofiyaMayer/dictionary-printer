NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c core_functions.c useful_functions.c create_dictionary.c read_file.c parse.c
OBJS = $(SRCS:.c=.o)
HEADERS = useful_functions.h core_functions.h parse.h read_file.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
