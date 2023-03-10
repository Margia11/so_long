/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargiac <amargiac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:50:28 by amargiac          #+#    #+#             */
/*   Updated: 2023/03/10 14:34:27 by amargiac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moveright(t_game *imgs)
{
	if (movecheck(imgs, (imgs->p_x + 1), imgs->p_y))
	{
		mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind,
			imgs->backg, imgs->p_x * 64, imgs->p_y * 64);
		mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind,
			imgs->player, imgs->p_x * 64, imgs->p_y * 64);
		mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind,
			imgs->backg, (imgs->p_x - 1) * 64, imgs->p_y * 64);
		imgs->move_counter++;
	}
	return (1);
}

int	moveleft(t_game *imgs)
{
	if (movecheck(imgs, (imgs->p_x - 1), imgs->p_y))
	{
		mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind,
			imgs->backg, imgs->p_x * 64, imgs->p_y * 64);
		mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind,
			imgs->player, imgs->p_x * 64, imgs->p_y * 64);
		mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind,
			imgs->backg, (imgs->p_x + 1) * 64, imgs->p_y * 64);
		imgs->move_counter++;
	}
	return (1);
}

int	moveup(t_game *imgs)
{
	if (movecheck(imgs, imgs->p_x, (imgs->p_y - 1)))
	{
		mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind,
			imgs->backg, imgs->p_x * 64, imgs->p_y * 64);
		mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind,
			imgs->player, imgs->p_x * 64, imgs->p_y * 64);
		mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind,
			imgs->backg, imgs->p_x * 64, (imgs->p_y + 1) * 64);
		imgs->move_counter++;
	}
	return (1);
}

int	movedown(t_game *imgs)
{
	if (movecheck(imgs, imgs->p_x, (imgs->p_y + 1)))
	{
		mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind,
			imgs->backg, imgs->p_x * 64, imgs->p_y * 64);
		mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind,
			imgs->player, imgs->p_x * 64, imgs->p_y * 64);
		mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind,
			imgs->backg, imgs->p_x * 64, (imgs->p_y - 1) * 64);
		imgs->move_counter++;
	}
	return (1);
}

void	print_moves(t_game *imgs)
{
	char	*s;

	s = ft_itoa(imgs->move_counter);
	img_selector(imgs, 0, 1);
	img_selector(imgs, 0, 0);
	mlx_string_put(imgs->mlx, imgs->mlx_wind, 10, 15, 0xFF0000, "MOVES: ");
	mlx_string_put(imgs->mlx, imgs->mlx_wind, 80, 15, 0xFF0000, s);
	if (imgs->counter != imgs->move_counter)
	{
		ft_putstr("MOVES: ");
		ft_putstr(s);
		ft_putstr("\n");
	}
	free(s);
}
