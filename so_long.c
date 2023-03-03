/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargiac <amargiac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:23:05 by amargiac          #+#    #+#             */
/*   Updated: 2023/03/03 15:14:08 by amargiac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	imgs;
	
	if (argc != 2)
	{
		return (0);
	}
	ft_memset(&imgs, 0, sizeof(t_game));
	read_map(&imgs, argv);
	check_errors(&imgs);
	imgs.mlx = mlx_init(imgs.mlx);
	imgs.mlx_wind = mlx_new_window(imgs.mlx, imgs.map_w * 64, imgs.map_h * 64, "so_long");
	load_imgs(&imgs);
	render(&imgs);
	mlx_hook(imgs.mlx_wind, 2, 1L << 0, handle_keypress, &imgs);
	mlx_hook(imgs.mlx_wind, 17, 0, exit_game, &imgs);
	mlx_loop(imgs.mlx);
	return (0);
}
