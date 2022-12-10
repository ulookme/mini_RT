/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:01:57 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/10 17:08:02 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	clear_scene(t_object *scene)
{
	t_object	*nxt;

	while (scene)
	{
		nxt = scene->next;
		if (scene->object)
			free(scene->object);
		free(scene);
		scene = nxt;
	}
}
