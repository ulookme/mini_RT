/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 04:21:53 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/11 18:39:32 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief is_empty()
 * verifier si un ligne est vide.
 * @param str 
 * @return t_bool 
 */
t_bool	is_empty(char **str)
{
	int	i;
	int	y;

	i = 0;
	while (str && str[i])
	{
		y = 0;
		while (str[i][y])
			if (!ft_isspace(str[i][y++]))
				return (0);
		i++;
	}
	return (1);
}

/**
 * @brief ajouter des object suivant la list
 * utiliser lors de la cration d'Object
 * verifier mais le declaration de elem se fait dans si *lst existe
 * @param lst 
 * @param insert 
 */
void	obj_addback(t_object **lst, t_object *insert)
{
	t_object	*elem;

	elem = NULL;
	if (*lst)
	{
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

/**
 * @brief parsing camera
 * fonction vecteur 3d pour le view et la pos float
 * fov
 * @param values 
 * @return t_object* 
 */
t_object	*parse_camera(char **values)
{
	t_object	*obj;

	obj = creat_object(OBJ_C);
	if (!obj)
		return (NULL);
	((t_cam *) obj->object)->view.x = NAN;
	if (!(values[1] && values[2] && values[3] && !values[4]))
		return (obj);
	((t_cam *) obj->object)->view = verteur_3d(values[1]);
	((t_cam *) obj->object)->pos = verteur_3d(values[2]);
	((t_cam *) obj->object)->fov = ft_atoi(values[3]);
	return (obj);
}

/**
 * @brief creation object lumiere
 * pos -> vecteur_3d
 * ratio -> float
 * RGB -> color()
 * @param values 
 * @return t_object* 
 */
t_object	*parse_lumiere(char **values)
{
	t_object	*obj;

	obj = creat_object(OBJ_L);
	if (!obj)
		return (NULL);
	((t_lum *) obj->object)->pos.x = NAN;
	if (!(values[1] && values[2] && values[3] && !values[4]))
		return (obj);
	((t_lum *) obj->object)->pos = verteur_3d(values[1]);
	((t_lum *) obj->object)->ratio = ft_atof(values[2]);
	((t_lum *) obj->object)->rgb = color(values[3]);
	return (obj);
}

/**
 * @brief parsing sphere object
 * pos -> vecteur_3d()
 * diametre en float
 * RGB -> color()
 * @param values 
 * @return t_object* 
 */
t_object	*parse_sphere(char **values)
{
	t_object	*obj;

	obj = creat_object(OBJ_SP);
	if (!obj)
		return (NULL);
	if (!(values[1] && values[2] && values[3] && !values[4]))
		return (obj);
	((t_sphere *) obj->object)->pos = verteur_3d(values[1]);
	((t_sphere *) obj->object)->diametre = ft_atof(values[2]);
	((t_sphere *) obj->object)->rgb = color(values[3]);
	return (obj);
}
