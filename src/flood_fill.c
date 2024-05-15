/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:21:58 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/05/10 18:42:36 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_save_player(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->h)
	{
		j = 0;
		while (map->grid[i][j] != '\0')
		{
			if (!ft_valid(map, i, j))
				ft_error();
			if (map->grid[i][j] == 'P')
			{
				map->p_x = j;
				map->p_y = i;
			}
			j++;
		}
	}
	if (map->p != 1 || map->e != 1 || map->c == 0)
		ft_error();
	i = -1;
	while (++i < map->h)
		map->copy_grid[i] = ft_strdup(map->grid[i]);
	ft_flood_fill(map, map->p_x, map->p_y);
}

void	ft_flood_fill(t_map *map, int x, int y)
{
	if (map->copy_grid[y][x] == '1' || map->copy_grid[y][x] == 'F')
		return ;
	map->copy_grid[y][x] = 'F';
	ft_flood_fill(map, x - 1, y);
	ft_flood_fill(map, x + 1, y);
	ft_flood_fill(map, x, y - 1);
	ft_flood_fill(map, x, y + 1);
}

void	ft_check_collectibles(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (map->copy_grid[i][j] != '\0')
		{
			if (map->copy_grid[i][j] == 'C')
			{
				ft_error();
				exit(1);
			}
			if (map->copy_grid[i][j] == 'E')
				ft_error();
			j++;
		}
		i++;
	}
}

int	ft_valid(t_map *map, int i, int j)
{
	if (map->grid[i][j] != 'P' && map->grid[i][j] != 'E'
		&& map->grid[i][j] != '1' && map->grid[i][j] != '0'
		&& map->grid[i][j] != 'C' && map->grid[i][j] != '\0'
		&& map->grid[i][j] != '\n')
		return (0);
	if (map->grid[i][j] == 'C')
		map->c++;
	if (map->grid[i][j] == 'P')
		map->p++;
	if (map->grid[i][j] == 'E')
		map->e++;
	return (1);
}
