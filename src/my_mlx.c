/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:39:04 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/05/15 21:27:01 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_fun(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window((data)->mlx);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS
		&& data->map->grid[data->map->p_y][data->map->p_x - 1] != '1')
		ft_left(data);
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS
		&& data->map->grid[data->map->p_y][data->map->p_x + 1] != '1')
		ft_right(data);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS && data->map->grid[data->map->p_y + 1]
		[data->map->p_x] != '1')
		ft_down(data);
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& data->map->grid[data->map->p_y - 1][data->map->p_x] != '1')
		ft_up(data);
	ft_check_exit(data);
}

void	ft_print_colectables(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	if (data->img_poke)
	{
		mlx_delete_image(data->mlx, data->img_poke);
		data->img_poke = mlx_texture_to_image(data->mlx, data->texture);
	}
	while (j < data->map->h)
	{
		i = 0;
		while (i < data->map->w)
		{
			if (data->map->grid[j][i] == 'C')
				mlx_image_to_window(data->mlx, data->img_poke, i * 50, j * 50);
			i++;
		}
		j++;
	}
}

void	ft_create_texture(t_data *data)
{
	data->texture = mlx_load_png("texture/bush.png");
	if (!data->texture)
		ft_error();
	data->img_wall = mlx_texture_to_image(data->mlx, data->texture);
	mlx_delete_texture(data->texture);
	data->texture = mlx_load_png("texture/fond.png");
	if (!data->texture)
		ft_error();
	data->img_floor = mlx_texture_to_image(data->mlx, data->texture);
	mlx_delete_texture(data->texture);
	data->texture = mlx_load_png("texture/npc.png");
	if (!data->texture)
		ft_error();
	data->img_pc = mlx_texture_to_image(data->mlx, data->texture);
	mlx_delete_texture(data->texture);
	data->texture = mlx_load_png("texture/imgexit.png");
	if (!data->texture)
		ft_error();
	data->img_exit = mlx_texture_to_image(data->mlx, data->texture);
	mlx_delete_texture(data->texture);
	data->texture = mlx_load_png("texture/poke.png");
	if (!data->texture)
		ft_error();
	data->img_poke = mlx_texture_to_image(data->mlx, data->texture);
}

void	ft_put_imgs(t_data *data, t_map *map)
{
	int	i;
	int	j;

	j = -1;
	while (++j < map->h)
	{
		i = 0;
		while (i < map->w)
		{
			if (map->grid[j][i] == '1')
				mlx_image_to_window(data->mlx, data->img_wall, i * 50, j * 50);
			if (map->grid[j][i] == 'P')
				mlx_image_to_window(data->mlx, data->img_floor, i * 50, j * 50);
			if (map->grid[j][i] == '0')
				mlx_image_to_window(data->mlx, data->img_floor, i * 50, j * 50);
			if (map->grid[j][i] == 'C')
			{
				mlx_image_to_window(data->mlx, data->img_floor, i * 50, j * 50);
				mlx_image_to_window(data->mlx, data->img_poke, i * 50, j * 50);
			}
			if (map->grid[j][i] == 'E')
				mlx_image_to_window(data->mlx, data->img_exit, i * 50, j * 50);
			i++;
		}
	}
}
