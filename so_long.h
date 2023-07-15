/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekahram <sekahram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:16:59 by sekahram          #+#    #+#             */
/*   Updated: 2022/12/23 13:57:34 by sekahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "minilibx/mlx.h"

# define WALL "./sprites/wall.xpm"
# define COIN "./sprites/banana.xpm"
# define PLAYER "./sprites/boy.xpm"
# define EXIT "./sprites/home.xpm"
# define EMPTY "./sprites/green.xpm"

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	**tempmap;
	int		map_x;
	int		map_y;
	int		map_area;
	int		x;
	int		y;
	int		pxl;
	int		player;
	int		player_x;
	int		player_y;
	int		pl_mov;
	char	*pl_dir;
	int		collect;
	int		exit;
	void	*wallptr;
	void	*playerptr;
	void	*coinptr;
	void	*exittptr;
	void	*emptyptr;
}	t_game;

void	ft_struct(t_game *game);
void	ft_map(char **argv, t_game *game);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_read_map(int fd);
char	*ft_strjoin(char *left_str, char buff);
void	ft_control_obj(char *buffer, t_game *game);
int		ft_line_control(char *line);
void	ft_map_area_control(char *buffer, t_game *game);
void	ft_map_area_control_v2(t_game *game);
void	ft_wall_control(t_game *game);
void	ft_wall_control_v2(t_game *game);
void	ft_map_playable_control(t_game *game);
void	ft_player_find(t_game *game);
void	ft_map_control_v1(t_game *game);
void	ft_map_control_v2(t_game *game);
void	ft_map_control_v3(t_game *game);
void	ft_map_control_v4(t_game *game);
void	ft_end_map_control(t_game *game);
void	ft_window(t_game *game);
void	ft_move_right(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_up(t_game *game);
void	ft_win(t_game *game);
int		ft_keyboard(int keyhook, t_game *game);
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);
int		ft_close_window(t_game *game);
void	ft_res(t_game *game);
void	ft_collect(t_game *game);
void	ft_key_hook(int key_hook, t_game *game);
char	*ft_itoa(int n);

#endif
