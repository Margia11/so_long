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

int	rectangular(t_game *imgs)
{
	int	i;

	i = 1;
	if (ft_strlen(imgs->map[i]) != ft_strlen(imgs->map[0]))
	{
		return (0);
		i++;
	}
	return (1);
}

int	wall(t_game *imgs)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (imgs->map[i])
		i++;
	while (imgs->map[0][j] != '\0' && imgs->map[i - 1][j] != '\0')
	{
		if (imgs->map[0][j] != '1' || imgs->map[i - 1][j] != '1')
			return (0);
		j++;
	}
	i = 1;
	len = ft_strlen(imgs->map[i]);
	while (imgs->map[i])
	{
		if (imgs->map[i][0] != '1' || imgs->map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_validate(t_game *imgs)
{
	int	i;
	int	j;

	i = 0;
	while (imgs->map[i])
	{
		j = 0;
		while (imgs->map[i][j])
		{
			if (imgs->map[i][j] != 'P' && imgs->map[i][j] != 'E' && imgs->map[i][j] != 'C'
				&& imgs->map[i][j] != '0' && imgs->map[i][j] != '1' && imgs->map[i][j]!= 'N')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	block_control(t_game *imgs)
{
	int	i;
	int	j;

	i = 0;
	imgs->num_collect = 0;
	imgs->num_player = 0;
	imgs->num_exit = 0;
	while (imgs->map[i])
	{
		j = 0;
		while (imgs->map[i][j] != '\0')
		{
			if (imgs->map[i][j] == 'P')
				imgs->num_player++;
			if (imgs->map[i][j] == 'E')
				imgs->num_exit++;
			if (imgs->map[i][j] == 'C')
				imgs->num_collect++;
			j++;
		}
		i++;
	}
	if (imgs -> num_player != 1 || imgs -> num_exit == 0 || imgs -> num_collect == 0)
		return (0);
	return (1);
}

int	map_check(t_game *imgs)
{
	if ((rectangular(imgs) && wall(imgs) && is_validate(imgs) && (block_control(imgs))))
		return (1);
	return (0);
}
