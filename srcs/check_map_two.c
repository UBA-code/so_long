/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:37:27 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/25 15:26:06 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int check_end_line(char **map)
{
	int y;
	int x;
	int width;

	y = 0;
	while (map[y][x] && map[y][x] != '\n')
		x++;
	width = x;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
			x++;
		if (x != width)
			return (0);
		y++;
	}
	return (1);
}

void get_player_position(char **map, int *y, int *x)
{
	int y_func;
	int x_func;

	y_func = 0;
	while (map[y_func])
	{
		x_func = 0;
		while (map[y_func][x_func])
		{
			if (map[y_func][x_func] == 'P')
			{
				*y = y_func;
				*x = x_func;
				return ;
			}
			x_func++;
		}
		y_func++;
	}
}
