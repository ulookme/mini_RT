/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:43:32 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/16 19:12:33 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_v3d	point(double x, double y, double z)
{
	t_v3d	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_v3d	vec3(double x, double y, double z)
{
	t_v3d	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_rgb	couleur(double r, double g, double b)
{
	t_rgb colors;

    colors.r = r;
    colors.g = g;
    colors.b = b;
    return (colors);
}

void	vset(t_v3d *vec, double x, double y, double z)
{
	vec->x = x;
    vec->y = y;
    vec->z = z;
}