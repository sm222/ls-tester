NAME			=	ls_tester.out

CT				=	C_tool.a
CT_DIR			=	C_tools/

RL_DIR			=	readline/
RL_H			=	libhistory.a
RL_L			=	libreadline.a

# Compiler and flags
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -g
#-fsanitize=addres
RM				=	rm -f

# Sources are all .c files
SRCS	=	tester/main.c\
			tester/read_ft.c\

#env -i ./minishell

OBJS	=	$(SRCS:.c=.o)

USER = $(shell whoami)

all: tools $(NAME)
	
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -l readline -l ncurses \
	$(RL_DIR)$(RL_H) $(RL_DIR)$(RL_L) $(CT_DIR)$(CT) $(EXECUTION_DIR)$(EXECUTION_LIB) \
	-o $(NAME)


#https://github.com/sm222/C_tools
tools:
	@make -C $(CT_DIR)

lib:
	@make -C $(LIB_DIR)

# Removes objects
clean:
	$(RM) $(OBJS)
	make -C $(CT_DIR) clean


# Removes objects and executables
fclean: clean
	$(RM) $(NAME)
	make -C $(CT_DIR) fclean

run: all
	@./$(NAME)

mc: all clean

# Removes objects and executables and remakes
re: fclean all

.PHONY: all libft