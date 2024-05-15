/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgonzal2 <pgonzal2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:36:55 by pgonzal2          #+#    #+#             */
/*   Updated: 2024/05/15 21:17:50 by pgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_left(t_data *data)
{
	data->map->p_x--;
	data->img_pc->instances[0].x -= 50;
	ft_printf("moves:	%i\n", data->i);
	data->i++;
}

void	ft_right(t_data *data)
{
	data->map->p_x++;
	data->img_pc->instances[0].x += 50;
	ft_printf("moves:	%i\n", data->i);
	data->i++;
}

void	ft_down(t_data *data)
{
	data->map->p_y++;
	data->img_pc->instances[0].y += 50;
	ft_printf("moves:	%i\n", data->i);
	data->i++;
}

void	ft_up(t_data *data)
{
	data->map->p_y--;
	data->img_pc->instances[0].y -= 50;
	ft_printf("moves:	%i\n", data->i);
	data->i++;
}

void	ft_check_exit(t_data *data)
{
	if (data->map->grid[data->map->p_y][data->map->p_x] == 'C')
	{
		data->map->grid[data->map->p_y][data->map->p_x] = '0';
		data->map->c--;
		ft_print_colectables(data);
	}
	if (data->map->grid[data->map->p_y][data->map->p_x] == 'E'
		&& data->map->c == 0)
		mlx_close_window(data->mlx);
}
