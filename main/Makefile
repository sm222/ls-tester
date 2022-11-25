SRC = get_next_line_main.c \
	  main_utils.c

CC = clang
CFLAGS = -Wall -Werror -Wextra

all:
	$(CC) $(CFLAGS) $(SRC)
	@echo "compile"
clean:
	@rm -f a.out
leaks: 
	$(CC) $(CFLAGS) $(SRC) -D LEAKS=1
