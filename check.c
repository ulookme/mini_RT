/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:17:34 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/08 00:53:04 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool_t	check_current(t_object *c, uint8_t *f)
{
	if (c->type == OBJ_A)
		if (!check_amb((t_la *) c->object, f))
			return (1);
	if (c->type == OBJ_C)
		if (!check_cam((t_cam *) c->object, f))
			return (1);
	if (c->type == OBJ_L)
		if (!check_lumiere((t_lum *) c->object, f))
			return (1);
	if (c->type == OBJ_SP)
		if(!check_sphere((t_sphere *) c->object))
			return (1);
	if (c->type == OBJ_PL)
		if (!check_plan((t_plan *) c->object))
			return (1);
	if (c->type == OBJ_CY)
		if (!check_cylindre((t_cylindre *) c->object))
			return (1);
	return (0);
}

bool_t	check_scene(t_object *scene)
{
	t_object	*current;
	uint8_t		flags;

	current = scene;
	while (current)
	{
		if (current->type == OBJ_INVALID)
		{
			printf("Error: Unknown symbol\n");
			return (1);
		}
		if (check_current(current, &flags))
			return (1);
		current = current->next;
	}
	if (flags & 1 << 0 && flags & 1 << 1 && flags & 1 << 2 \
		&& !(flags & 1 << 4) && !(flags & 1 << 5) && !(flags & 1 << 6))
	{
		printf("Valid scene registered\n");
		return (0);
	}
	else if (flags & 1 << 0 && flags & 1 << 1 && flags & 1 << 2)
		printf("Error: Extra Camera and/or Ambiance light and/or Light found\n");
	else
		printf("Error: Missing Camera and / or Ambiance light and/or Light\n");
	return (1);
}