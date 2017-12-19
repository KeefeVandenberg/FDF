/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <kvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:20:15 by bhalderm          #+#    #+#             */
/*   Updated: 2017/12/18 19:56:41 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    draw_horizon(int y_base, int x1, int x2, t_mlx *mlx)
{
    while (x1 <= x2)
    {
        mlx_pixel_put(mlx->mlx, mlx->window, x1, y_base, 0xFFFFFF);
        x1++;
    }
}

void    draw_vertic(int x_base, int y1, int y2, t_mlx *mlx)
{
    while (y1 <= y2)
    {
        mlx_pixel_put(mlx->mlx, mlx->window, x_base, y1, 0xFFFFFF);
        y1++;
    }
}

void    generate(int x1, int x2, int y1, int y2, t_mlx *mlx)
{
    int sx;
    int sy;
    int e;

    sx = x2 - x1;
    sy = y2 - y1;
    e = sy - sx;

    while (x1 <= x2)
    {
        //mlx_pixel_put(mlx->mlx, mlx->window, x1, y1, 0xFFFFFF);
        if (e >= 0)
        {
            y1 += 1;
            e += sx;
        }
        else
            e -= sy;
        x1++;
    }
}

void    coord_calc(t_plc *start, t_plc *end, t_mlx *mlx)
{
    if (start->x_place == end->x_place)
        draw_vertic(start->x_place, start->y_place, end->y_place, mlx);
    if (start->y_place == end->y_place)
        draw_horizon(start->y_place, start->x_place, end->x_place, mlx);
    else
        generate(start->x_place, start->y_place, end->x_place, end->y_place, mlx);
}