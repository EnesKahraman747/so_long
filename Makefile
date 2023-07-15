NAME		= so_long
SRCS		= $(wildcard ./*.c)
OBJS		= $(SRCS:.c=.o)
PF			= ft_printf/libftprintf.a
CFLAGS		= -Wall -Wextra -Werror
LFLAGS		= -framework OpenGL -framework AppKit -L ./minilibx -lmlx -L ./ft_printf -lftprintf

all: $(NAME)

$(NAME): $(OBJS) $(PF)
	make -C ./minilibx 2> /dev/null
	gcc $(LFLAGS) $(OBJS) -o $(NAME)

$(PF):
	make -C ./ft_printf

clean:
	make -C ./minilibx clean
	make -C ./ft_printf clean
	rm -rf $(OBJS)

fclean:
	make -C ./ft_printf fclean
	make -C ./minilibx clean
	rm -rf $(OBJS)
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
