/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 04:21:53 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/08 10:04:59 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool_t  is_empty(char **str)
{
	int i = 0;
	int y;

	while(str && str[i])
	{
		y = 0;
		while(str[i][y])
			if (!ft_isspace(str[i][y++]))
				return (0);
		i++;

	}
	return (1);
}

void    obj_addback(t_object **lst, t_object *insert)
{
	if (*lst)
	{
		t_object	*elem;

		if (lst == NULL)
			return ;
		elem = *lst;
		while (elem->next != NULL)
			elem = elem->next;
		elem->next = insert;
	}
	else
		*lst = insert;
}

t_object *parse_camera(char **values)
{
	t_object *obj;

	obj = creat_object(OBJ_C);
	if(!obj)
		return (NULL);
	((t_cam *) obj->object)->view.x = NAN;
	if (!(values[1] && values[2] && values[3] && !values[4]))
		return (obj);
	((t_cam *) obj->object)->view = verteur_3d(values[1]);
	((t_cam *) obj->object)->pos = verteur_3d(values[2]);
	((t_cam *) obj->object)->fov = ft_atoi(values[3]);
	return(obj);
}

t_object *parse_lumiere(char **values)
{
	t_object *obj;

	obj = creat_object(OBJ_L);
	if (!obj)
		return (NULL);
	((t_lum *) obj->object)->pos.x = NAN;
	if (!(values[1] && values[2] && values[3] && !values[4]))
		return (obj);
	((t_lum *) obj->object)->pos = verteur_3d(values[1]);
	((t_lum *) obj->object)->ratio = ft_atof(values[2]);
	((t_lum *) obj->object)->RGB = color(values[3]);
	return (obj);
}

t_object *parse_sphere(char ** values)
{
	t_object *obj;

	obj = creat_object(OBJ_SP);
	if (!obj)
		return (NULL);
	if (!(values[1] && values[2] && values[3] && !values[4]))
		return (obj);
	((t_sphere *) obj->object)->pos = verteur_3d(values[1]);
	((t_sphere *) obj->object)->diametre = ft_atof(values[2]);
	((t_sphere *) obj->object)->RGB = color(values[3]);
	return (obj);
}
