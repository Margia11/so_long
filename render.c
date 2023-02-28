/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:41:34 by amargiac          #+#    #+#             */
/*   Updated: 2023/02/27 19:56:02 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_dic	load_img(t_game *imgs, char *path)
{
	int		img_width;
	int		img_height;
	t_dic	var;

	var.img = mlx_xpm_file_to_image(imgs, path, &img_width, &img_height);
	var.addr = mlx_get_data_addr(var.img, &var.bpp,
			&var.line_len, &var.endian);
	return (var);
}

t_game load_imgs(t_game *imgs)
{
	t_game	images;

	images.backg = load_img(imgs,"/so_long/images/backg.xpm");
	images.player = load_img(imgs, "/so_long/images/player.xpm");
	images.collect = load_img(imgs, "/so_long/images/collect.xpm");
	images.exit = load_img(imgs, "/so_long/images/door1.xpm");
	images.enemy = load_img(imgs, "/so_long/images/enemy.xpm");
	images.wall = load_img(imgs, "/so_long/images/wall.xpm");
	return (images);
}

void	render(t_game *imgs)
{
	int	i;
	int	j;


	i = 0;
	imgs->num_collect = 0;
	while (imgs->map[i])
	{
		j = 0;
		while (imgs->map[i][j])
		{
			img_selector(imgs, i, j);
			j++;
		}
		i++;
	}
}



