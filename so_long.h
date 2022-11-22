/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:46:28 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/22 21:58:27 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "mlx.h"
# include "fcntl.h"
# include "stdio.h"
# include "./1337_get_next_line/get_next_line.h"




typedef struct s_elements
{
	char *player_path;
	char *wall_path;
	char *exit_path;
	char *coin_path;
	char *floor_path;

} t_elements;

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
} t_game;

void put_line_to_window(t_game *game, char *line, int *x);
char *ft_strdup(char *str);
void init_path_struct(t_elements *elements);
int check_map(char *file);
char **get_map(char *file);
void render_map(t_game *game);
void	ft_swap(char *a, char *b);
void player_move(t_game game, int y_move, int x_move);
// void move_up(t_game game);
// void move_down(t_game game);
// void move_left(t_game game);
// void move_right(t_game game);

#endif