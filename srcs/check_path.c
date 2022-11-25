#include "../so_long.h"

void set_player(char **map, t_utils utils, int old_y, int old_x)
{
	map[utils.y][utils.x] = 'P';
	map[old_y][old_x] = 'x';
}

void set_postion(char **map, int y, int x, t_utils utils)
{
	map[utils.old_y][utils.old_x] = 'x';
	map[y][x] = 'P';
}

int check_move(char **map, int y, int x)
{
	if (!ft_tabchr(map, 'C'))
	{
		if (map[y] && map[y][x] != 'x' && map[y][x] != '1')
			return (1);
	}
	else
	{
		if (map[y] && map[y][x] != 'x' && map[y][x] != '1' && map[y][x] != 'E')
			return (1);
	}
	return (0);
}

void next_move(char **map, t_utils utils)
{
	get_player_position(map, &utils, 'P');
	if (check_move(map, utils.y , utils.x + 1))
	{
		set_postion(map, utils.y, utils.x + 1, utils);
		next_move(map, utils);
		set_player(map, utils, utils.y, utils.x + 1);
	}
	if (check_move(map, utils.y , utils.x - 1))
	{
		set_postion(map, utils.y, utils.x - 1, utils);
		next_move(map, utils);
		set_player(map, utils, utils.y, utils.x - 1);
	}
	if (check_move(map, utils.y - 1, utils.x))
	{
		set_postion(map, utils.y - 1, utils.x, utils);
		next_move(map, utils);
		set_player(map, utils, utils.y - 1, utils.x);
	}
	if (check_move(map, utils.y + 1, utils.x))
	{
		set_postion(map, utils.y + 1, utils.x, utils);
		next_move(map, utils);
		set_player(map, utils, utils.y + 1, utils.x);
	}
}

int check_path(char *file)
{
	t_utils	utils;
	char	**map;

	map = get_map(file);
	next_move(map, utils);
	get_player_position(map, &utils, 'E');
		
	if (ft_tabchr(map, 'E') || ft_tabchr(map, 'C'))
	{
		if (!(map[utils.y][utils.x - 1] == 'x' || map[utils.y][utils.x + 1] == 'x'
			|| map[utils.y + 1][utils.x] == 'x' || map[utils.y - 1][utils.x] == 'x'))
			{
			free(map);
			return (ft_error("Unvalid path\n"));
			}
	}
	free(map);
	return (1);
}
