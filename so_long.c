/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:31:34 by ndufourn          #+#    #+#             */
/*   Updated: 2025/03/07 15:16:35 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "so_long.h"
#include <math.h>
#define RED

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	size_t		i;
	size_t		j;

	mlx = mlx_init(IMG_WIDTH, IMG_HEIGHT, "SO_LONG - MA GAME", true);
	if (!mlx)
		return (ft_printf("%s", "MLX42 initialization failed\n"));
	img = mlx_new_image(mlx, IMG_WIDTH, IMG_HEIGHT);
	i = 0;
	while (i < IMG_WIDTH)
	{
		j = 0;
		while (j < IMG_HEIGHT)
		{
			mlx_put_pixel(img, i, j, rand());
			j++;
		}
		i++;
	}
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop_hook(mlx, ft_close_window, mlx);
	mlx_close_hook(mlx, ft_close_window, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}

// Handles closing the window (ESC key + "X" button)
void	ft_close_window(void *key)
{
	mlx_t	*mlx;

	mlx = (mlx_t *)key;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}
