/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:55:20 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/22 03:28:35 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int get_lines_len(char *file)
{
	int fd = open(file, O_RDONLY);
	int i;
	char *line;

	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (i);
}

char **get_map(char *file)
{
	int fd;
	char **map;
	char *line;
	int i;

	map = malloc(sizeof(char *) * get_lines_len(file) + 1);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map[i] = malloc(sizeof(char) * get_str_len(line));
		ft_strcpy(map[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	free(line);
	map[i] = 0;
	return (map);
}