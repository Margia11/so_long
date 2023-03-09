/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargiac <amargiac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:32:06 by amargiac          #+#    #+#             */
/*   Updated: 2023/03/09 17:08:53 by amargiac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	frame(t_game *imgs)
{
	if (imgs->enemy_frame == 1)
		imgs->enemy = build_img(imgs->mlx, "./images/enemy.xpm");
	if (imgs->enemy_frame == 10)
		imgs->enemy = build_img(imgs->mlx, "./images/enemy1.xpm");
	if (imgs->enemy_frame == 100)
		imgs->enemy_frame = 1;
}

int	print_frame(t_game *imgs)
{
	int	i;
	int	j;

	i = -1;
	imgs->enemy_frame++;
	imgs->y = 0;
	while (imgs->map[++i])
	{
		j = 0;
		imgs->x = 0;
		while (imgs->map[i][j++])
		{
			if (imgs->map[i][j] == 'N')
			{
				mlx_destroy_image(imgs->mlx, imgs->enemy);
				mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind, imgs->enemy1, \
				j * 64, i * 64);
			}
			imgs->x += 64;
		}
		imgs->y += 64;
	}
	frame(imgs);
	return(0);
}

