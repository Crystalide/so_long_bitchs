/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:56:20 by ndufourn          #+#    #+#             */
/*   Updated: 2025/04/03 15:39:32 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

# define img_width 1080
# define img_height 720

// typedef struct s_game
// {
// 	mlx_t			*mlx;
// 	t_player_data	*player;
// 	t_map			map;
// 	size_t			img_width;
// 	size_t			img_height;
// }				t_game;

// typedef struct s_map
// {
// 	char			**map;
// 	size_t			map_width;
// 	size_t			map_height;
// 	t_map_tokens	tokens;
// }				t_map;

// typedef struct s_map_tokens
// {
// 	size_t	collectibles;
// 	size_t	exit;
// 	size_t	player;
// 	size_t	enemies;
// }				t_map_tokens;

// typedef struct s_player_data
// {
// 	size_t	player_x;
// 	size_t	player_y;
// 	size_t	collected_collectibles;
// }				t_player_data;

void	ft_add_background(mlx_image_t *img, mlx_texture_t *texture);
void	ft_close_window(void *key);
int		ft_do_components_exist(char **map);
int		ft_is_map_enclosed(char **map);
int		ft_is_map_rectangular(char **map);
char	**ft_read_map(const char *map_file);

#endif
