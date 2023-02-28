/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargiac <amargiac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:03:28 by amargiac          #+#    #+#             */
/*   Updated: 2023/02/28 11:18:56 by amargiac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_game *imgs)
{
	if (keycode == 53)
	{
		mlx_destroy_window(imgs->mlx, imgs->win);
		exit(0);
	}
	return (0);
}

int	handle_close_window(t_game *imgs)
{
	mlx_destroy_window(imgs->mlx, imgs->win);
	exit(0);
	return (0);
}
