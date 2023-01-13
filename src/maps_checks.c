/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:22:22 by nibenoit          #+#    #+#             */
/*   Updated: 2023/01/13 10:23:39 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_extension(t_game *game)
{
	int	len;

	len = ft_strlen(game->filename);
	if (len > 4)
	{
		if (game->filename[len - 1] == 'r' && game->filename[len - 2] == 'e'
			&& game->filename[len - 3] == 'b' && game->filename[len - 4] == '.')
			return (SUCCESS);
	}
	return (ERROR);
}