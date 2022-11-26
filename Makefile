SRCS = game.c put_line_to_window.c ./1337_get_next_line/get_next_line_utils.c ./1337_get_next_line/get_next_line.c \
		./srcs/game_utils.c ./srcs/get_map.c ./srcs/render_map.c ./srcs/check_map.c ./srcs/check_map_two.c ./srcs/check_path.c \
		./srcs/messages.c \
		./moving/move_up.c ./moving/move_enemy.c
CFLAGS = -Wall -Werror -Wextra
OBGS = $(SRCS:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBGS)
	$(CC) -o $(NAME) $(CFLAGS) -lmlx -framework OpenGl -framework AppKit $(OBGS)

clean:
	rm -rf $(OBGS)

fclean: clean
	rm -rf $(NAME)

re: fclean all