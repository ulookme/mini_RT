/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:17:34 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/08 04:04:25 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool_t	check_cam(t_cam *c, uint8_t *f)
{
	(*f) |= 1 << 1;
	if (c->view.x != NAN \
		&& c->pos.x >= 0.f && c->pos.x <= 1.f \
		&& c->pos.y >= 0.f && c->pos.y <= 1.f \
		&& c->pos.z >= 0.f && c->pos.z <= 1.f \
		&& c->fov >= 0 && c->fov <= 180)
		return (1);
	return (0);
}

static bool_t	check_amb(t_la *a, uint8_t *f)
{
	(*f) |= 1 << 0;
	if (a->ratio >= 0.f && a->ration <= 1.f \
		&& a->RGB)
		return (1);
	return (0);
}

static bool_t	check_lumiere(t_lum *l, uint8_t *f)
{
	if(l->pos.x && l->pos.y && l->pos.z \
		&& l->ratio >= 0.f && l->ration <= 1.f \
		&& l->RGB )
		return (1);
	return (0);
}

bool_t	check_scene(t_object *scene)
{
	t_object	*cur;
	uint8_t		flags;

	cur = scene;
	while (cur)
	{
		if (cur->type == OBJ_INVALID)
			return (1);
		if (cur->type == OBJ_A)
			if (!check_amb((t_la *) cur->object, &flags))
				return (1);
		if (cur->type == OBJ_C)
			if (!check_cam((t_cam *) cur->object, &flags))
				return (1);
		if (cur->type == OBJ_L)
			if (!check_lumiere(t_lum *) cur->object)
				return (1);
		cur = cur->next;
	}
	if (flags & 1 << 0 && flags & 1 << 1)
		return (0);
	return (1);
}