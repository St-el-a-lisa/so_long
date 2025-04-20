NAME = solong
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux -Ignl -g3
LDFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

LIBFT = libft/libft.a

SRCS = gnl/get_next_line_utils.c\
		gnl/get_next_line.c\
		srcs/print.map.c\
		srcs/end_game.c\
		srcs/moves.c\
		srcs/is_valid.c\
		srcs/solong.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)
	@$(MAKE) banner --silent

$(NAME): $(OBJ) $(LIBFT) 
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LIBFT) -o $(NAME)

$(LIBFT): 
	$(MAKE) -C libft --silent

banner:
	@echo "		\33[38;5;217m+=========================================================================+";
	@echo "		|                                                                         |";
	@echo "		|                                                                         |";
	@echo "		|      █████████              █████                                       |";
	@echo "		\33[38;5;218m|     ███░░░░░███            ░░███                                        |";
	@echo "		\33[38;5;225m|    ░███    ░░░   ██████     ░███         ██████  ████████    ███████    |";
	@echo "		\33[38;5;224m|    ░░█████████  ███░░███    ░███        ███░░███░░███░░███  ███░░███    |";
	@echo "		\33[38;5;223m|     ░░░░░░░░███░███ ░███    ░███       ░███ ░███ ░███ ░███ ░███ ░███    |";
	@echo "		\33[38;5;222m|     ███    ░███░███ ░███    ░███      █░███ ░███ ░███ ░███ ░███ ░███    |";
	@echo "		\33[38;5;221m|    ░░█████████ ░░██████     ███████████░░██████  ████ █████░░███████    |";
	@echo "		\33[38;5;220m|     ░░░░░░░░░   ░░░░░░     ░░░░░░░░░░░  ░░░░░░  ░░░░ ░░░░░  ░░░░░███    |";
	@echo "		|                                                             ███ ░███    |";
	@echo "		\33[38;5;226m|                                                            ░░██████     |";
	@echo "		|    ( (                                                      ░░░░░░      |";
	@echo "		|     ) )                                                                 |";
	@echo "		|    .....                                                                |";
	@echo "		|   |     |]                                                              |";
	@echo "		|    \   /                                                                |";
	@echo "		|    =====                                                                |";
	@echo "		+=========================================================================+";

%.o: %.c
	@$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C libft fclean --silent

fclean: clean
	@rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re banner 
