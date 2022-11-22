SRCS = game.c put_line_to_window.c ./1337_get_next_line/get_next_line_utils.c ./1337_get_next_line/get_next_line.c \
		./srcs/game_utils.c ./srcs/get_map.c ./srcs/render_map.c \
		./moving/move_up.c
# CFLAGS = -Wall -Wextra -Werror
OBGS = $(SRCS:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBGS)
	$(CC) $(OBGS) -L /usr/local/lib/ -lmlx -framework OpenGl -framework AppKit

clean:
	rm -rf $(OBGS)

fclean: clean
	rm -rf $(NAME)

re: fclean all