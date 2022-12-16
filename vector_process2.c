/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_process2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:16:12 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/16 21:38:23 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_v3d	vplus(t_v3d v1, t_v3d v2)
{
    v1.x += v2.x;
    v1.y += v2.y;
    v1.z += v2.z;
    return (v1);
}

t_v3d	vminus(t_v3d v1, t_v3d v2)
{
    v1.x -= v2.x;
    v1.y -= v2.y;
    v1.z -= v2.z;
    return (v1);
}

t_v3d	vmult_(t_v3d v1, t_v3d v2)
{
    v1.x *= v2.x;
    v1.y *= v2.y;
    v1.z *= v2.z;
    return (v1);
}


t_v3d	vunit(t_v3d v1)
{
	double	len;

	len = vlength(v1);
    if (len == 0)
    {
        printf("Error\n:Devider is 0");
        exit(0);
    }
    v1.x /= len;
    v1.y /= len;
    v1.z /= len;
    return (v1);
}

t_v3d	vmin(t_v3d v1, t_v3d v2)
{
    if (v1.x > v2.x)
        v1.x = v2.x;
    if (v1.y > v2.y)
        v1.y = v2.y;
    if (v1.z > v2.z)
        v1.z = v2.z;
    return (v1);
}
