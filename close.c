/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargiac <amargiac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:03:28 by amargiac          #+#    #+#             */
/*   Updated: 2023/03/01 11:27:16 by amargiac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_game *imgs)
{
	if (keycode == 53)
	{
		mlx_destroy_window(imgs->mlx, imgs->win);
		free(imgs);
		exit(0);
	}
	free(imgs);
	return (0);
}

int	handle_close_window(t_game *imgs)
{
	mlx_destroy_window(imgs->mlx, imgs->win);
	free(imgs);
	exit(0);
	return (0);
}
