/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_process3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:43:29 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/18 19:46:01 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief multiplicateur de vecteur scalaire
 * 
 * @param vec 
 * @param t 
 * @return t_v3d 
 */
t_v3d	vmult(t_v3d vec, double t)
{
    vec.x *= t;
    vec.y *= t;
    vec.z *= t;
    return (vec);
}