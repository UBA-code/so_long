/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line_to_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:00:14 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/21 16:32:43 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"



void check_and_put()
{
	
}

typedef struct s_put_line_to_window_utils {
	int i;
	int width;int height;
	void *img;
	int j;
	static int x;

} t_put_line_to_window_utils;


void put_line_to_window(void *mlx, void *win, char *line)
{
	t_elements elements;
	int i;
	int width;
	int height;
	void *img;
	int j;
	static int x;

	init_path_struct(&elements);
	i = -1;
	width = 0;
	j = 0;

	while (line[++i])
	{
		if (line[i] == '0')
		{
			img = mlx_xpm_file_to_image(mlx, elements.floor_path, &width, &height);
			mlx_put_image_to_window(mlx, win, img, j, x);
		}
		else if (line[i] == '1')
		{
			img = mlx_xpm_file_to_image(mlx, elements.wall_path, &width, &height);
			mlx_put_image_to_window(mlx, win, img, j, x);
		}
		else if (line[i] == 'C')
		{
			img = mlx_xpm_file_to_image(mlx, elements.coin_path, &width, &height);
			mlx_put_image_to_window(mlx, win, img, j, x);
		}
		else if (line[i] == 'E')
		{
			img = mlx_xpm_file_to_image(mlx, elements.exit_path, &width, &height);
			mlx_put_image_to_window(mlx, win, img, j, x);
		}
		else if (line[i] == 'P')
		{
			img = mlx_xpm_file_to_image(mlx, elements.player_path, &width, &height);
			mlx_put_image_to_window(mlx, win, img, j, x);
		}
		j += width;
	}
	x += height;
}