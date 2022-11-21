/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:56:27 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/21 02:29:01 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char *ft_strdup(char *str)
{
	char *s;

	s = malloc(sizeof(char) * get_str_len(str));
	ft_strcpy(s, str);
	return (s);
}

void init_path_struct(t_elements *elements)
{
	elements->wall_path = "./items/wall.xpm";
	elements->player_path = "./items/player.xpm";
	elements->coin_path = "./items/coin.xpm";
	elements->exit_path = "./items/door.xpm";
	elements->floor_path = "./items/floor.xpm";
}