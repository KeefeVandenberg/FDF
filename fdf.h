/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <kvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:43:30 by kvandenb          #+#    #+#             */
/*   Updated: 2017/12/07 19:02:32 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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

t_plc *init_plc(void);
t_plc *parse(t_plc *current, char *str, int y, int x);
int main(int argc, char **argv);

#endif