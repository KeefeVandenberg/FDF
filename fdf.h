/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <kvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:43:30 by kvandenb          #+#    #+#             */
/*   Updated: 2017/12/19 17:02:46 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define PI 3.14159265359
# define HEIGHT 1000
# define WIDTH 1000

# include "minilibx_macos/mlx.h"
# include "unistd.h"
# include "stdlib.h"
# include <fcntl.h>
# include "GNL/libft/libft.h"
# include "GNL/get_next_line.h"
# include "math.h"

typedef struct		s_plc
{
	struct s_plc	*next;
	struct s_plc	*last;
	unsigned int	x;
	unsigned int	y;
	int				z;
	int				x_place;
	int				y_place;
}					t_plc;

typedef struct		s_position
{
	double			dx;
	double			dy;
}					t_position;

typedef struct		s_cam
{
	double			angle_x;
	double			radian_x;
	double			angle_y;
	double			radian_y;
	double			angle_z;
	double			radian_z;
	double			scaling;
}					t_cam;

typedef struct		s_rot
{
	double			x0;
	double			x1;
	double			x2;
	double			y0;
	double			y1;
	double			y2;
	double			z0;
	double			z1;
	double			z2;
}					t_rot;

typedef struct		s_mlx
{
	void			*mlx;
	void			*window;
}					t_mlx;

typedef struct		s_all
{
	struct s_plc	*head;
	struct s_cam	*cam;
	struct s_mlx	*mlx;
}					t_all;

typedef struct		s_read
{
	int				fd;
	char			*line;
	int				y;
}					t_read;

t_plc				*init_plc(void);
t_plc				*parse(t_plc *current, char *str, int y, int x);
int					main(int argc, char **argv);
int					ft_intlen(int num);
t_plc				*do_find_points(t_cam *cam, t_plc *cur);
t_cam				*init_cam(void);
t_cam				*reinit_cam(t_cam *camera);
void				mlx_looper(t_all *all);
t_all				*init_all(t_cam *cam, t_plc *head);
t_plc				*find_points(t_cam *cam, t_plc *current);
void				ft_exit(int i, t_all *all);
int					draw(t_all *all);
void				coord_calc(t_plc *start, t_plc *end, t_mlx *mlx);
t_mlx				*init_mlx(void);
t_plc				*free_plc(t_plc *current);
t_read				*init_read(void);
t_plc				*find_struct(t_plc *head, int x_cord, int y_cord);

#endif
