/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargiac <amargiac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:41:34 by amargiac          #+#    #+#             */
/*   Updated: 2023/03/02 16:14:58 by amargiac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_imgs(t_game *imgs)
{
	imgs->backg = mlx_xpm_file_to_image(imgs->mlx, "./images/backg.xpm", &imgs->img_w, &imgs->img_h);
	imgs->player = mlx_xpm_file_to_image(imgs->mlx, "./images/player.xpm", &imgs->img_w, &imgs->img_h);
	imgs->collect = mlx_xpm_file_to_image(imgs->mlx, "./images/collect.xpm", &imgs->img_w, &imgs->img_h);
	imgs->exit = mlx_xpm_file_to_image(imgs->mlx, "./images/door1.xpm", &imgs->img_w, &imgs->img_h);
	imgs->enemy = mlx_xpm_file_to_image(imgs->mlx, "./images/enemy.xpm", &imgs->img_w, &imgs->img_h);
	imgs->wall = mlx_xpm_file_to_image(imgs->mlx, "./images/wall.xpm", &imgs->img_w, &imgs->img_h);
	return ;
}

void	render(t_game *imgs)
{
	int	i;
	int	j;


	i = 0;
	imgs->num_collect = 0;
	while (i < imgs->map_h)
	{
		j = 0;
		while (imgs->map[i][j])
		{
			img_selector(imgs, i, j);
			j++;
		}
		i++;
	}
}