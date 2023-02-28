/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargiac <amargiac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:23:05 by amargiac          #+#    #+#             */
/*   Updated: 2023/02/28 17:07:21 by amargiac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_game	*imgs;

	imgs = (t_game *)malloc(sizeof(t_game));
	read_map("./so_long/maps/mappa1.ber", imgs);
	if(map_check(imgs) == 0)
	{
		perror("invalid map");
		exit(0);
	imgs->mlx = mlx_init();
	}
	render(imgs);
	imgs->win = mlx_new_window(imgs->mlx, 640, 480, "DioCane");
	//imgs->img = mlx_xpm_file_to_image(imgs->mlx, "/so_long/maps/images/backg->xpm", &imgs->img_w, &imgs->img_h);
	//mlx_put_image_to_window(imgs->mlx, imgs->win, imgs, 0, 0);
	mlx_key_hook(imgs->win, movecheck, &imgs);
	mlx_hook(imgs->win, 2, 0, handle_keypress, &imgs);
	mlx_hook(imgs->win, 17, 0, handle_close_window, &imgs);
	mlx_loop(imgs->mlx);
}
