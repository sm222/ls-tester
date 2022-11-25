SRC = get_next_line_main.c \
	  main_utils.c

CC = clang
CFLAGS = -Wall -Werror -Wextra

all:
	$(CC) $(CFLAGS) $(SRC)
	@echo "compile"
clean:
	rm -f a.out
leaks: 
	$(CC) $(CFLAGS) $(SRC) -D LEAK=1
re: clean all
releaks: clean leaks
