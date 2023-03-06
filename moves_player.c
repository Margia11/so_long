/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:50:28 by amargiac          #+#    #+#             */
/*   Updated: 2023/03/06 15:57:54 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int moveright(t_game *imgs)
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
    printf("%d\n", imgs->move_counter);
  }
  return (1);
}

int moveleft(t_game *imgs)
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
    printf("%d\n", imgs->move_counter);
  }
  return (1);
}

int moveup(t_game *imgs)
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
    printf("%d\n", imgs->move_counter);
  }
  return (1);
}

int movedown(t_game *imgs)
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
    printf("%d\n", imgs->move_counter);
  }
  return (1);
}

void  n_moves(t_game *imgs)
{
  char  *str;

  str = ft_itoa(imgs->move_counter);
  mlx_string_put(imgs->mlx, imgs->win, 25, 20, 16777215, "Moves: ");
	mlx_string_put(imgs->mlx, imgs->win, 125, 20, 16777215, str);
	free(str);
}
