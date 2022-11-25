/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:24:25 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/25 21:26:04 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void render_map(t_game *game)
{
	int y;
	int x;

	y = 0;
	x = 32;
	while (game->map[y])
	{
		put_line_to_window(game, game->map[y], &x);
		y++;
	}
}