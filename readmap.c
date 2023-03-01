/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargiac <amargiac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:01:27 by amargiac          #+#    #+#             */
/*   Updated: 2023/03/01 16:36:36 by amargiac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(t_game *imgs, char **argv)
{
	int		fd;
	char 	*line;
	
	line = malloc(sizeof(char) *10000000);
	fd = open(argv[1], O_RDONLY);
	read(fd, line, 10000000);
	imgs->map = ft_split(line, '\n');
	return(imgs->map);
}
