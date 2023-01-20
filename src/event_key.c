/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:56:11 by nibenoit          #+#    #+#             */
/*   Updated: 2023/01/20 15:54:59 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_msg(int i)
{
	if (i == 1)
	{
		ft_putstr_fd("-----------------------", 1);
		ft_putstr_fd("\n-----|| YOU  WON ||----\n", 1);
		ft_putstr_fd("-----------------------\n", 1);
	}
	if (i == 2)
	{
		ft_putstr_fd("------------------------------------------", 1);
		ft_putstr_fd("\n-------------|| GAME  OVER ||-------------\n", 1);
		ft_putstr_fd("------------------------------------------\n", 1);
	}
}

void	ft_check_key(t_game *game, int x, int y)
{
	if (game->map[x][y] == '0' || game->map[x][y] == 'C'
	|| (game->map[x][y] == 'E' && game->collectible == 0))
	{
		if (game->map[x][y] == 'C')
			game->collectible--;
		else if (game->collectible == 0 && game->map[x][y] == 'E')
		{
			ft_print_msg(1);
			ft_exit(game, END_OF_GAME);
		}
		game->map[x][y] = 'P';
		game->map[game->player_pos_x][game->player_pos_y] = '0';
		game->player_pos_x = x;
		game->player_pos_y = y;
		game->nb_move++;
		ft_putnbr_fd(game->nb_move, 1);
		ft_putchar_fd('\n', 1);
	}
	if (game->map[x][y] == 'X' && (ft_subword(game->filename, "bonus")
	== SUCCESS))
	{
		ft_print_msg(2);
		ft_exit(game, END_OF_GAME);
	}
}

int	ft_event_key(int key_code, t_game *game)
{
	char	*printed_moves;

	if (key_code == KEY_W)
		ft_check_key(game, game->player_pos_x - 1, game->player_pos_y);
	else if (key_code == KEY_S)
		ft_check_key(game, game->player_pos_x + 1, game->player_pos_y);
	else if (key_code == KEY_A)
		ft_check_key(game, game->player_pos_x, game->player_pos_y - 1);
	else if (key_code == KEY_D)
		ft_check_key(game, game->player_pos_x, game->player_pos_y + 1);
	else if (key_code == KEY_ESC)
		ft_exit(game, END_OF_GAME);
	ft_render_img(game, key_code);
	printed_moves = ft_itoa(game->nb_move);
	if (!(printed_moves))
		ft_exit(game, ERROR_MALLOC);
	mlx_string_put(game->mlx, game->window, 55, 65, 45, printed_moves);
	free(printed_moves);
	return (SUCCESS);
}
