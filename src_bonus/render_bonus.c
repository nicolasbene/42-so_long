/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:07:25 by nibenoit          #+#    #+#             */
/*   Updated: 2023/01/23 10:28:19 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_choice_player(t_game *game, int i, int j, int key_code)
{
	if (key_code == KEY_W)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_centaur_up, IMG_SIZE * j, IMG_SIZE * i);
		return (1);
	}
	else if (key_code == KEY_S)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_centaur_down, IMG_SIZE * j, IMG_SIZE * i);
		return (1);
	}
	else if (key_code == KEY_A)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_centaur_left, IMG_SIZE * j, IMG_SIZE * i);
		return (1);
	}	
	else if (key_code == KEY_D)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_centaur_right, IMG_SIZE * j, IMG_SIZE * i);
		return (1);
	}
	return (0);
}

static void	ft_render_sprites(t_game *game, int i, int j, int key_code)
{
	if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_sand, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == 'P'
		&& ft_choice_player(game, i, j, key_code) == 1)
		return ;
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_player_1, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_wall, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_collectible, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_end, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == 'X' && (game->nb_move % 2 == 0))
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_fire, IMG_SIZE * j, IMG_SIZE * i);
	else if (game->map[i][j] == 'X' && (game->nb_move % 2 != 0))
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_fire2, IMG_SIZE * j, IMG_SIZE * i);
}

void	ft_render_img(t_game *game, int key_code)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			ft_render_sprites(game, i, j, key_code);
	}
}
