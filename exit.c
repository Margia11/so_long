/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargiac <amargiac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:03:28 by amargiac          #+#    #+#             */
/*   Updated: 2023/03/03 15:16:08 by amargiac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *imgs)
{
	free(imgs->map);
	mlx_destroy_image(imgs->mlx, imgs->backg);
	mlx_destroy_image(imgs->mlx, imgs->wall);
	mlx_destroy_image(imgs->mlx, imgs->player);
	mlx_destroy_image(imgs->mlx, imgs->collect);
	mlx_destroy_image(imgs->mlx, imgs->exit);
	mlx_destroy_image(imgs->mlx, imgs->enemy);
	mlx_destroy_window(imgs->mlx, imgs->mlx_wind);
	exit(0);
	return (0);
}
