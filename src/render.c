/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:07:25 by nibenoit          #+#    #+#             */
/*   Updated: 2023/01/16 18:24:53 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_render_sprites(t_game *game, int i, int j)
{
	if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_grass, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_player_1, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_collectible, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_end, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_wall, IMG_SIZE * j, IMG_SIZE * i);
}

void	ft_render_img(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			ft_render_sprites(game, i, j);
	}
}
