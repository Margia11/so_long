/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargiac <amargiac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:39:05 by amargiac          #+#    #+#             */
/*   Updated: 2023/03/07 11:47:23 by amargiac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_game *imgs)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		exit_game(imgs);
  if (keycode == KEY_W || keycode == KEY_UP)
		moveup(imgs);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		moveleft(imgs);
  if (keycode == KEY_S || keycode == KEY_DOWN)
		movedown(imgs);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		moveright(imgs);
  print_moves(imgs);
  return (0);
}

int  movecheck(t_game *imgs, int x_dest, int y_dest)
{
    if (imgs->map[y_dest][x_dest] == '1')
		  return (0);
    else if (imgs->map[y_dest][x_dest] == 'N')
    {
       printf("YOU_LOST\n");
      return(exit_game(imgs));
    }
    else if (imgs->map[y_dest][x_dest] == 'E' && imgs->num_collect == 0)
    {
      printf("YOU_WON\n");
      return(exit_game(imgs));
    }
    else if (imgs->map[y_dest][x_dest] == 'E' && imgs->num_collect != 0)
      return (0);
    else if (imgs->map[y_dest][x_dest] == 'C')
      imgs->num_collect--;
    imgs->map[imgs->p_y][imgs->p_x] = '0';
	  imgs->p_x = x_dest;
	  imgs->p_y = y_dest;
    return (1);
}