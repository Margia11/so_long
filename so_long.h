/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargiac <amargiac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:47:35 by amargiac          #+#    #+#             */
/*   Updated: 2023/03/03 15:34:23 by amargiac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <stddef.h>
#include <string.h>
#include "./minilibx/mlx.h"
#include "./libft/libft.h"

# define KEY_ESC 53
# define KEY_Q 12
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*mlx_wind;
	char	**map;
	void	*img;
	char	*addr;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	void	*player;
	void	*exit;
	void	*collect;
	void	*backg;
	void	*enemy;
	void	*wall;
	int		num_player;
	int		num_exit;
	int		num_collect;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		loop;
}	t_game;

int			handle_keypress(int keycode, t_game *imgs);
char		**read_map(t_game *imgs, char **argv);
void		img_selector(t_game *imgs,int i, int j);
void		render(t_game *imgs);
void		img_selector2(t_game *imgs,int i, int j);
void		load_imgs(t_game *imgs);
size_t		ft_strlen(const char *s);
int			moveright(t_game *imgs);
int			moveleft(t_game *imgs);
int			moveup(t_game *imgs);
int			movedown(t_game *imgs);
int 		movecheck(t_game *imgs, int x_dest, int y_dest);
void		if_walls(t_game *imgs);
int			verticalwall(t_game *imgs);
int			horizontalwall(t_game *imgs);
void		character_valid(t_game *imgs);
void		check_errors(t_game *imgs);
void		count_checker(t_game *imgs, int width, int height);
int			exit_game(t_game *imgs);
#endif
