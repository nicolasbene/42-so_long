/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:07:25 by nibenoit          #+#    #+#             */
/*   Updated: 2023/01/18 19:48:45 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_render_static(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			mlx_put_image_to_window(game->mlx, game->window,
				game->sprite_grass, IMG_SIZE * j, IMG_SIZE * i);
			j++;
		}
		i++;
	}
	return (0);
}

static void	ft_render_sprites(t_game *game, int i, int j)
{
	if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_grass, IMG_SIZE * j, IMG_SIZE * i);
	else if ((game->map[i][j] == 'P') && (game->nb_move % 2 == 0))
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_player_1, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == 'P' && (game->nb_move % 2 != 0))
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_player_2, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_wall, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_collectible, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_end, IMG_SIZE * j, IMG_SIZE * i);

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
