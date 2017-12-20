/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <kvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:24:31 by kvandenb          #+#    #+#             */
/*   Updated: 2017/12/19 16:58:40 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_strsrc(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == '-')
			return (1);
		i++;
	}
	return (-1);
}

int		put_t_plc(t_plc *first, char *str, int y, int x)
{
	t_plc			*new;
	t_plc			*last;

	new = first;
	while (new->next != NULL)
		new = new->next;
	if (!(new->next = (t_plc *)malloc(sizeof(t_plc))))
		return (-1);
	new->x = x;
	new->y = y;
	new->z = ft_atoi(str);
	last = new;
	new = new->next;
	new->next = NULL;
	new->last = last;
	while (str[0] == '\0')
		return (-1);
	return (ft_strsrc(str) ? 1 : -1);
}

t_plc	*parse(t_plc *current, char *str, int y, int x)
{
	unsigned int	i;

	while (!(ft_isdigit(str[0]) || str[0] == '-') && str[0])
		str++;
	if (!(str[0]))
		return (0);
	i = put_t_plc(current, str, y, x);
	if (i == -1)
		return (current);
	else
		while (ft_isdigit(str[0]) || str[0] == '-')
			str++;
	return (parse(current, str, y, x + 1));
}

int		main(int argc, char **argv)
{
	t_read			*read;
	t_plc			*start;
	t_cam			*cam;
	t_all			*all;

	read = init_read();
	start = init_plc();
	cam = init_cam();
	if (argc == 2)
	{
		read->fd = open(argv[1], O_RDONLY);
		while (get_next_line(read->fd, &read->line) != 0)
		{
			parse(start, read->line, read->y++, 0);
			read->line = NULL;
		}
		close(read->fd);
		free(read);
	}
	reinit_cam(cam);
	do_find_points(cam, start);
	all = init_all(cam, start);
	mlx_looper(all);
	return (0);
}
