/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line_to_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:00:14 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/22 17:03:10 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"



void check_and_put(t_game *game, char *path, t_put_line_to_window_utils *utils, int x)
{
	(*utils).img = mlx_xpm_file_to_image(game->mlx, path, &(*utils).width, &(*utils).height);
	game->img = (*utils).img;
	mlx_put_image_to_window(game->mlx, game->win, (*utils).img, (*utils).y, x);
	mlx_destroy_image(game->mlx, (*utils).img);
}

void put_line_to_window(t_game *game, char *line, int *x)
{
	t_elements elements;
	t_put_line_to_window_utils utils;

	init_path_struct(&elements);
	utils.i = -1;
	utils.width = 0;
	utils.y = 0;
	while (line[++utils.i])
	{
		if (line[utils.i] == '0')
			check_and_put(game, elements.floor_path, &utils, *x);
		else if (line[utils.i] == '1')
			check_and_put(game, elements.wall_path, &utils, *x);
		else if (line[utils.i] == 'C')
			check_and_put(game, elements.coin_path, &utils, *x);
		else if (line[utils.i] == 'E')
			check_and_put(game, elements.exit_path, &utils, *x);
		else if (line[utils.i] == 'P')
			check_and_put(game, elements.player_path, &utils, *x);
		utils.y += utils.width;
	}
	*x += utils.height;
}