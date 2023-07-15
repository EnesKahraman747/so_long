/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekahram <sekahram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:14:58 by sekahram          #+#    #+#             */
/*   Updated: 2022/12/22 20:14:59 by sekahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_game *game)
{
	if (game->tempmap[game->player_y - 1][game->player_x] == 'C')
		game->collect--;
	game->tempmap[game->player_y][game->player_x] = '0';
	game->tempmap[game->player_y - 1][game->player_x] = 'P';
	game->player_y--;
	game->pl_mov++;
}

void	ft_move_down(t_game *game)
{
	if (game->tempmap[game->player_y + 1][game->player_x] == 'C')
		game->collect--;
	game->tempmap[game->player_y][game->player_x] = '0';
	game->tempmap[game->player_y + 1][game->player_x] = 'P';
	game->player_y++;
	game->pl_mov++;
}

void	ft_move_left(t_game *game)
{
	if (game->tempmap[game->player_y][game->player_x - 1] == 'C')
		game->collect--;
	game->tempmap[game->player_y][game->player_x] = '0';
	game->tempmap[game->player_y][game->player_x - 1] = 'P';
	game->pl_mov++;
	game->player_x--;
}

void	ft_move_right(t_game *game)
{
	if (game->tempmap[game->player_y][game->player_x + 1] == 'C')
		game->collect--;
	game->tempmap[game->player_y][game->player_x] = '0';
	game->tempmap[game->player_y][game->player_x + 1] = 'P';
	game->pl_mov++;
	game->player_x++;
}

int	ft_close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}
