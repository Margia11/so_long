/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargiac <amargiac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:32:06 by amargiac          #+#    #+#             */
/*   Updated: 2023/03/07 14:58:35 by amargiac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	put_image(char *s, t_game *imgs)
// {
// 	imgs->enemy = mlx_xpm_file_to_image(imgs->mlx,
// 			s, &imgs->img_w, &imgs->img_h);
// }

// int animation(t_game *imgs)
// {
//     if (imgs->loop < 1000)
//     {
//     imgs->loop++;
//     return(0);
//     }
//     imgs->loop = 0;
// 	mlx_destroy_image(imgs->mlx, imgs->enemy);
// 	if (imgs->p_enemy == 1)
// 		put_image("images/enemy.xpm", imgs);
// 	else if (imgs->p_enemy == 2)
// 		put_image("images/enemy1.xpm", imgs);
//     imgs->p_enemy++;
// 	return(0);
// }