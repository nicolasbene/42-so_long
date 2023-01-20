/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:38:43 by nibenoit          #+#    #+#             */
/*   Updated: 2023/01/20 11:43:44 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_game *game)
{
	int	i;

	i = -1;
	if (game->map)
	{
		while (++i < game->map_height)
		{
			free(game->map[i]);
		}
		free(game->map);
	}
}

void	ft_print_error(int err)
{
	if (err == ERROR_MALLOC)
		ft_putstr_fd("Error\nMALLOC_FAILED\n", 2);
	else if (err == ERROR_MLX)
		ft_putstr_fd("Error\nMLX_FAILED\n", 2);
	else if (err == ERROR_OPEN)
		ft_putstr_fd("Error\nOPEN_FAILED\n", 2);
	else if (err == ERROR_INVALID_MAP)
		ft_putstr_fd("Error\nINVALID_MAP\n", 2);
	else if (err == ERROR_WALL)
		ft_putstr_fd("Error\nINVALID_WALL\n", 2);
	else if (err == ERROR_INVALID_MAP_PARAMS)
		ft_putstr_fd("Error\nINVALID_MAP_PARAMS\n", 2);
	else if (err == ERROR_MAP_SIZE)
		ft_putstr_fd("Error\nINVALID_MAP_SIZE\n", 2);
	else if (err == ERROR_INVALID_SYMBOLS)
		ft_putstr_fd("Error\nERROR_INVALID_SYMBOLS\n", 2);
	else if (err == ERROR_USAGE)
		ft_putstr_fd("Error\nusage: ./so_long map.ber\n", 2);
	else if (err == ERROR_PATH)
		ft_putstr_fd("Error\nINVALID_PATH\n", 2);
	else
		return ;
}

static void	ft_clean_sprite(t_game *game)
{
	if (game->sprite_sand)
		mlx_destroy_image(game->mlx, game->sprite_sand);
	if (game->sprite_end)
		mlx_destroy_image(game->mlx, game->sprite_end);
	if (game->sprite_wall)
		mlx_destroy_image(game->mlx, game->sprite_wall);
	if (game->sprite_collectible)
		mlx_destroy_image(game->mlx, game->sprite_collectible);
	if (game->sprite_player_1)
		mlx_destroy_image(game->mlx, game->sprite_player_1);
	if (game->sprite_fire)
		mlx_destroy_image(game->mlx, game->sprite_fire);
	if (game->sprite_centaur_down)
		mlx_destroy_image(game->mlx, game->sprite_centaur_down);
	if (game->sprite_centaur_up)
		mlx_destroy_image(game->mlx, game->sprite_centaur_up);
	if (game->sprite_centaur_left)
		mlx_destroy_image(game->mlx, game->sprite_centaur_left);
	if (game->sprite_centaur_right)
		mlx_destroy_image(game->mlx, game->sprite_centaur_right);
}

void	ft_exit(t_game *game, int err)
{
	ft_print_error(err);
	if (game)
	{
		if (game->map)
			ft_free_map(game);
		ft_clean_sprite(game);
		if (game->window)
			mlx_destroy_window(game->mlx, game->window);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		free(game);
	}
	exit(0);
}
