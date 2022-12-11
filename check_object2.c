/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:18:41 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/11 18:31:12 by charleshajj      ###   ########.fr       */
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
		&& p->rgb && p->diametre != NAN && p->hauteur != NAN)
		return (1);
	printf("Error: Invalid Cylinder Settings\n");
	return (0);
}
