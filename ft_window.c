/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekahram <sekahram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:14:45 by sekahram          #+#    #+#             */
/*   Updated: 2022/12/23 13:38:24 by sekahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_window(t_game *game)
{
	ft_collect(game);
	game->pxl = 64;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx,
			game->pxl * game->map_x,
			game->pxl * game->map_y, "so_long 42");
	game->wallptr = mlx_xpm_file_to_image(game->mlx, WALL, \
		&game->pxl, &game->pxl);
	game->playerptr = mlx_xpm_file_to_image(game->mlx, PLAYER, \
		&game->pxl, &game->pxl);
	game->coinptr = mlx_xpm_file_to_image(game->mlx, COIN, \
		&game->pxl, &game->pxl);
	game->exittptr = mlx_xpm_file_to_image(game->mlx, EXIT, \
		&game->pxl, &game->pxl);
	game->emptyptr = mlx_xpm_file_to_image(game->mlx, EMPTY, \
		&game->pxl, &game->pxl);
	ft_res(game);
}

void	ft_res(t_game *game)
{
	char	*walkcount;

	game->y = 0;
	game->x = 0;
	ft_win(game);
	mlx_hook(game->mlx_win, 2, 1L << 0, ft_keyboard, game);
	mlx_hook(game->mlx_win, 17, 1L << 5, ft_close_window, game);
	mlx_string_put(game->mlx, game->mlx_win, 20, 30, 0xFF0000, "Walk Count:");
	walkcount = ft_itoa(game->pl_mov);
	mlx_string_put(game->mlx, game->mlx_win, 110, 30, 0xFF0000, walkcount);
	free(walkcount);
	ft_printf("Walk Count: %d\n", game->pl_mov);
	mlx_loop(game->mlx);
}

void	ft_win(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	while (game->tempmap[game->y])
	{
		game->x = 0;
		while (game->tempmap[game->y][game->x])
		{
			if (game->tempmap[game->y][game->x] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
					game->wallptr, game->x * 64, game->y * 64);
			if (game->tempmap[game->y][game->x] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
					game->playerptr, game->x * 64, game->y * 64);
			if (game->tempmap[game->y][game->x] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
					game->coinptr, game->x * 64, game->y * 64);
			if (game->tempmap[game->y][game->x] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
					game->exittptr, game->x * 64, game->y * 64);
			else if (game->tempmap[game->y][game->x] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win, \
					game->emptyptr, game->x * 64, game->y * 64);
			game->x ++;
		}
		game->y++;
	}
}

int	ft_keyboard(int keyhook, t_game *game)
{
	if (keyhook == 53)
		ft_close_window(game);
	if (game->collect == 0
		&& ((keyhook == 2 && \
		game->tempmap[game->player_y][game->player_x + 1] == 'E')
		|| (keyhook == 1 && \
		game->tempmap[game->player_y + 1][game->player_x] == 'E')
		|| (keyhook == 0 && \
		game->tempmap[game->player_y][game->player_x - 1] == 'E')
		|| (keyhook == 13 && \
		game->tempmap[game->player_y - 1][game->player_x] == 'E')))
	{
		ft_printf("Walk Count: %d\n", game->pl_mov + 1);
		ft_printf("Game Over!! YOU WON!!\n");
		ft_close_window(game);
	}
	ft_key_hook(keyhook, game);
	ft_res(game);
	return (0);
}

void	ft_key_hook(int keyhook, t_game *game)
{
	if (keyhook == 13 && \
		game->tempmap[game->player_y - 1][game->player_x] != '1'
		&& game->tempmap[game->player_y - 1][game->player_x] != 'E')
		ft_move_up(game);
	if (keyhook == 0 && game->tempmap[game->player_y][game->player_x - 1] != '1'
		&& game->tempmap[game->player_y][game->player_x - 1] != 'E')
		ft_move_left(game);
	if (keyhook == 1 && game->tempmap[game->player_y + 1][game->player_x] != '1'
		&& game->tempmap[game->player_y + 1][game->player_x] != 'E')
		ft_move_down(game);
	if (keyhook == 2 && game->tempmap[game->player_y][game->player_x + 1] != '1'
		&& game->tempmap[game->player_y][game->player_x + 1] != 'E')
		ft_move_right(game);
}
