NAME = solong
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux -Ignl -g3
LDFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

LIBFT = libft/libft.a

SRCS = gnl/get_next_line_utils.c\
		gnl/get_next_line.c\
		libft/ft_printf/ft_printf.c \
		libft/ft_printf/ft_printf_utils.c \
		print.map.c\
		main.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)
	@$(MAKE) --no-print-directory banner

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LIBFT) -o $(NAME)

banner:
	@echo "		\33[38;5;199m+=========================================================================+";
	@echo "		|                                                                         |";
	@echo "		|                                                                         |";
	@echo "		|      █████████              █████                                       |";
	@echo "		\33[38;5;208m|     ███░░░░░███            ░░███                                        |";
	@echo "		\33[38;5;210m|    ░███    ░░░   ██████     ░███         ██████  ████████    ███████    |";
	@echo "		\33[38;5;221m|    ░░█████████  ███░░███    ░███        ███░░███░░███░░███  ███░░███    |";
	@echo "		\33[38;5;227m|     ░░░░░░░░███░███ ░███    ░███       ░███ ░███ ░███ ░███ ░███ ░███    |";
	@echo "		\33[38;5;207m|     ███    ░███░███ ░███    ░███      █░███ ░███ ░███ ░███ ░███ ░███    |";
	@echo "		\33[38;5;141m|    ░░█████████ ░░██████     ███████████░░██████  ████ █████░░███████    |";
	@echo "		\33[38;5;129m|     ░░░░░░░░░   ░░░░░░     ░░░░░░░░░░░  ░░░░░░  ░░░░ ░░░░░  ░░░░░███    |";
	@echo "		|                                                             ███ ░███    |";
	@echo "		\33[38;5;5m|                                                            ░░██████     |";
	@echo "		|                                                             ░░░░░░      |";
	@echo "		|                                                                         |";
	@echo "		+=========================================================================+";

%.o: %.c
	@$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re banner 
