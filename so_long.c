/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndufourn <ndufourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:31:34 by ndufourn          #+#    #+#             */
/*   Updated: 2025/04/11 17:22:13 by ndufourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "so_long.h"

void	ft_initialize_game(t_game *game)
{
	game->img_width = 1080;
	game->img_height = 720;
	
	game->player = malloc(sizeof(t_player_data));
	if (!game->player)
		return (perror("Error: Failed to allocate player memory"));
	
	game->player->player_x = 0;
	game->player->player_y = 0;
	game->player->collected_collectibles = 0;

	game->map.map = NULL;
	game->map.map_width = 0;
	game->map.map_height = 0;

	game->map.tokens.player = 0;
	game->map.tokens.exit = 0;
	game->map.tokens.collectibles = 0;
	game->map.tokens.enemies = 0;
}

// mlx_t	*ft_init_mlx(size_t img_width, size_t img_height)
// {
// 	mlx_t	*mlx;
	
// 	mlx = mlx_init(img_width, img_height, "SO_LONG - MA GAME", true);
// 	if (!mlx)
// 		return (perror("Error: Failed to initialize MLX42"), NULL);
// 	return (mlx);
// }

int	main(void)
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*texture;
	t_game			game;
	size_t			i;

	ft_initialize_game(&game);
	
	// mlx = ft_init_mlx(game.img_width, game.img_height);
	mlx = mlx_init(game.img_width, game.img_height, "SO_LONG - MA GAME", true);
	if (!mlx)
		return (perror("Error:Failed to initialize MLX42"), 1);

	texture = mlx_load_png("textures/spacebackground.png");
	if (!texture)
		return (mlx_terminate(mlx), perror("Error: Failed to load background"), 1);
	img = mlx_new_image(mlx, game.img_width, game.img_height);
	if (!img)
	{
		mlx_delete_texture(texture);
		return (mlx_terminate(mlx), perror("Error: Failed to create image"), 1);
	}

	ft_add_background(&game, img, texture);
	mlx_delete_texture(texture);
	
	game.map.map = ft_read_map(&game, "map.ber");
	if (!game.map.map)
	return (mlx_terminate(mlx), perror("Error: Failed to read map file"), 1);
	
	if (!ft_is_map_rectangular(&game))
	return (mlx_terminate(mlx), perror("Error: Map not rectangular"), 1);
	
	if (!ft_is_map_enclosed(&game))
	return (mlx_terminate(mlx), perror("Error: Map not enclosed in walls"), 1);
	
	if (!ft_do_components_exist(&game))
	return (mlx_terminate(mlx), perror("Error: Invalid map components"), 1);
	
	// Map reading and processing logic (validation, parsing, etc.)
	i = 0;
	while (game.map.map[i])
	{
		ft_printf("%s\n", game.map.map[i]);
		i++;
	}
	
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop_hook(mlx, ft_close_window, &game);
	mlx_close_hook(mlx, ft_close_window, &game);
	mlx_loop(mlx);
	ft_free_resources(&game);
	mlx_terminate(mlx);
	return (0);
}

// Scales the texture to the window.
// Let's say:
// The texture is 200 × 200 pixels. The window is 400 × 400 pixels.
// The goal is to stretch the 200 × 200 texture to fill the 400 × 400 window.
// If we're at window position (i, j) = (100, 100), the calculation would be:
// j * texture->height / IMG_HEIGHT → 100 * 200 / 400 = 50 → row 50 in the texture
// i * texture->width / IMG_WIDTH → 100 * 200 / 400 = 50 → column 50 in the texture
// So, the pixel drawn at (100, 100) in the window would come from (50, 50) in the texture.
void	ft_add_background(t_game *game, mlx_image_t *img, mlx_texture_t *texture)
{
	unsigned char	*pixel;
	unsigned char	color;
	size_t			i;
	size_t			j;

	i = 0;
	while (i < game->img_width)
	{
		j = 0;
		while (j < game->img_height)
		{
			pixel = texture->pixels
			+ ((j * texture->height / game->img_height) * texture->width
			+ (i * texture->width / game->img_width)) * texture->bytes_per_pixel;
			color = (pixel[0] << 24) | (pixel[1] << 16) | (pixel[2] << 8) | pixel[3];
			mlx_put_pixel(img, i, j, color);
			j++;
		}
		i++;
	}
}
// Frees all game resources before closing
void	ft_free_resources(t_game *game)
{
	size_t	i;
	
	if (game->map.map)
	{
		i = 0;
		while (game->map.map[i])
		{
			free(game->map.map[i]);
			i++;
		}
		free(game->map.map);
	}
	if (game->player)
		free(game->player);
}

// Handles closing the window (ESC key + "X" button)
void	ft_close_window(void *key)
{
	t_game	*game;

	game = (t_game *)key;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
}


// #include "so_long.h"
// int	main(void)
// {
// 	mlx_t			*mlx;
// 	mlx_image_t		*img;
// 	mlx_texture_t	*texture;
// 	char			**map;
// 	size_t			i;

// 	mlx = mlx_init(img_width, img_height, "SO_LONG - MA GAME", true);
// 	if (!mlx)
// 		return (ft_printf("%s", "Error: Failed to initialize MLX42\n"));
// 	texture = mlx_load_png("textures/spacebackground.png");
// 	if (!texture)
// 		return (ft_printf("%s", "Error: Failed to load background\n"));
// 	img = mlx_new_image(mlx, img_width, img_height);
// 	if (!img)
// 		return (ft_printf("%s", "Error: Failed to create image\n"));

// 	ft_add_background(img, texture);
// 	mlx_image_to_window(mlx, img, 0, 0);
// 	mlx_delete_texture(texture);

// 	map = ft_read_map("map.ber");
// 	if (!map)
// 		return (mlx_terminate(mlx), perror("Error: Failed to read map file"), 1);

// 	if (!ft_is_map_rectangular(map))
// 		return (mlx_terminate(mlx), perror("Error: Map not rectangular"), 1);

// 	if (!ft_is_map_enclosed(map))
// 		return (mlx_terminate(mlx), perror("Error: Map not enclosed in walls"), 1);

// 	if (!ft_do_components_exist(map))
// 		return (mlx_terminate(mlx), perror("Error: Invalid map components"), 1);
	
// 	// Map reading and processing logic (validation, parsing, etc.)
// 	i = 0;
// 	while (map[i])
// 	{
// 		ft_printf("%s\n", map[i]);
// 		free(map[i]);
// 		i++;
// 	}
// 	free(map);
	
// 	mlx_loop_hook(mlx, ft_close_window, mlx);
// 	mlx_close_hook(mlx, ft_close_window, mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (0);
// }
// void	ft_add_background(mlx_image_t *img, mlx_texture_t *texture)
// {
// 	unsigned char	*pixel;
// 	size_t			i;
// 	size_t			j;

// 	i = 0;
// 	while (i < img_width)
// 	{
// 		j = 0;
// 		while (j < img_height)
// 		{
// 			pixel = texture->pixels
// 				+ ((j * texture->height / img_height) * texture->width
// 					+ (i * texture->width / img_width)) * texture->bytes_per_pixel;
// 			mlx_put_pixel(img, i, j,
// 				(pixel[0] << 24) | (pixel[1] << 16) | (pixel[2] << 8) | pixel[3]);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// char	**ft_read_map(const char *map_file)
// {
// 	int				fd_map;
// 	char			*line;
// 	char			**map;
// 	size_t			map_buffer;
// 	size_t			i;

	
// 	fd_map = open(map_file, O_RDONLY);
// 	if (fd_map == -1)
// 		return (perror("Error: Failed to open map file"), NULL);
// 	map_buffer = 42;
// 	map = malloc(sizeof(char *) * map_buffer);
// 	if (!map)
// 		return (perror("Error: Failed malloc for map file"), NULL);
// 		//check if fd_map needs to be closed
// i = 0;
// while ((line = ft_get_next_line(fd_map)) != NULL)
// {
// 	if (i >= map_buffer)
// 	{
// 		map_buffer = map_buffer * 2;
// 		map = ft_realloc(map, sizeof(char*) * (i+1), sizeof(char *) * map_buffer);
// 		if (!map)
// 		{
// 			close(fd_map);
// 			return (perror("Error: Failed malloc for new map file"), NULL);
// 		}
// 	}
// 	map[i] = line;
// 	i++;
// }
// map[i] = NULL;
// 	close(fd_map);
// 	return (map);
// }
// Checks whether map is rectangular
// int	ft_is_map_rectangular(char **map)
// {
// 	size_t	i;
// 	size_t	map_width;
// 	size_t	current_width;

// 	if (!map || !map[0])
// 		return (0);
// 	map_width = ft_strlen(map[0]);
// 	if (map[0][map_width - 1] == '\n')
// 		map_width--;
// 	i = 1;
// 	while (map[i])
// 	{
// 		current_width = ft_strlen(map[i]);
// 		if (map[i][current_width - 1] == '\n')
// 			current_width--;
// 		if (current_width != map_width)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int	ft_is_map_enclosed(char **map)
// {
// 	size_t	i;
// 	size_t	map_width;
// 	size_t	map_height;

// 	map_width = ft_strlen(map[0]);
// 	if (map[0][map_width - 1] == '\n')
// 		map_width--;
// 	map_height = 0;
// 	while (map[map_height])
// 	map_height++;
// 	i = 0;
// 	while (map[i])
// 	{
// 		if (map[0][i] != '1' || map[map_height - 1][i] != '1'
// 			|| map[i][0] != '1' || map[i][map_width - 1] != '1')
// 			return (0);
// 		i++;	
// 	}
// 	return (1);
// }



// // Handles closing the window (ESC key + "X" button)
// void	ft_close_window(void *key)
// {
// 	mlx_t	*mlx;

// 	mlx = (mlx_t *)key;
// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// }