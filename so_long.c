/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargiac <amargiac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:23:05 by amargiac          #+#    #+#             */
/*   Updated: 2023/03/10 12:10:57 by amargiac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	argv_check(char **argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[1][i])
		i++;
	i -= 1;
	if (argv[1][i] != 'r' && argv[1][i - 1] != 'e'
		&& argv[1][i - 2] != 'b' && argv[1][i - 3] != '.')
	{
		ft_putstr("argvInvalid");
		exit(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	imgs;

	if (argc != 2)
	{
		write(1, "argcInvalid\n", 15);
		return (0);
	}
	argv_check(argv);
	imgs.mlx = mlx_init(imgs.mlx);
	imgs.move_counter = 0;
	read_map(&imgs, argv);
	check_errors(&imgs);
	imgs.mlx_wind = mlx_new_window(imgs.mlx, imgs.map_w * 64, \
	imgs.map_h * 64, "so_long");
	load_imgs(&imgs);
	render(&imgs);
	mlx_hook(imgs.mlx_wind, 2, 1L << 0, handle_keypress, &imgs);
	mlx_hook(imgs.mlx_wind, 17, 0, exit_game, &imgs);
	mlx_loop_hook(imgs.mlx, print_frame, &imgs);
	mlx_loop(imgs.mlx);
	return (0);
}
