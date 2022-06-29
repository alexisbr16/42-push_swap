# VARIABLE
NAME	= push_swap

CC		= gcc
CFLAGS	= -Wall		\
		  -Wextra	\
		  -Werror	\
		  -g -fsanitize=address

SRCS_PATH	= srcs/
SRCS		= push_swap.c					\
			  check_and_fix.c				\
			  operations-push.c				\
			  operations-reverse_rotate.c	\
			  operations-rotate.c			\
			  operations-swap.c				\
			  parsing.c						\
			  print-tool.c					\
			  sorting.c						\
			  sorting2.c					\
			  sorting3.c					\
			  utils-stack.c					\
			  utils-stack2.c				\
			  utils.c

OBJS_PATH	= objs/
OBJS		= $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
vpath %.c $(SRCS_PATH)

INC	= -I./includes/ -I./libft/includes/

LIBFT = libft/libft.a

# COMPILATION
$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "Push_swap Done !"

$(LIBFT):
	@make -C libft/

$(OBJS_PATH)%.o : %.c
	@mkdir -p $(OBJS_PATH)
	@echo "Compiling : $<"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# RULES
all	: $(NAME)

clean : 
	@make -C libft/ clean
	@rm -rf $(OBJS) $(OBJS_PATH)
	@echo "Push_swap : Remove objects"

fclean : clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "Push_swap : Remove $(NAME)"

re : fclean all

.PHONY : all clean fclean re
