/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargiac <amargiac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:50:28 by amargiac          #+#    #+#             */
/*   Updated: 2023/03/01 16:30:26 by amargiac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int movecheck(t_game *imgs)
{
    if (getchar() == 'w' && imgs->map[imgs->p_y + 1][imgs->p_x] != '1')
      moveup(imgs);
    else if (getchar() == 'a' && imgs->map[imgs->p_y][imgs->p_x - 1] != '1')
      moveleft(imgs);
    else if (getchar() == 's' && imgs->map[imgs->p_y - 1][imgs->p_x] != '1')
      movedown(imgs);
    else if (getchar() == 'd' && imgs->map[imgs->p_y ][imgs->p_x + 1] != '1')
      moveright(imgs);
    else if (imgs->map[imgs->p_x][imgs->p_y] == 'N')
    {
      return(handle_close_window(imgs));
      write(1, "YOU_LOST", 10);
    }
    else if (imgs->map[imgs->p_x][imgs->p_y] == 'E' && imgs->num_collect == '0')
    {
      return(handle_close_window(imgs));
      write(1, "YOU_WON", 9);
    }
    else if (imgs->map[imgs->p_x][imgs->p_y] == 'C')
      imgs->num_collect--;
    return (1);
}

int moveright(t_game *imgs)
{
    mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind,
		  imgs->backg, imgs->p_x * 64, imgs->p_y * 64);
    imgs->p_x++;
    mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind,
		  imgs->player, imgs->p_x * 64, imgs->p_y * 64);    
  return (1); 
}

int moveleft(t_game *imgs)
{
    mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind,
		  imgs->backg, imgs->p_x * 64, imgs->p_y * 64);
    imgs->p_x--;
    mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind,
		  imgs->player, imgs->p_x * 64, imgs->p_y * 64);    
  return (1); 
}

int moveup(t_game *imgs)
{
    mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind,
		  imgs->backg, imgs->p_x * 64, imgs->p_y * 64);
    imgs->p_y++;
    mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind,
		  imgs->player, imgs->p_x * 64, imgs->p_y * 64);    
  return (1); 
}

int movedown(t_game *imgs)
{
    mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind,
		  imgs->backg, imgs->p_x * 64, imgs->p_y * 64);
    imgs->p_y--;
    mlx_put_image_to_window(imgs->mlx, imgs->mlx_wind,
		  imgs->player, imgs->p_x * 64, imgs->p_y * 64);    
  return (1); 
}