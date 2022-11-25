#include "../so_long.h"

int ft_tabchr(char **map, char c)
{
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void set_player(char **map, int y, int x, int old_y, int old_x)
{
	map[y][x] = 'P';
	map[old_y][old_x] = 'x';
}

void set_postion(char **map, int y, int x, int old_y, int old_x)
{
	map[old_y][old_x] = 'x';
	map[y][x] = 'P';
}

typedef struct s_utils
{
	int y;
	int x;
	int old_y;
	int old_x;
} utils;

void next_move(char **map, int y, int x)
{
	get_player_position(map, &y, &x);
	if (map[y][x + 1] != 'x' && map[y][x + 1] != '1')
	{
		set_postion(map, y, x + 1, y, x);
		next_move(map, y, x);
		set_player(map, y, x, y, x + 1);
	}
	if (map[y][x - 1] != 'x' && map[y][x - 1] != '1')
	{
		set_postion(map, y, x - 1, y, x);
		next_move(map, y, x);
		set_player(map, y, x, y, x - 1);
	}
	if (map[y - 1] && (map[y - 1][x] != 'x' && map[y - 1][x] != '1'))
	{
		set_postion(map, y - 1, x, y, x);
		next_move(map, y, x);
		set_player(map, y, x, y - 1, x);
	}
	if (map[y + 1] && (map[y + 1][x] != 'x' && map[y + 1][x] != '1'))
	{
		set_postion(map, y + 1, x, y, x);
		next_move(map, y, x);
		set_player(map, y, x, y + 1, x);
	}
}

int check_path(char *file)
{
	int y;
	int x;
	char **map;

	map = get_map(file);
	next_move(map, y, x);
	if (ft_tabchr(map, 'C') || ft_tabchr(map, 'E'))
	{
		free(map);
		return (ft_error("Unvalid path\n"));
	}
	free(map);
	return (1);
}