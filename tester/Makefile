SRC = \
		ls_tester.c\
		main_utils.c\
		anboisve_ft.c\
		wdelaros_ft.c\
		main/PRINTF/printf_main.c\
		main/GNL/get_next_line_main.c\
		main/GNL/get_next_line_main_bonus.c\
		ls_gnl.c\
		ls_printf.c


CC = clang
CFLAGS = -Wall -Werror -Wextra

GRE		:= \033[1;32m
WHT		:= \033[0m
RED		:= \033[1;31m


all: Ctool
	@$(CC) $(CFLAGS) $(SRC) -o ls_tester.out
	@reset
# @afplay ./p.wav &>/dev/null &
Ctool:
	@make -C ../C_tools

clean:
	@make -C ../C_tools clean
	rm -f ls_tester.out

re: clean all

releaks: clean leaks Ctool
