/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargiac <amargiac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:12:27 by amargiac          #+#    #+#             */
/*   Updated: 2023/03/07 16:24:04 by amargiac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_errors(t_game *imgs)
{
	if (if_walls(imgs)== 0 && character_valid(imgs) == 0)
		return(0);
	return(1);
}