/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:41:08 by nibenoit          #+#    #+#             */
/*   Updated: 2023/01/13 10:34:11 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_open_file(t_game *game)
{
	int		fd;
	char	*line;

	fd = open(game->filename, O_RDONLY);
	if (fd == -1)
		ft_exit(game, ERROR_OPEN);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		game->map_height++;
		free(line);
	}
	close(fd);
	game->map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (ERROR_MALLOC);
	game->map[game->map_height] = NULL;
	// ft_second_open(game, 0);
	return (SUCCESS);
}