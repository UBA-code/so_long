/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:46:35 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/22 22:10:27 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void player_move(t_game game, int y_move, int x_move)
{
	int x;
	int y;

	y = 0;
	while (game.map[++y])
	{
		x = -1;
		while (game.map[y][++x])
		{
			if (game.map[y][x] == 'P')
			{
				if (game.map[++y - y_move - 1][x - x_move] != '1')
				{
					game.map[y - 1][x] = '0';
					game.map[y - y_move - 1][x - x_move] = 'P';
					mlx_clear_window(game.mlx, game.win);
					render_map(&game);
				}
				break;
			}
		}
	}
}
/*
void move_down(t_game game)
{
	int x;
	int y;

	y = -1;
	while (game.map[++y])
	{
		x = -1;
		while (game.map[y][++x])
		{
			if (game.map[y][x] == 'P')
			{
				if (game.map[++y][x] != '1')
				{
					game.map[y - 1][x] = '0';
					game.map[y][x] = 'P';
					mlx_clear_window(game.mlx, game.win);
					render_map(&game);
				}
				break;
			}
		}
	}
}

void move_left(t_game game)
{
	int x;
	int y;

	y = -1;
	while (game.map[++y])
	{
		x = -1;
		while (game.map[y][++x])
		{
			if (game.map[y][x] == 'P')
			{
				if (game.map[y][x - 1] != '1')
				{
					game.map[y][x] = '0';
					game.map[y][x - 1] = 'P';
					mlx_clear_window(game.mlx, game.win);
					render_map(&game);
				}
				break;
			}
		}
	}
}

void move_right(t_game game)
{
	int x;
	int y;

	y = -1;
	while (game.map[++y])
	{
		x = -1;
		while (game.map[y][++x])
		{
			if (game.map[y][x] == 'P')
			{
				if (game.map[y][x + 1] != '1')
				{
					game.map[y][x] = '0';
					game.map[y][x + 1] = 'P';
					mlx_clear_window(game.mlx, game.win);
					render_map(&game);
				}
				break;
			}
		}
	}
}
*/