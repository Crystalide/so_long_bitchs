/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_validate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:05:55 by ndufourn          #+#    #+#             */
/*   Updated: 2025/04/11 17:11:54 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Checks whether map is rectangular
int	ft_is_map_rectangular(t_game *game)
{
	size_t	i;
	size_t	map_width;
	size_t	current_width;

	if (!game->map.map || !game->map.map[0])
		return (0);
	map_width = ft_strlen(game->map.map[0]);
	if (game->map.map[0][map_width - 1] == '\n')
		map_width--;
	i = 1;
	while (game->map.map[i])
	{
		current_width = ft_strlen(game->map.map[i]);
		if (game->map.map[i][current_width - 1] == '\n')
			current_width--;
		if (current_width != map_width)
			return (0);
		i++;
	}
	game->map.map_width = map_width;
	game->map.map_height = i;
	return (1);
}
// Checks whether first and last row and column are walls
int	ft_is_map_enclosed(t_game *game)
{
	size_t	i;
	size_t	map_width;
	size_t	map_height;

	map_width = game->map.map_width;
	map_height = game->map.map_height;
	i = 0;
	while (i < map_width)
	{
		if (game->map.map[0][i] != '1' || game->map.map[map_height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map_height)
	{
		if (game->map.map[i][0] != '1' || game->map.map[i][map_width - 1] != '1')
			return (0);
		i++;	
	}
	return (1);
}

int	ft_do_components_exist(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'P')
				game->map.tokens.player++;
			else if (game->map.map[i][j] == 'E')
				game->map.tokens.exit++;
			else if (game->map.map[i][j] == 'C')
				game->map.tokens.collectibles++;
			j++;
		}
		i++;
	}
	if (game->map.tokens.player != 1 || game->map.tokens.exit != 1 || game->map.tokens.collectibles < 0)
		return (0);
	return (1);
}