/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_symbols_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:11:06 by acerdan           #+#    #+#             */
/*   Updated: 2023/01/23 10:27:59 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_return(t_game *game)
{
	if (game->player != 1 || game->end != 1 || game->collectible < 1)
		return (ERROR_INVALID_SYMBOLS);
	return (SUCCESS);
}

static void	ft_fill_struct(t_game *game, int i, int j)
{
	game->player_pos_x = i;
	game->player_pos_y = j;
	game->player++;
}

int	ft_check_symbols(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
				ft_fill_struct(game, i, j);
			else if (game->map[i][j] == 'E')
				game->end++;
			else if (game->map[i][j] == 'C')
				game->collectible++;
		}
	}
	return (ft_return(game));
}
