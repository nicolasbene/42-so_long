/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:49:26 by nibenoit          #+#    #+#             */
/*   Updated: 2023/01/13 10:31:14 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <mlx.h>
# include "libft.h"
# include <stdio.h>
# define IMG_SIZE					50
# define END_OF_GAME				2
# define SUCCESS					1
# define ERROR						0
# define ERROR_MALLOC				-2
# define ERROR_OPEN					-3
# define ERROR_INVALID_MAP			-4
# define ERROR_WALL					-5
# define ERROR_INVALID_MAP_PARAMS	-6
# define ERROR_MAP_SIZE				-7
# define ERROR_INVALID_SYMBOLS		-8
# define ERROR_USAGE				-9
# define ERROR_MLX					-10
# define KEY_W						119
# define KEY_S						115
# define KEY_A						97
# define KEY_D						100
# define KEY_ESC					65307

typedef struct s_game
{
	char	**map;
	char	*filename;
	int		map_width;
	int		map_height;
	int		collectible;
	int		player;
	int		end;
	int		nb_move;
	int		player_pos_x;
	int		player_pos_y;
	void	*sprite_player_1;
	void	*sprite_end;
	void	*sprite_collectible;
	void	*mlx;
	void	*window;
	int		img_size;
	int		win_width;
	int		win_height;

}	t_game;

// Initiate struct
void	ft_init_structure(t_game *game, char **argv);

// Exit
void	ft_exit(t_game *game, int err);

#endif