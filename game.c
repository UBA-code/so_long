#include "so_long.h"

void *get_window_size(void *mlx, char *path)
{
	int fd = open(path, O_RDONLY);
	char *line;
	void *win;
	int w;
	int h;

	w = 0;
	h = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line)
			++h;
		else
		{
			free(line);
			break;
		}
		w = get_str_len(line);
		free(line);
	}
	win = mlx_new_window(mlx, w * 32, h * 32, "Game");
	close(fd);
	return (win);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 1 || keycode == 125)
		move_down(*game);
	if (keycode == 13 || keycode == 126)
		move_up(*game);
	if (keycode == 0 || keycode == 123)
		move_left(*game);
	if (keycode == 2 || keycode == 124)
		move_right(*game);
	if (keycode == 53)
	{
		free(game->map);
		exit(1);
	}
	return (0);
}

int main (int argc, char **argv)
{
	t_game game;

	game.mlx = mlx_init();
	game.win = get_window_size(game.mlx, argv[1]);
	game.map = get_map(argv[1]);
	render_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
}
