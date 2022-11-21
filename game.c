#include "so_long.h"

void get_window_size(int *w, int *h, char *path)
{
	int fd = open(path, O_RDONLY);
	char *line;

	while (1)
	{
		line = get_next_line(fd);
		if (line)
			++*h;
		else
		{
			free(line);
			break;
		}
		*w = get_str_len(line);
		free(line);
	}
	close(fd);
}

int main (int argc, char **argv)
{
	t_game_main_utils game;

	game.h = 0;
	game.w = 0;
	game.map_fd = open(argv[1], O_RDONLY);

	if (check_map(argv[1]))
	{
		get_window_size(&game.w, &game.h, argv[1]);
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, (32 * game.w), (32 * game.h), "window");
		game.map_fd = open("./maps", O_RDONLY);
		while (1)
		{
			game.line = get_next_line(game.map_fd);
			if (!game.line)
				break;
			put_line_to_window(game.mlx, game.win, game.line);
			free(game.line);
		}
		mlx_loop(game.mlx);
	}
}
