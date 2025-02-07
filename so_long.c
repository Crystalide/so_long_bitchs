/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:31:34 by ndufourn          #+#    #+#             */
/*   Updated: 2025/02/07 15:41:39 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "so_long.h"

int	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(1080, 720, "SO_LONG - MA GAME", true);
	if (!mlx)
		return(ft_printf("%s", "MLX42 initialization failed\n"));
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
