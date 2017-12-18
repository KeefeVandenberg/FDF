/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <kvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:43:30 by kvandenb          #+#    #+#             */
/*   Updated: 2017/12/17 17:02:26 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ANGLE 45

# include "minilibx_macos/mlx.h"
# include "unistd.h"
# include "stdlib.h"
# include <fcntl.h>
# include "GNL/libft/libft.h"
# include "GNL/get_next_line.h"
# include "math.h"
#include "stdio.h"

typedef struct      s_plc
{
    struct s_plc    *next;
    struct s_plc    *last;
    int             x;
    int             y;
    int             z;
    int             x_place;
    int             y_place;
}                   t_plc;

typedef struct      s_cam
{
    int             offset_x;
    int             offset_y;
    double          angle_x;
    double          radian_x;
    double          angle_y;
    double          radian_y;
    double          angle_z;
    double          radian_z;
}                   t_cam;

typedef struct      s_rot
{
    double          x0;
	double          x1;
	double          x2;
	double          y0;
	double          y1;
	double          y2;
	double          z0;
	double          z1;
	double          z2;
}                   t_rot;

t_plc *init_plc(void);
t_plc *parse(t_plc *current, char *str, int y, int x);
int main(int argc, char **argv);
int	ft_intlen(int num);
t_plc *find_points(t_cam *cam, t_plc *cur);
t_cam *init_cam(void);

#endif