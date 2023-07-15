/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekahram <sekahram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:14:13 by sekahram          #+#    #+#             */
/*   Updated: 2022/12/23 13:34:20 by sekahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_area_control_v2(t_game *game)
{
	if (game->map_area != game->map_x * game->map_y)
	{
		ft_printf("wrong map desing!!");
		exit(1);
	}
}

void	ft_wall_control(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_y)
	{
		if (game->map[i][0] != '1')
		{
			ft_printf("left side wall error");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < game->map_x)
	{
		if (game->map[0][i] != '1')
		{
			ft_printf("top side wall error");
			exit(1);
		}
		i++;
	}
}

void	ft_wall_control_v2(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_y)
	{
		if (game->map[i][game->map_x - 1] != '1')
		{
			ft_printf("right side wall error");
			exit(1);
		}
		i++;
	}
	i = 0;
	while (i < game->map_x)
	{
		if (game->map[game->map_y - 1][i] != '1')
		{
			ft_printf("bottom side wall error");
			exit(1);
		}
		i++;
	}
}

void	ft_player_find(t_game *game)
{
	while (game->player_y < game->map_y)
	{
		while (game->player_x < game->map_x)
		{
			if (game->map[game->player_y][game->player_x] == 'P')
			{
				ft_map_playable_control(game);
				ft_end_map_control(game);
				return ;
			}
			game->player_x++;
		}
		game->player_x = 0;
		game->player_y++;
	}
}

void	ft_end_map_control(t_game *game)
{
	if (game->collect > 0 || game->exit > 0)
	{
		ft_printf("not playable MAP");
		exit(1);
	}
}
