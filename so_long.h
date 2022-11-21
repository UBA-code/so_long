/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:46:28 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/21 18:34:58 by ybel-hac         ###   ########.fr       */
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

void put_line_to_window(void *mlx, void *win, char *line);
char *ft_strdup(char *str);
void init_path_struct(t_elements *elements);
int check_map(char *file);

#endif