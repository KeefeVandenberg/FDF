/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <kvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 18:31:30 by kvandenb          #+#    #+#             */
/*   Updated: 2017/12/19 16:45:23 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		redraw(t_all *all)
{
	do_find_points(all->cam, all->head);
	mlx_clear_window(all->mlx->mlx, all->mlx->window);
	draw(all);
	return (0);
}

int		hook_keydown(int key, t_all *all)
{
	int i;

	if (key == 53)
		ft_exit(1, all);
	if (key == 13)
		all->cam->angle_x += .01;
	if (key == 1)
		all->cam->angle_x -= .01;
	if (key == 2)
		all->cam->angle_y += .01;
	if (key == 0)
		all->cam->angle_y -= .01;
	redraw(all);
	return (0);
}

void	mlx_looper(t_all *al)
{
	t_plc *found;
	t_plc *use;
	t_all *all;

	all = al;
	use = all->head;
	all->mlx->mlx = mlx_init();
	all->mlx->window = mlx_new_window(all->mlx->mlx, WIDTH, HEIGHT, "fdf");
	draw(all);
	mlx_key_hook(all->mlx->window, hook_keydown, all);
	mlx_loop(all->mlx->mlx);
}
