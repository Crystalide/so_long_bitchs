/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_validate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:05:55 by ndufourn          #+#    #+#             */
/*   Updated: 2025/04/03 15:31:17 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Checks whether map is rectangular
int	ft_is_map_rectangular(char **map)
{
	size_t	i;
	size_t	map_width;
	size_t	current_width;

	if (!map || !map[0])
		return (0);
	map_width = ft_strlen(map[0]);
	if (map[0][map_width - 1] == '\n')
		map_width--;
	i = 1;
	while (map[i])
	{
		current_width = ft_strlen(map[i]);
		if (map[i][current_width - 1] == '\n')
			current_width--;
		if (current_width != map_width)
			return (0);
		i++;
	}
	return (1);
}
// Checks whether first and last row and column are walls
int	ft_is_map_enclosed(char **map)
{
	size_t	i;
	size_t	map_width;
	size_t	map_height;

	map_width = ft_strlen(map[0]);
	if (map[0][map_width - 1] == '\n')
		map_width--;
	map_height = 0;
	while (map[map_height])
	map_height++;
	i = 0;
	while (map[i])
	{
		if (map[0][i] != '1' || map[map_height - 1][i] != '1'
			|| map[i][0] != '1' || map[i][map_width - 1] != '1')
			return (0);
		i++;	
	}
	return (1);
}

int	ft_do_components_exist(char **map)
{
	size_t	i;
	size_t	j;
	size_t	player_count;
	size_t	exit_count;
	size_t	collectible_count;

	player_count = 0;
	exit_count = 0;
	collectible_count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player_count++;
			else if (map[i][j] == 'E')
				exit_count++;
			else if (map[i][j] == 'C')
				collectible_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1 || exit_count != 1 || collectible_count < 0)
		return (0);
	return (1);
}