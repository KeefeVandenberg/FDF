/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <kvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:53:59 by kvandenb          #+#    #+#             */
/*   Updated: 2017/12/16 19:02:21 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		higher_nums(int num)
{
	if (num >= 10000000)
	{
		if (num >= 1000000000)
			return (10);
		if (num >= 100000000)
			return (9);
		return (8);
	}
	if (num >= 1000000)
		return (7);
	return (6);
}

int		ft_intlen(int num)
{
	if (num >= 100000)
		return (higher_nums(num));
	else
	{
		if (num >= 1000)
		{
			if (num >= 10000)
				return (5);
			return (4);
		}
		else
		{
			if (num >= 100)
				return (3);
			if (num >= 10)
				return (2);
		}
		return (1);
	}
}

int find_struct(t_plc *head, int x_cord, int y_cord, char c)
{
	t_plc *new;

	new = head;
	if (!(x_cord >= 0 || y_cord >= 0))
		return(-1);
	while(new->next)
	{
		if (new->x == x_cord && new->y == y_cord)
			return(new->z);
		new = new->next;
	}
	return(-1);
}

int find_points(int x, int y, int z, t_cam *cam, t_plc current)
{
	t_rot *alg;

	alg = (*t_rot)malloc(sizeof(t_rot));
	alg->x0 = x;
	alg->y0 = (y * cos(cam->angle_x)) + (z * sin(cam->angle_x));
	alg->z0 = (z * cos(cam->angle_x)) - (y * sin(cam->angle_x));
	alg->x1 = (alg->x0 * cos(cam->angle_y)) - (alg->z0 * sin(cam->angle_y));
	alg->y1 = alg->y0;
	alg->z1 = (alg->z0 * cos(cam->angle_y)) + (alg->x0 * sin(cam->angle_y));
	alg->x2 = (alg->x1 * cos(cam->angle_z)) + (alg->y1 * sin(cam->angle_z));
	alg->y2 = (alg->y1 * cos(cam->angle_z)) - (alg->x1 * sin(cam->angle_z));
	current->x_place = alg->x2;
	current->y_place = alg->y2;
	return (current);
}