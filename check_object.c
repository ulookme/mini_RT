/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 04:14:06 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/15 18:27:51 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/**
 * @brief check_amb() verifie la lumiere ambiante et propriéte lier a elle
 * ratio dans le range [0.0,1.0]
 * R,G,B dans le range [0-255]
 * @param a 
 * @param f 
 * @return t_bool
 */
t_bool	check_amb(t_la *a, uint8_t *f)
{
	if ((*f) & 1 << 0)
		(*f) |= 1 << 4;
	(*f) |= 1 << 0;
	if (a->ratio >= 0.f && a->ratio <= 1.f \
		&& a->rgb.r >= 0 && a->rgb.r <= 255 \
		&& a->rgb.g >= 0 && a->rgb.g <= 255 \
		&& a->rgb.b >= 0 && a->rgb.b <= 255)
		return (1);
	printf("Error: Invalid Ambiance Settings\n");
	return (0);
}

/**
 * @brief check_cam verifi les proprieter de la camera
 * coordonnées x,y,z view float.
 * Vecteur d’orientation 3d (c.pos) dans lerange[-1,1] 
 * fov Champ de vision horizontal en degrés entre [0,180]
 * @param c 
 * @param f 
 * @return t_bool
 */
t_bool	check_cam(t_cam *c, uint8_t *f)
{
	if ((*f) & 1 << 1)
		(*f) |= 1 << 5;
	(*f) |= 1 << 1;
	if (c->view.x != NAN \
		&& c->pos.x >= 0.f && c->pos.x <= 1.f \
		&& c->pos.y >= 0.f && c->pos.y <= 1.f \
		&& c->pos.z >= 0.f && c->pos.z <= 1.f \
		&& c->fov >= 0 && c->fov <= 180)
		return (1);
	printf("Error: Invalid Camera Settings\n");
	return (0);
}

/**
 * @brief verifier la lumiere
 * pos : coordonnées x,y,z du point Lumière float
 * ratio:  lumnosité dans le range [0.0,1.0]
 * RGB :  range [0- 255]
 * @param l 
 * @param f 
 * @return t_bool
 */
t_bool	check_lumiere(t_lum *l, uint8_t *f)
{
	if ((*f) & 1 << 2)
		(*f) |= 1 << 6;
	(*f) |= 1 << 2;
	if (l->pos.x != NAN && l->pos.y != NAN && l->pos.z != NAN \
		&& l->ratio >= 0.f && l->ratio <= 1.f \
		&& l->rgb.r >= 0 && l->rgb.r <= 255 \
		&& l->rgb.g >= 0 && l->rgb.g <= 255 \
		&& l->rgb.b >= 0 && l->rgb.b <= 255)
		return (1);
	printf("Error: Invalid Light Settings\n");
	return (0);
}

/**
 * @brief figure sphere et condition
 * pos: coordonnées x,y,z du point sphere en float
 * diameter: float
 * RGB :  range [0-255]
 * @param s 
 * @return t_bool 
 */
t_bool	check_sphere(t_sphere *s)
{
	if (s->pos.x != NAN && s->pos.y != NAN && s->pos.z != NAN \
		&& s->diametre && s->rgb.r >= 0 && s->rgb.r <= 255 \
		&& s->rgb.g >= 0 && s->rgb.g <= 255 \
		&& s->rgb.b >= 0 && s->rgb.b <= 255)
		return (1);
	printf("Error: Invalid Sphere Settings\n");
	return (0);
}

/**
 * @brief check_plan condition verif
 * view: coordonnées x,y,z
 * pos : vecteur d’orientation 3d range [-1,1]
 * RGB : range [0-255]
 * @param p 
 * @return t_bool
 */
t_bool	check_plan(t_plan *p)
{
	if (p->view.x != NAN \
		&& p->pos.x >= -1.f && p->pos.x <= 1.f \
		&& p->pos.y >= -1.f && p->pos.y <= 1.f \
		&& p->pos.z >= -1.f && p->pos.z <= 1.f \
		&& p->rgb.r >= 0 && p->rgb.r <= 255 \
		&& p->rgb.g >= 0 && p->rgb.g <= 255 \
		&& p->rgb.b >= 0 && p->rgb.b <= 255)
		return (1);
	printf("Error: Invalid Plan Settings\n");
	return (0);
}
