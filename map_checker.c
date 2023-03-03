/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs->map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargiac <amargiac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:51:39 by amargiac          #+#    #+#             */
/*   Updated: 2023/02/23 15:35:55 by amargiac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	horizontalwall(t_game *imgs)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (imgs->map[i])
		i++;
	while (imgs->map[0][j])
	{
		if (imgs->map[0][j] != '1' && imgs->map[i - 1][j] != '1')
		{
			return (0);
		}
		j++;
	}
	imgs->map_w = j;
	return (1);
}

int	verticalwall(t_game *imgs)
{
	int	height;
	int	width;

	height = 0;
	width = 0;

	while (imgs->map[width][height])
		height++;
	while (imgs->map[width])
	{
		if (imgs->map[width][0] != '1' && imgs->map[width][height - 1] != '1')
		{
			return (0);
		}
		width++;
	}
	imgs->map_h = width;
	return (1);
}

void	if_walls(t_game *imgs)
{
	int	verticalwalls;
	int	horizontalwalls;

	verticalwalls = verticalwall(imgs);
	horizontalwalls = horizontalwall(imgs);
	if (!verticalwalls || !horizontalwalls)
	{
		write(1,"WallsMapInvalid\n", 19);
		exit_game(imgs);
	}
}

void	count_checker(t_game *imgs, int width, int height)
{
	
	if (imgs->map[width][height] != '1' &&
		imgs->map[width][height] != '0' &&
		imgs->map[width][height] != 'P' &&
		imgs->map[width][height] != 'E' &&
		imgs->map[width][height] != 'C' &&
		imgs->map[width][height] != 'N' &&
		imgs->map[width][height] != '\n')
	{
		write(1, "ErrorElements\n", 17);
		exit_game(imgs);
	}
	if (imgs->map[width][height] == 'C')
			imgs->num_collect++;
	if (imgs->map[width][height] == 'P')
			imgs->num_player++;
	if (imgs->map[width][height] == 'E')
			imgs->num_exit++;
}

void	character_valid(t_game *imgs)
{
	int	height;
	int	width;
	width = 0;
	while (imgs->map[width])
	{
		height = 0;
		while (imgs->map[width][height])
		{
			count_checker(imgs, width, height);
			height++;
		}
		width++;
	}
	if ((imgs->num_player != 1 || imgs->num_collect == 0
			|| imgs->num_exit != 1))
	{
		write(1, "InvalidElements\n", 19);
		exit_game(imgs);
	}
}

void	check_errors(t_game *imgs)
{
	if_walls(imgs);
	character_valid(imgs);
}