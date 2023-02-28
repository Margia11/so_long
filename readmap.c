/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamargiacchi <andreamargiacchi@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:01:27 by amargiac          #+#    #+#             */
/*   Updated: 2023/02/27 19:57:19 by andreamargi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *path, t_game *imgs)
{
	int		fd;
	char 	*line;
	char	*s1;

	s1 = "";
	fd = open(path, O_RDONLY);
	if (fd <= 0)
		return ;
	while (1)
	{
		line = get_next_line(fd);
			if (!line)
				return ;
		s1 = ft_strjoin(s1, line);
	}
	imgs->map = ft_split(s1, '\n');
	close (fd);
}
