/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:51:29 by charleshajj       #+#    #+#             */
/*   Updated: 2023/01/24 12:29:40 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief constructeur de rayon (rayon normalisé)
 * 
 * @param orig 
 * @param dir 
 * @return t_ray 
 */
t_ray	ray(t_point3 orig, t_v3d dir)
{
	t_ray ray;

	ray.orig = orig;
	ray.dir = vunit(dir);
	return (ray);
}

/**
 * @brief Un point éloigné du point d'origine 
 * du rayon par le vecteur de direction 
 * rayon dir * t.
 * 
 * @param ray 
 * @param t 
 * @return t_point3 
 */
t_point3	ray_at(t_ray *ray, double t)
{
    t_point3 at;

    at = vplus(ray->orig, vmult(ray->dir, t));
		return (at);
}
