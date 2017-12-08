/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <kvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:24:31 by kvandenb          #+#    #+#             */
/*   Updated: 2017/12/07 19:34:28 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_plc *parse(t_plc *current, char *str, int y, int x)
{
	t_plc *new;
	t_plc *last;

	new = current;
	while (new->next)
		new = new->next;
	while (str[0] != '\0' && ((str[0] >= '0' && str[0] <= '9') || str[0] == ' '))
	{
		while(str[0] >= '0' && str[0] <= '9')
			str++;		
		while(str[0] == ' ')
			str++;
		if(!(new->next = (t_plc *)malloc(sizeof(t_plc))))
			return (0);
		new->x = x++;
		new->y = y;
		new->z = ft_atoi(str);
		printf("x = %d y = %d z = %d\n\n", new->x, y, ft_atoi(str));
		last = new;
		new = new->next;
		new->last = last;
	}
	return (current);
}

int main(int argc, char **argv)
{
	int fd;
	char *line;
	t_plc *start;
	int y;

	y = 0;
	start = init_plc();
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line))
		{
			parse(start, line, y, 0);
			y++;
			line = NULL;
		}
	}
	return (0);
}
