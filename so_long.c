/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargiac <amargiac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:23:05 by amargiac          #+#    #+#             */
/*   Updated: 2023/03/01 18:05:34 by amargiac         ###   ########.fr       */
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
	imgs.win = mlx_new_window(imgs.mlx, 1920, 1080, "DioCane");
	load_imgs(&imgs);
	render(&imgs);
	printf("arriivato\n");
	mlx_key_hook(imgs.win, movecheck, &imgs);
	mlx_hook(imgs.win, 2, 0, handle_keypress, &imgs);
	mlx_hook(imgs.win, 17, 0, handle_close_window, &imgs);
	mlx_loop(imgs.mlx);
	return (0);
}
