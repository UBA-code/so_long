/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:46:35 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/25 00:38:10 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int coins_search(t_game game)
{
	int y;
	int x;

	y = -1;
	while (game.map[++y])
	{
		x = -1;
		while (game.map[y][++x])
			if (game.map[y][x] == 'C')
				return (1);
	}
	y = -1;
	return (0);
}

void check_position(t_game game, int y_move, int x_move, int y, int x)
{
	static int i;
	if (!coins_search(game) && game.map[y - y_move][x - x_move] == 'E')
	{
		ft_putstr("number of moves is : ");
		ft_putnbr(++i);
		ft_putchar('\n');
		game.map[y][x] = '0';
		game.map[y - y_move][x - x_move] = 'P';
		mlx_clear_window(game.mlx, game.win);
		succes_message();
		render_map(&game);
		free(game.map);
		mlx_clear_window(game.mlx, game.win);
		exit(0);
	}
	else if (game.map[y - y_move][x - x_move] != '1' && game.map[y - y_move][x - x_move] != 'E')
	{
		ft_putstr("number of moves is : ");
		ft_putnbr(++i);
		ft_putchar('\n');
		game.map[y][x] = '0';
		game.map[y - y_move][x - x_move] = 'P';
		mlx_clear_window(game.mlx, game.win);
		render_map(&game);
	}
}

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
				check_position(game, y_move, x_move, y, x);
				return;
			}
		}
	}
}
