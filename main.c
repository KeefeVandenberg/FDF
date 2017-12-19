/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <kvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:24:31 by kvandenb          #+#    #+#             */
/*   Updated: 2017/12/18 19:20:45 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int put_t_plc(t_plc *first, char *str, int y, int x)
{
	t_plc *new;
	t_plc *last;

	new = first;
	while(new->next != NULL)
		new = new->next;
	if(!(new->next = (t_plc *)malloc(sizeof(t_plc))))
		return (-1);
	new->x = x;
	new->y = y;
	new->z = ft_atoi(str);
	last = new;
	new = new->next;
	new->next = NULL;
	new->last = last;
	if (str[0] == '\0')
		return (-1);	
	return (ft_intlen(ft_atoi(str)));
}

t_plc *parse(t_plc *current, char *str, int y, int x)
{
	static int i;
	
	if (!(str[0]))
		return (0);
	while(!(ft_isdigit(str[0]) || str[0] == '-'))
		str++;
	i = put_t_plc(current, str, y, x);
	if (i == -1)
		return (current);
	else
		while(ft_isdigit(str[0]) || str[0] == '-')
			str++;
	return (parse(current, str, y, x + 1));
}

t_plc *free_plc(t_plc *current)
{
	int i;

	i = 0;
	while(current->next)
	{
		current = current->next;
		i++;
	}
	while(current->last)
	{
		free(current->next);
		current = current->last;
	}
	free(current);
	return (current);
}


int main(int argc, char **argv)
{
	int fd;
	char *line;
	t_plc *start;
	t_cam *cam;
	t_all *fatcunt;
	int y;

	y = 0;
	start = init_plc();
	cam = init_cam();
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) != 0)
		{
			parse(start, line, y++, 0);
			line = NULL;
		}
		close(fd);
	}
	reinit_cam(cam);
	do_find_points(cam, start);
	fatcunt = init_all(cam, start);
	mlx_looper(fatcunt);
	free_plc(start);
	return (0);
}
