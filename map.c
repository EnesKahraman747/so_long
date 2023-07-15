/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekahram <sekahram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:14:54 by sekahram          #+#    #+#             */
/*   Updated: 2022/12/23 13:54:09 by sekahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_area_control(char *buffer, t_game *game)
{
	game->map_area = ft_strlen(buffer) - game->map_y;
	ft_map_area_control_v2(game);
	ft_wall_control(game);
	ft_wall_control_v2(game);
}

void	ft_control_obj(char *buffer, t_game *game)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'P')
			game->player++;
		else if (buffer[i] == 'C')
			game->collect++;
		else if (buffer[i] == 'E')
			game->exit++;
		else if (buffer[i] == '\n')
			game->map_y++;
		else if (buffer[i] != '1' && buffer[i] != '0')
		{
			ft_printf("Map harf hatasi!");
			exit(1);
		}
		i++;
	}
	if (game->player != 1 || game->collect < 1 || game->exit != 1)
	{
		ft_printf("Map object crasshhhh!!!");
		exit(1);
	}
}

int	ft_line_control(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *left_str, char buff)
{
	int		i;
	char	*str;

	i = 0;
	while (left_str[i])
			i++;
	str = malloc(i + 2);
	i = 0;
	while (left_str[i])
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = buff;
	str[i + 1] = '\0';
	free(left_str);
	return (str);
}

char	*ft_read_map(int fd)
{
	char	buffer;
	int		rd_bytes;
	char	*line;

	line = malloc(1);
	line[0] = '\0';
	rd_bytes = 1;
	while (rd_bytes > 0 && !ft_line_control(line))
	{
		rd_bytes = read(fd, &buffer, 1);
		if (rd_bytes == 0)
			return (line);
		line = ft_strjoin(line, buffer);
	}
	return (line);
}
