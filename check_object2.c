/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:18:41 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/15 18:36:27 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief check cylindre verif que les conditions de scene sont remplie.
 * sinon message d'erreur.
 * @param p 
 * @return t_bool
 */
t_bool	check_cylindre(t_cylindre *p)
{
	if (p->view.x != NAN \
		&& p->pos.x >= -1.f && p->pos.x <= 1.f \
		&& p->pos.y >= -1.f && p->pos.y <= 1.f \
		&& p->pos.z >= -1.f && p->pos.z <= 1.f \
		&& p->diametre != NAN && p->hauteur != NAN \
		&& p->rgb.r >= 0 && p->rgb.r <= 255 \
		&& p->rgb.g >= 0 && p->rgb.g <= 255 \
		&& p->rgb.b >= 0 && p->rgb.b <= 255)
		return (1);
	printf("Error: Invalid Cylinder Settings\n");
	return (0);
}

t_bool	check_color(t_rgb *rgb)
{
	if ((rgb->r <= 255 && rgb->r >= 0) && \
		(rgb->g <= 255 && rgb->g >= 0) \
		&& (rgb->b <= 255 && rgb->b >= 0))
		return (1);
	printf("Error: Invalid range color RGB\n");
	return (0);
}
