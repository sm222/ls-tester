SRC = get_next_line_main.c \
	  main_utils.c

CC = clang
CFLAGS = -Wall -Werror -Wextra

all:
	$(CC) $(CFLAGS) $(SRC)
	@echo "compile"
leaks: 
	$(CC) $(CFLAGS) $(SRC) -D LEAKS=1
