/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_xpm_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:05:45 by nibenoit          #+#    #+#             */
/*   Updated: 2023/01/23 10:28:14 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_extra_sprites(t_game *game)
{
	game->sprite_centaur_down = mlx_xpm_file_to_image(game->mlx,
			"xpm/centaur_down.xpm", &game->img_size, &game->img_size);
	game->sprite_centaur_up = mlx_xpm_file_to_image(game->mlx,
			"xpm/centaur_up.xpm", &game->img_size, &game->img_size);
	game->sprite_centaur_left = mlx_xpm_file_to_image(game->mlx,
			"xpm/centaur_left.xpm", &game->img_size, &game->img_size);
	game->sprite_centaur_right = mlx_xpm_file_to_image(game->mlx,
			"xpm/centaur_right.xpm", &game->img_size, &game->img_size);
	if (!game->sprite_centaur_down || !game->sprite_centaur_up
		|| !game->sprite_centaur_left
		|| !game->sprite_centaur_right)
		ft_exit(game, ERROR_OPEN);
	return (SUCCESS);
}

int	ft_parse_xpm(t_game *game)
{
	game->img_size = IMG_SIZE;
	game->win_height = game->img_size * game->map_height;
	game->win_width = game->img_size * game->map_width;
	game->window = mlx_new_window(game->mlx, game->win_width,
			game->win_height, "so_long");
	game->sprite_end = mlx_xpm_file_to_image(game->mlx,
			"xpm/star.xpm", &game->img_size, &game->img_size);
	game->sprite_player_1 = mlx_xpm_file_to_image(game->mlx,
			"xpm/centaur_down.xpm", &game->img_size, &game->img_size);
	game->sprite_collectible = mlx_xpm_file_to_image(game->mlx,
			"xpm/ramen.xpm", &game->img_size, &game->img_size);
	game->sprite_wall = mlx_xpm_file_to_image(game->mlx,
			"xpm/tree.xpm", &game->img_size, &game->img_size);
	game->sprite_sand = mlx_xpm_file_to_image(game->mlx,
			"xpm/sable.xpm", &game->img_size, &game->img_size);
	game->sprite_fire = mlx_xpm_file_to_image(game->mlx,
			"xpm/fire.xpm", &game->img_size, &game->img_size);
	game->sprite_fire2 = mlx_xpm_file_to_image(game->mlx,
			"xpm/fire2.xpm", &game->img_size, &game->img_size);
	ft_extra_sprites(game);
	if (!game->sprite_end || !game->sprite_sand || !game->sprite_player_1
		|| !game->sprite_collectible || !game->sprite_wall
		|| !game->sprite_fire || !game->sprite_fire2)
		ft_exit(game, ERROR_OPEN);
	return (SUCCESS);
}
