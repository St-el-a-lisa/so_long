NAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_atoi.c \
      ft_printf/ft_printf.c \
      ft_printf/ft_printf_utils.c \
      ft_printf/ft_printf_utils2.c \
      

OBJ = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re