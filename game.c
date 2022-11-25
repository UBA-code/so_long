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
	win = mlx_new_window(mlx, w * 32, (h * 32) + 32, "l3ba hhh");
	close(fd);
	return (win);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 126)
		player_move(*game, 1, 0);
	if (keycode == 1 || keycode == 125)
		player_move(*game, -1, 0);
	if (keycode == 0 || keycode == 123)
		player_move(*game, 0, 1);
	if (keycode == 2 || keycode == 124)
		player_move(*game, 0, -1);
	if (keycode == 53)
	{
		close_message();
		free(game->map);
		exit(1);
	}
	return (0);
}

int close_win(t_game *game)
{
	close_message();
	free(game->map);
	exit(1);
	return (0);
}

int main (int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		return (0);
	if (!check_file(argv[1]))
		return (ft_error("Please check if the extension of file is .ber\n"));
	game.map = get_map(argv[1]);
	if (!check_map(game))
		return (invalid_message());
	if (!check_path(argv[1]))
		return (0);
	game.mlx = mlx_init();
	game.win = get_window_size(game.mlx, argv[1]);
	render_map(&game);
	mlx_string_put(game.mlx, game.win, 0, 0, 0x001958b9, "Number of moves is : 0");
	mlx_hook(game.win, 2, 0, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_win, &game);
	mlx_loop(game.mlx);
}
