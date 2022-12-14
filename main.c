/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 04:22:20 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/16 18:42:49 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_object	*scene;

	scene = check_open(argc, argv);
	if (!scene)
	{
		printf("Error: Memory allocation failed\n");
		return (1);
	}
	if (!check_scene(scene))
		;
	clear_scene(scene);
	return (0);
}