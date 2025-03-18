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

int	main(void)
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*texture;
	unsigned char	*pixel;
	size_t		i;
	size_t		j;

	mlx = mlx_init(IMG_WIDTH, IMG_HEIGHT, "SO_LONG - MA GAME", true);
	if (!mlx)
		return (ft_printf("%s", "Failed to initialize MLX42\n"));
	
	texture = mlx_load_png("textures/spacebackground.png");
	if (!texture)
		return (ft_printf("%s", "Failed to load background\n"));

	img = mlx_new_image(mlx, IMG_WIDTH, IMG_HEIGHT);
	if (!img)
		return (ft_printf("%s", "Failed to create image\n"));
	
	i = 0;
	while (i < IMG_WIDTH)
	{
		j = 0;
		while (j < IMG_HEIGHT)
		{
			pixel = texture->pixels +
				((j * texture->height / IMG_HEIGHT) * texture->width +
				(i * texture->width / IMG_WIDTH)) * texture->bytes_per_pixel;
			
			mlx_put_pixel(img, i, j,
				(pixel[0] << 24) | (pixel[1] << 16) | (pixel[2] << 8) | pixel[3]);
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
