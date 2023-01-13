/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:19:23 by nibenoit          #+#    #+#             */
/*   Updated: 2023/01/13 10:26:15 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_structure(t_game *game, char **argv)
{
	game->filename = argv[1];
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->collectible = 0;
	game->player = 0;
	game->end = 0;
	game->nb_move = 0;
	game->player_pos_x = 0;
	game->player_pos_y = 0;
	game->sprite_player_1 = NULL;
	game->sprite_collectible = NULL;
	game->sprite_end = NULL;
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_exit(game, ERROR_MLX);
	game->window = NULL;
	game->img_size = 0;
	game->win_width = 0;
	game->win_height = 0;
}

static void	ft_check_errors(t_game *game)
{
	int	err;

	err = ft_open_file(game);
	if (err < 0)
		ft_exit(game, err);
	err = ft_check_rectangle(game);
	if (err < 0)
		ft_exit(game, err);
	err = ft_check_symbol(game);
	if (err < 0)
		ft_exit(game, err);
	err = ft_check_wall(game);
	if (err < 0)
		ft_exit(game, err);
	err = ft_parse_xpm(game);
	if (err < 0)
		ft_exit(game, err);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	
	if (argc != 2)
		ft_exit(NULL, ERROR_USAGE);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		ft_exit(game, ERROR_MALLOC);
	ft_init_structure(game, argv);
	if (check_extension(game) == ERROR)
		ft_exit(game, ERROR_USAGE);
	ft_check_errors(game);
	
	return (0);
}