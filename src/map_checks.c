/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:22:22 by nibenoit          #+#    #+#             */
/*   Updated: 2023/01/17 18:26:33 by nibenoit         ###   ########.fr       */
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

int	ft_check_rectangle(t_game *game)
{
	int	i;
	int	len_line;

	i = 0;
	while (game->map[i])
	{
		len_line = ft_strlen(game->map[i]);
		if (i != 0 && game->map_width != len_line)
			return (ERROR_MAP_SIZE);
		game->map_width = len_line;
		i++;
	}
	return (SUCCESS);
}

int	ft_check_wall(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		if (i == 0 || i == game->map_height)
		{
			j = -1;
			while (game->map[i][++j])
			{
				if (game->map[i][j] != '1')
					return (ERROR_WALL);
			}
		}
		else
		{
			if (game->map[i][0] != '1')
				return (ERROR_WALL);
			if (game->map[i][game->map_width - 1] != '1')
				return (ERROR_WALL);
		}
	}
	return (SUCCESS);
}
