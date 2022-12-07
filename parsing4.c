/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 07:43:30 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/08 10:06:51 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object *parse_plan(char **values)
{
	t_object *obj;

	obj = creat_object(OBJ_PL);
	if (!obj)
		return (NULL);
	((t_plan *) obj->object)->view.x = NAN;
	if (!(values[1] && values[2] && values[3] && !values[4]))
		return (obj);
	((t_plan *) obj->object)->view = verteur_3d(values[1]);
	((t_plan *) obj->object)->pos = verteur_3d(values[2]);
	((t_plan *) obj->object)->RGB = color(values[3]);
	return (obj);
}

t_object *parse_cylindre(char **values)
{
	t_object *obj;

	obj = creat_object(OBJ_CY);
	if (!obj)
		return (NULL);
	((t_cylindre *) obj->object)->view.x = NAN;
	if (!(values[1] && values[2] && values[3] \
		&& values[4] && values[5] && !values[6]))
		return (obj);
	((t_cylindre *) obj->object)->view = verteur_3d(values[1]);
	((t_cylindre *) obj->object)->pos = verteur_3d(values[2]);
	((t_cylindre *) obj->object)->diametre = ft_atof(values[3]);
	((t_cylindre *) obj->object)->hauteur = ft_atof(values[4]);
	((t_cylindre *) obj->object)->RGB = color(values[5]);
	return (obj);
}

