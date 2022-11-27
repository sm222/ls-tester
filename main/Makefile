SRC = get_next_line_main.c \
	  main_utils.c\
	  ls_tester.c\
	  anboisve_ft.c


CC = clang
CFLAGS = -Wall -Werror -Wextra

all:
	$(CC) $(CFLAGS) $(SRC)
	@echo "\x1B[32mcompile\x1B[37m"
clean:
	rm -f a.out
leaks: 
	$(CC) $(CFLAGS) $(SRC)
re: clean all
releaks: clean leaks
