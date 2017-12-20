/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <kvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:35:57 by kvandenb          #+#    #+#             */
/*   Updated: 2017/12/19 16:59:09 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit(int i, t_all *all)
{
	free_plc(all->head);
	free(all->cam);
	free(all->mlx);
	free(all);
	if (i == 1)
		ft_putstr("EXITED PROGRAM SUCCESSFULLY\n");
	else
		ft_putstr("ERROR");
	exit(1);
}

t_mlx	*init_mlx(void)
{
	t_mlx *p;

	p = (t_mlx *)malloc(sizeof(t_mlx));
	return (p);
}

t_plc	*find_struct(t_plc *head, int x_cord, int y_cord)
{
	t_plc *new;

	new = head;
	if (!(x_cord >= 0 || y_cord >= 0))
		return (NULL);
	while (new->next)
	{
		if (new->x == x_cord && new->y == y_cord)
			return (new);
		new = new->next;
	}
	return (NULL);
}

t_plc	*free_plc(t_plc *current)
{
	int				i;

	i = 0;
	while (current->next)
	{
		current = current->next;
		i++;
	}
	while (current->last)
	{
		free(current->next);
		current = current->last;
	}
	free(current);
	return (current);
}
