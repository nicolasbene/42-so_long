/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:38:43 by nibenoit          #+#    #+#             */
/*   Updated: 2023/01/13 09:32:21 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(int err)
{
	if (err == ERROR_USAGE)
		ft_putstr_fd("ERROR_USAGE", 2);

		
}

void	ft_exit(t_game *game, int err)
{
	print_error(err);
}