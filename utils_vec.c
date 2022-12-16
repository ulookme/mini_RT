/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:43:32 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/16 22:24:38 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/**
 * @brief constructeur point 3
 * 
 * @param x 
 * @param y 
 * @param z 
 * @return t_v3d 
 */
t_v3d	point(double x, double y, double z)
{
	t_v3d	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

/**
 * @brief constructeur vector
 * 
 * @param x 
 * @param y 
 * @param z 
 * @return t_v3d 
 */
t_v3d	vec3(double x, double y, double z)
{
	t_v3d	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

/**
 * @brief constructeur color
 * 
 * @param r 
 * @param g 
 * @param b 
 * @return t_v3d 
 */
t_v3d	couleur(double r, double g, double b)
{
	t_rgb colors;

    colors.r = r;
    colors.g = g;
    colors.b = b;
    return (colors);
}

/**
 * @brief ensemble de valeurs vectorielles
 * 
 * @param vec 
 * @param x 
 * @param y 
 * @param z 
 */
void	vset(t_v3d *vec, double x, double y, double z)
{
	vec->x = x;
    vec->y = y;
    vec->z = z;
}

/**
 * @brief Division scalaire vectorielle
 * 
 * @param vec 
 * @param t 
 * @return t_vec3 
 */
t_v3d	vdivide(t_v3d vec, double t)
{
    vec.x *= 1 / t;
    vec.y *= 1 / t;
    vec.z *= 1 / t;

    return (vec);
}
