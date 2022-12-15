/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:43:37 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/15 23:16:49 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitrt.h"

t_bool sphere_intersect(t_ray *r, t_sphere *s)
{
	float	a;
	float	b;
	float	c;
	float	discr;
	t_v3d	dist;
	a = vector_dot(&r->dir, &s-dir);
	dist = vector_sub(&r->start, &s->pos);
	b = 2 * vector_dot(&r->dir, &dist);
	c = vector_dot(&dist, &dist) - (s->diametre * s->diametre);
	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (0);
	else
		return (1);
}