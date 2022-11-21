/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:54:41 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/21 22:35:30 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int check_rectangular(char *file)
{
	int fd;
	fd = open(file, O_RDONLY);
	char *line;
	int w;
	int h;

	line = get_next_line(fd);
	w = get_str_len(line);
	h = 0;
	while (line)
	{
		h++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	if (w <= h)
		return (0);
	else
		return (1);
}

int check_elements(char *file)
{
	char *line;
	int i;
	int fd;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		i = -1;
		while (line[++i])
		{
			if (line[i] != '0' && line[i] != '1' && line[i] != 'P'
				&& line[i] != 'C' && line[i] != 'E' && line[i] != '\n')
			{
				free(line);
				close(fd);
				return (0);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int check_valid_end(char *file)
{
	int fd;
	int w;
	int w_temp;
	char *line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	w = get_str_len(line);
	w_temp = w;
	while (line)
	{
		if (w_temp != w)
		{
			close(fd);
			free(line);
			return (0);
		}
		w_temp = w;
		free(line);
		line = get_next_line(fd);
		w = get_str_len(line);
		if (line && line[w - 1] != '\n')
			w++;
	}
	close(fd);
	free(line);
	return (1);
}

int check_map(char *file)
{
	int width;
	int height;
	char *line;

	if (check_rectangular(file) && check_elements(file) && check_valid_end(file))
		return (1);
	else
		return (0);
}