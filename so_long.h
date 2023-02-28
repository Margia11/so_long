/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargiac <amargiac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:47:35 by amargiac          #+#    #+#             */
/*   Updated: 2023/02/28 16:50:57 by amargiac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <stddef.h>
#include <string.h>
#include "./minilibx/mlx.h"
#include "./libft/libft.h"
#include "./get_next_line.h"

typedef struct s_dic {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_dic;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*mlx_wind;
	char	**map;
	void	*img;
	char	*addr;
	int		line_len;
	int		endian;
	int 	bpp;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	t_dic	player;
	t_dic	exit;
	t_dic	collect;
	t_dic	backg;
	t_dic	enemy;
	t_dic	wall;
	int		num_player;
	int		num_exit;
	int		num_collect;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		loop;
}	t_game;


int			handle_close_window(t_game *imgs);
int			handle_keypress(int keycode, t_game *imgs);
void		read_map(char *path, t_game *imgs);
int			rectangular(t_game *imgs);
int			wall(t_game *imgs);
int			is_validate(t_game *imgs);
int			block_control(t_game *imgs);
int			map_check(t_game *imgs);
void		img_selector(t_game *imgs,int i, int j);
void		render(t_game *imgs);
void		img_selector2(t_game *imgs,int i, int j);
t_dic		load_img(t_game *imgs, char *path);
t_game		load_imgs(t_game *imgs);
size_t		ft_strlen(const char *s);
int 		moveright(t_game *imgs);
int 		moveleft(t_game *imgs);
int 		moveup(t_game *imgs);
int			movedown(t_game *imgs);
int 		movecheck(t_game *imgs);

#endif
