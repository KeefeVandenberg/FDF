/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvandenb <kvandenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:47:46 by kvandenb          #+#    #+#             */
/*   Updated: 2017/12/07 18:49:47 by kvandenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_plc *init_plc(void)
{
    t_plc *p;

    p = (t_plc *)malloc(sizeof(t_plc));
    p->last = NULL;
    p->next = NULL;
    p->x = 0;
    p->y = 0;
    p->z = 0;
    p->x_place = 0;
    p->y_place = 0;
    return(p);
}