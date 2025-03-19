/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:56:20 by ndufourn          #+#    #+#             */
/*   Updated: 2025/03/19 17:10:40 by ndufourn         ###   ########.fr       */
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

void	ft_add_background(mlx_image_t *img, mlx_texture_t *texture);
void	ft_close_window(void *key);
char	**ft_read_map(const char *map_file);


#endif
