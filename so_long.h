/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:46:28 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/25 13:37:57 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "mlx.h"
# include "fcntl.h"
# include "stdio.h"
# include "./1337_get_next_line/get_next_line.h"

#define FLOOR "./items/floor.xpm"
#define DOOR_CLOSE "./items/door.xpm"
#define DOOR_OPEN "./items/door_open.xpm"
#define DOOR DOOR_CLOSE
#define COIN "./items/coin.xpm"
#define PLAYER "./items/player.xpm"
#define WALL "./items/wall.xpm"


typedef struct s_game_main_utils
{
	void *mlx;
	void *win;
	int map_fd;
	char *line;
	int w;
	int h;
} t_game_main_utils;

typedef struct s_put_line_to_window_utils {
	int i;
	int width;
	int height;
	void *img;
	int y;

} t_put_line_to_window_utils;

typedef struct s_game
{
	void *mlx;
	void *win;
	void *img;
	char **map;
	char *exit;
} t_game;

void put_line_to_window(t_game *game, char *line, int *x);
char *ft_strdup(char *str);
int check_map(t_game game);
char **get_map(char *file);
void render_map(t_game *game);
void	ft_swap(char *a, char *b);
void player_move(t_game game, int y_move, int x_move);
void ft_putchar(char c);
void ft_putstr(char *str);
void	ft_putnbr(int n);
int check_file(char *str);
int check_end_line(char **map);
void	close_message(void);
int	invalid_message(void);
void	succes_message(void);
int	ft_error(char *txt);

int check_path(char *file);
void get_player_position(char **map, int *y, int *x);

#endif