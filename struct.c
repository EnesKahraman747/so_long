/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekahram <sekahram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:15:02 by sekahram          #+#    #+#             */
/*   Updated: 2022/12/23 14:00:42 by sekahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_struct(t_game *game)
{
	game->map_x = 0;
	game->map_y = 0;
	game->map_area = 0;
	game->x = 0;
	game->y = 0;
	game->pxl = 0;
	game->player = 0;
	game->pl_mov = 0;
	game->collect = 0;
	game->exit = 0;
	game->player_x = 0;
	game->player_y = 0;
}
