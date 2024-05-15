/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:46:46 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/05/15 21:25:10 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		ft_error();
	ft_read_map(&map, argv[1]);
	ft_free_map(&map, map.copy_grid);
	ft_init_my_mlx(&map);
	return (0);
}

void	ft_init_struct(t_map *map)
{
	map->h = 0;
	map->p_x = -1;
	map->p_y = -1;
	map->p = 0;
	map->e = 0;
	map->c = 0;
}

void	ft_init_my_mlx(t_map *map)
{
	t_data	data;

	data.i = 1;
	data.map = map;
	data.mlx = mlx_init(map->w * 50, map->h * 50, "so_long", false);
	if (!data.mlx)
		ft_error();
	ft_create_texture(&data);
	ft_put_imgs(&data, map);
	mlx_image_to_window(data.mlx, data.img_pc, map->p_x * 50, map->p_y * 50);
	mlx_key_hook(data.mlx, ft_fun, &data);
	mlx_loop(data.mlx);
	mlx_delete_texture(data.texture);
	ft_free_map(map, map->grid);
	mlx_terminate(data.mlx);
}
