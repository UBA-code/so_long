/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line_to_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:00:14 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/21 16:52:20 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"



void check_and_put(void *mlx, void *win, char *path, t_put_line_to_window_utils *utils, int x)
{
	(*utils).img = mlx_xpm_file_to_image(mlx, path, &(*utils).width, &(*utils).height);
	mlx_put_image_to_window(mlx, win, (*utils).img, (*utils).y, x);
}

void put_line_to_window(void *mlx, void *win, char *line)
{
	t_elements elements;
	t_put_line_to_window_utils utils;
	static int x;

	init_path_struct(&elements);
	utils.i = -1;
	utils.width = 0;
	utils.y = 0;

	while (line[++utils.i])
	{
		if (line[utils.i] == '0')
			check_and_put(mlx, win, elements.floor_path, &utils, x);
		else if (line[utils.i] == '1')
			check_and_put(mlx, win, elements.wall_path, &utils, x);
		else if (line[utils.i] == 'C')
			check_and_put(mlx, win, elements.coin_path, &utils, x);
		else if (line[utils.i] == 'E')
			check_and_put(mlx, win, elements.exit_path, &utils, x);
		else if (line[utils.i] == 'P')
			check_and_put(mlx, win, elements.player_path, &utils, x);
		utils.y += utils.width;
	}
	x += utils.height;
}