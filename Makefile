NAME    = lem-in
LIBFT     = libft/
CFLAGS  = -Wall -Wextra -Werror
CC      = gcc

ALGO    =	algorithm/find_all_paths.c algorithm/find_no_intersecting_paths.c \
			algorithm/find_room.c algorithm/find_tunnels_with_rooms.c \
			algorithm/parse_rooms.c algorithm/parse_tunnels.c \
			algorithm/send_ants.c

PRINT	=	printing/print_ants.c printing/print_ants_on_screen.c

SUPPORT =	support_functions/ft_join_free.c \
			support_functions/ft_put_error.c \
			support_functions/support_functions.c \

VALID	=	validations/check_ants.c validations/check_change_tunnel.c \
			validations/check_commands.c validations/check_comments.c \
			validations/check_empty_struct.c validations/check_line_break.c \
			validations/check_rooms.c validations/check_spaces.c \
			validations/check_start_end.c validations/check_tunnels.c \
			validations/validation.c

MAIN	=	main.c

SRCS	=	$(ALGO) $(PRINT) $(SUPPORT) $(VALID) $(MAIN)

OBJS    =	$(SRCS:.c=.o)

RED		=	\033[0;31m
GREEN	=	\033[0;32m
NC		=	\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling lem-in library...$(NC)"
	@make -C $(LIBFT)
	@$(CC) $(SRCS) $(LIBFT)libft.a -o $(NAME)
	@echo "$(GREEN)Exercutable lem-in was created$(NC)"

.c.o:
	@$(CC) $(CFLAGS) -c $<  -o $@

clean:
	@echo "$(RED)Deleting lem-in object files...$(NC)"
	@rm -rf $(OBJS)
	@make -C $(LIBFT) clean

fclean: clean
	@echo "$(RED)Deleting lem-in exercutable...$(NC)"
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

