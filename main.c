/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekahram <sekahram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:14:05 by sekahram          #+#    #+#             */
/*   Updated: 2022/12/23 13:37:11 by sekahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map(char **argv, t_game *game)
{
	int		i;
	int		fd;
	char	*buffer;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("map crash!!");
		exit(1);
	}
	buffer = ft_read_map(fd);
	ft_control_obj(buffer, game);
	game->map = ft_split(buffer, '\n');
	game->tempmap = ft_split(buffer, '\n');
	free(buffer);
	while (game->map[0][i] != '\0')
	{
		game->map_x++;
		i++;
	}
	ft_map_area_control(buffer, game);
	close(fd);
}

int	ft_arg_control_2(char **argv)
{
	size_t	i;
	char	*a;

	a = argv[1];
	i = 0;
	i = ft_strlen(a);
	if (a[i - 4] != '.' || i < 3)
	{
		ft_printf("no map");
		exit(1);
	}
	return (0);
}

int	ft_arg_control(int arg, char **argv)
{
	int	i;

	i = 0;
	if (arg == 2)
	{
		while (argv[1][i++])
		{
			if (argv[1][i] == '.')
			{
				if (argv[1][i + 1] != 'b' || argv[1][i + 2] != 'e'
				|| argv[1][i + 3] != 'r')
				{
					ft_printf("wrong map format\n");
					exit(1);
				}
			}
		}
		ft_arg_control_2(argv);
	}
	else
	{
		ft_printf("./<main.c> <name.ber>");
		exit(1);
	}
	return (0);
}

int	main(int arg, char **argv)
{
	t_game	game;

	ft_arg_control(arg, argv);
	ft_struct(&game);
	ft_map(argv, &game);
	ft_player_find(&game);
	ft_window(&game);
	return (0);
}
