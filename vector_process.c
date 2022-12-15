/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:21:24 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/15 19:43:59 by charleshajj      ###   ########.fr       */
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

