/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 04:14:06 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/08 00:51:30 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool_t	check_amb(t_la *a, uint8_t *f)
{
	if ((*f) & 1 << 0)
		(*f) |= 1 << 4;
	(*f) |= 1 << 0;
	if (a->ratio >= 0.f && a->ratio <= 1.f \
		&& a->RGB)
		return (1);
	printf("Error: Invalid Ambiance Settings\n");
	return (0);
}

bool_t	check_cam(t_cam *c, uint8_t *f)
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

bool_t	check_lumiere(t_lum *l, uint8_t *f)
{
	if ((*f) & 1 << 2)
		(*f) |= 1 << 6;
	(*f) |= 1 << 2;
	if(l->pos.x != NAN && l->pos.y != NAN && l->pos.z != NAN \
		&& l->ratio >= 0.f && l->ratio <= 1.f \
		&& l->RGB )
		return (1);
	printf("Error: Invalid Light Settings\n");
	return (0);
}

bool_t	check_sphere(t_sphere *s)
{
	if(s->pos.x != NAN && s->pos.y != NAN && s->pos.z != NAN \
		&& s->RGB && s->diametre)
		return (1);
	printf("Error: Invalid Sphere Settings\n");
	return (0);
}

bool_t	check_plan(t_plan *p)
{
	if (p->view.x != NAN \
		&& p->pos.x >= -1.f && p->pos.x <= 1.f \
		&& p->pos.y >= -1.f && p->pos.y <= 1.f \
		&& p->pos.z >= -1.f && p->pos.z <= 1.f \
		&& p->RGB)
		return (1);
	printf("Error: Invalid Plan Settings\n");
	return(0);
}