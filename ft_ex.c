/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekahram <sekahram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:14:15 by sekahram          #+#    #+#             */
/*   Updated: 2022/12/22 20:14:16 by sekahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collect(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map_y)
	{
		x = 0;
		while (game->tempmap[y][x])
		{
			if (game->tempmap[y][x] == 'C')
				game->collect++;
			x++;
		}
		y++;
	}
}
