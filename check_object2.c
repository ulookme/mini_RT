/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:18:41 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/08 09:33:55 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool_t	check_cylindre(t_cylindre *p)
{
	if (p->view.x != NAN \
		&& p->pos.x >= -1.f && p->pos.x <= 1.f \
		&& p->pos.y >= -1.f && p->pos.y <= 1.f \
		&& p->pos.z >= -1.f && p->pos.z <= 1.f \
		&& p->RGB && p->diametre != NAN && p->hauteur != NAN)
		return (1);
	printf("Error: Invalid Cylinder Settings\n");
	return (0);
}