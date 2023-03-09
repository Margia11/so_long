/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs_selector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargiac <amargiac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:23:19 by amargiac          #+#    #+#             */
/*   Updated: 2023/03/09 11:26:01 by amargiac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_selector(t_game *imgs, int i, int j)
{
	if (imgs->map[i][j] == '1')
	{
		mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind, imgs->wall, \
		j * 64, i * 64);
	}
	if (imgs->map[i][j] == '0')
	{
		mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind, imgs->backg, \
		j * 64, i * 64);
	}
	else if (imgs->map[i][j] == 'P')
	{
		mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind, imgs->player, \
		j * 64, i * 64);
		imgs->p_x = j;
		imgs->p_y = i;
	}
	else
	{
		img_selector2(imgs, i, j);
	}
}

void	img_selector2(t_game *imgs, int i, int j)
{
	if (imgs->map[i][j] == 'E')
	{
		mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind, imgs->exit, \
		j * 64, i * 64);
		imgs->e_x = j;
		imgs->e_y = i;
	}
	if (imgs->map[i][j] == 'N')
	{
		mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind, imgs->enemy, \
		j * 64, i * 64);
	}
	else if (imgs->map[i][j] == 'C')
	{
		imgs->num_collect++;
		mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind, imgs->backg, \
		j * 64, i * 64);
		mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind, imgs->collect, \
		j * 64, i * 64);
	}
}
