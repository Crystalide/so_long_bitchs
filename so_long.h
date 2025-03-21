/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:56:20 by ndufourn          #+#    #+#             */
/*   Updated: 2025/03/21 15:38:18 by ndufourn         ###   ########.fr       */
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

// # define img_width 1080
// # define img_height 720

typedef struct s_game
{
	mlx_t			*mlx;
	t_player_data	*player;
	t_map			map;
	size_t			img_width;
	size_t			img_height;
}				t_game;

typedef struct s_map
{
	char	**map;
	size_t	map_width;
	size_t	map_height;
	size_t	token_co;
	size_t	token_ex;
	size_t	token_pl;
	size_t	token_en;
}				t_map;

typedef struct s_player_data
{
	size_t	player_x;
	size_t	player_y;
	size_t	collected_co;
}				t_player_data;

void	ft_add_background(mlx_image_t *img, mlx_texture_t *texture);
void	ft_close_window(void *key);
char	**ft_read_map(const char *map_file);

#endif
