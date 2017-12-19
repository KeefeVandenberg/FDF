/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <kvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:53:59 by kvandenb          #+#    #+#             */
/*   Updated: 2017/12/18 19:56:04 by kvandenb         ###   ########.fr       */
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

t_plc *find_struct(t_plc *head, int x_cord, int y_cord)
{
	t_plc *new;

	new = head;
	if (!(x_cord >= 0 || y_cord >= 0))
		return(NULL);
	while(new->next)
	{
		if (new->x == x_cord && new->y == y_cord)
			return(new);
		new = new->next;
	}
	return(NULL);
}

t_plc *do_find_points(t_cam *cam, t_plc *current)
{
	t_plc *header;
	t_plc *last;

	header = current;
	while(header->next != NULL)
	{
		header = find_points(cam, header);
		last = header;
		header = header->next;
		header->last = last;
	}
	header = find_points(cam, header);
	return (current);
}

t_plc *find_points(t_cam *cam, t_plc *current)
{
	t_rot *alg;
	t_plc *cur;

	cur = current;
	alg = (t_rot *)malloc(sizeof(t_rot));
	alg->x0 = cur->x;
	alg->y0 = (cur->y * cos(cam->angle_x)) + (cur->z * sin(cam->angle_x));
	alg->z0 = (cur->z * cos(cam->angle_x)) - (cur->y * sin(cam->angle_x));
	alg->x1 = (alg->x0 * cos(cam->angle_y)) - (alg->z0 * sin(cam->angle_y));
	alg->y1 = alg->y0;
	alg->z1 = (alg->z0 * cos(cam->angle_y)) + (alg->x0 * sin(cam->angle_y));
	alg->x2 = (alg->x1 * cos(cam->angle_z)) + (alg->y1 * sin(cam->angle_z));
	alg->y2 = (alg->y1 * cos(cam->angle_z)) - (alg->x1 * sin(cam->angle_z));
	alg->x2 *= 20;
	alg->y2 *= 20;
	alg->x2 += 200;
	alg->y2 += 200;
	cur->x_place = (int)alg->x2;
	cur->y_place = (int)alg->y2;
	free(alg);
	return (cur);
}

int draw(t_all *all)
{
	t_plc 	*a;
	t_plc	*down;
	int 	x[1];
	int		y[1];

	a = all->head;
	down = find_struct(a, a->x, a->y + 1);
	while (a->next)
	{
		if(down->next != NULL && (down->next->x > down->x))
			coord_calc(a, down, all->mlx);	
		if(a->next && (a->next->x > a->x))
			coord_calc(a, a->next, all->mlx);
		if(a->next != NULL)
			a = a->next;
		if (down->next != NULL)
			down = down->next;
	}
	return(0);
}

void ft_exit(int i)
{
	if (i == 1)
	{
		ft_putstr("EXITED PROGRAM SUCCESSFULLY");
	}
	else
		ft_putstr("ERROR");
	exit(1);
}