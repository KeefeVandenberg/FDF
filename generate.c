/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <kvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:20:15 by kvandenb          #+#    #+#             */
/*   Updated: 2017/12/19 13:51:56 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_yaxis(t_plc *start, t_plc *end, t_position *line, t_mlx *mlx)
{
	int				e;
	int				slope;
	unsigned int	x;
	unsigned int	y;

	x = start->x_place;
	y = start->y_place;
	e = 2 * line->dx - line->dy;
	if (x < (int)end->x_place)
		slope = 1;
	else
		slope = -1;
	while (y < (int)end->y_place)
	{
		mlx_pixel_put(mlx->mlx, mlx->window, x, y, 0xFFFFFF);
		if (e < 0)
			e += 2 * line->dx;
		else
		{
			x += slope;
			e += 2 * (line->dx - line->dy);
		}
		y++;
	}
}

void	draw_xaxis(t_plc *start, t_plc *end, t_position *line, t_mlx *mlx)
{
	int				e;
	int				slope;
	unsigned int	x;
	unsigned int	y;

	x = start->x_place;
	y = start->y_place;
	e = 2 * line->dy - line->dx;
	if (y < (int)end->y_place)
		slope = 1;
	else
		slope = -1;
	while (x < (int)end->x_place)
	{
		mlx_pixel_put(mlx->mlx, mlx->window, x, y, 0xFFFFFF);
		if (e < 0)
			e += 2 * line->dy;
		else
		{
			y += slope;
			e += 2 * (line->dy - line->dx);
		}
		x++;
	}
}

void	coord_calc(t_plc *start, t_plc *end, t_mlx *mlx)
{
	t_position	*line;

	if (!(line = malloc(sizeof(t_position))))
		return ;
	line->dx = fabs((double)start->x_place - end->x_place);
	line->dy = fabs((double)start->y_place - end->y_place);
	if (line->dx > line->dy)
	{
		if (start->x_place > end->x_place)
			draw_xaxis(end, start, line, mlx);
		else
			draw_xaxis(start, end, line, mlx);
	}
	else
	{
		if (start->y_place > end->y_place)
			draw_yaxis(end, start, line, mlx);
		else
			draw_yaxis(start, end, line, mlx);
	}
}
