/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:25:25 by nibenoit          #+#    #+#             */
/*   Updated: 2023/01/17 18:47:27 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_istofill(char c)
{
	if (c == 'P' || c == 'C' || c == 'E' || c == '0')
		return (1);
	return (0);
}

void	ft_fill(char **map, t_point size, t_point cur, t_count *count)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| ft_istofill(map[cur.y][cur.x]) == 0)
		return ;
	if (map[cur.y][cur.x] == 'C')
		count->c++;
	if (map[cur.y][cur.x] == 'E')
		count->e++;
	map[cur.y][cur.x] = 'F';
	ft_fill(map, size, (t_point){cur.x - 1, cur.y}, count);
	ft_fill(map, size, (t_point){cur.x + 1, cur.y}, count);
	ft_fill(map, size, (t_point){cur.x, cur.y - 1}, count);
	ft_fill(map, size, (t_point){cur.x, cur.y + 1}, count);
}

char	**ft_map_fill(t_game *game, char **map, int width)
{
	char	**map2;
	int		i;
	int		j;

	map2 = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!map2)
		ft_exit(game, ERROR_MALLOC);
	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		map2[i] = (char *)malloc(sizeof(char) * (game->map_width + 1));
		while (j < width)
		{
			map2[i][j] = map[i][j];
			printf("%c", map2[i][j]);
			j++;
		}
		printf("\n");
		map2[i][j] = '\0';
		i++;
	}
	map2[i] = '\0';
	return (map2);
}

int	ft_check_path(t_game *game)
{
	t_point	begin;
	t_point	size;
	t_count	count;
	int		i;
	char	**map2;

	size.y = game->map_height;
	size.x = game->map_width;
	begin.y = game->player_pos_x;
	begin.x = game->player_pos_y;
	count.c = 0;
	count.e = 0;
	map2 = ft_map_fill(game, game->map, game->map_width);
	ft_fill(map2, size, begin, &count);
	i = 0;
	while (i < game->map_height)
	{
		free(map2[i]);
		i++;
	}
	free(map2);
	if (count.c == game->collectible && count.e == game->end)
		return (SUCCESS);
	return (ERROR_PATH);
}
