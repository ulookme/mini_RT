/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:21:24 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/16 22:16:21 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitr.h"

/**
 * @brief différence vectorielle
 * 
 * @param v1 
 * @param v2 
 * @return double 
 */
double	vector_sub(t_v3d v1, t_v3d v2)
{
	return (v1->x - v2->x, v1->y - v2->y, v1->z - v2->z);
}

/**
 * @brief produit scalaire vectoriel
 * 
 * @param v1 
 * @param v2 
 * @return double 
 */
double	vector_dot(t_v3d v1, t_v3d v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

/**
 * @brief longueur du vecteur au carré
 * 
 * @param v1 
 * @param v2 
 * @return double 
 */
double	vlength2(t_v3d v1, t_v3d v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

/**
 * @brief longueur du vecteur
 * 
 * @param vec 
 * @return double 
 */
double	vlength(t_v3d vec)
{
    return (sqrt(vlength2(vec)));
}

/**
 * @brief produit croisé vectoriel
 * 
 * @param v1 
 * @param v2 
 * @return t_v3d 
 */
t_v3d	vcross(t_v3d v1, t_v3d v2)
{
    t_v3d new;

    new.x = v1.y * v2.z - v1.z * v2.y;
    new.y = v1.z * v2.x - v1.x * v2.z;
    new.z = v1.x * v2.y - v1.y * v2.x;
    return (new);
}
