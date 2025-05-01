/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_read_parse.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:07:36 by ndufourn          #+#    #+#             */
/*   Updated: 2025/04/11 17:26:44 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_read_map(t_game *game, const char *map_file)
{
	int				fd_map;
	char			*line;
	char			**map;
	size_t			i;
	size_t			map_buffer;

	
	fd_map = open(map_file, O_RDONLY);
	if (fd_map == -1)
		return (perror("Error: Failed to open map file"), NULL);
	map_buffer = 10;
	map = malloc(sizeof(char *) * map_buffer);
	if (!map)
	{
		close(fd_map);
		return (perror("Error: Failed malloc for map file"), NULL);
	}
	i = 0;
	while ((line = ft_get_next_line(fd_map)) != NULL)
	{
		if (i >= map_buffer)
		{
			map_buffer = map_buffer * 2;
			map = ft_realloc(map, sizeof(char*) * (i+1), sizeof(char *) * map_buffer);
			if (!map)
			{
				close(fd_map);
				return (perror("Error: Failed malloc for new map file"), NULL);
			}
		}
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	close(fd_map);
	game->map.map_width = i;
	if (i > 0)
		game->map.map_height = ft_strlen(map[0]);
	game->map.map = map;
	return (map);
}
