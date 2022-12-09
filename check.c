/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:17:34 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/09 15:09:44 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief verification du type d'objet A C L SP CY .
 *  Activation de la fonction check lier a l'element.
 * @param c 
 * @param f 
 * @return bool_t 
 */
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
		if (!check_sphere((t_sphere *) c->object))
			return (1);
	if (c->type == OBJ_PL)
		if (!check_plan((t_plan *) c->object))
			return (1);
	if (c->type == OBJ_CY)
		if (!check_cylindre((t_cylindre *) c->object))
			return (1);
	return (0);
}

/**
 * @brief ckeck_scene verifie si tout est ok sur la scene 
 * envoyer que tout est au norme.
 * utilise check current et check flag.
 * @param scene 
 * @return bool_t 
 */
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
	if (check_flag(&flags))
		return (0);
	return (1);
}

/**
 * @brief check flag operation binaire pour verifier 
 * que la camera est la lumiere sont utiliser une fois dans le fichier .rt
 * @param f 
 * @return bool_t 
 */
bool_t	check_flag(uint8_t *f)
{
	if ((*f) & 1 << 0 && (*f) & 1 << 1 && (*f) & 1 << 2 \
		&& !((*f) & 1 << 4) && !((*f) & 1 << 5) && !((*f) & 1 << 6))
	{
		printf("Valid scene registered\n");
		return (0);
	}
	else if ((*f) & 1 << 0 && (*f) & 1 << 1 && (*f) & 1 << 2)
		printf("Error: Extra Camera and/or Ambiance light and/or Light found\n");
	else
		printf("Error: Missing Camera and / or Ambiance light and/or Light\n");
	return (1);
}
