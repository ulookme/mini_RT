/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:21:24 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/16 21:35:49 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitr.h"

double	vector_sub(t_v3d v1, t_v3d v2)
{
	return (v1->x - v2->x, v1->y - v2->y, v1->z - v2->z);
}

double	vector_dot(t_v3d v1, t_v3d v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

double	vlength2(t_v3d v1, t_v3d v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double	vlength(t_v3d vec)
{
    return (sqrt(vlength2(vec)));
}

t_v3d	vcross(t_v3d v1, t_v3d v2)
{
    t_v3d new;

    new.x = v1.y * v2.z - v1.z * v2.y;
    new.y = v1.z * v2.x - v1.x * v2.z;
    new.z = v1.x * v2.y - v1.y * v2.x;
    return (new);
}
