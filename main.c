/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 04:22:20 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/15 23:38:03 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(int argc, char *argv){
	
	/* Our ray and a sphere */
	sphere s;
	ray r;
	
	/* x, y for screen 'resolution' */
	int x,y;	

	/* Intersect ray/sphere or not */
	bool hit;

	/* Position the sphere */
	s.pos.x = 20;
	s.pos.y = 20;
	s.pos.z = 20;

	/* Sphere radius */
	s.radius = 10;

	/* Direction of the ray */
	r.dir.x = 0;
	r.dir.y = 0;
	r.dir.z = 1;

	/* Start position of the ray, z coordinate */
	r.start.z = 0;

	/* Iterate over every 'pixel' of our screen
	 * We use a 40x40 virtual ASCII screen for now
	 */
	for(y=0;y<40;y++){
		/* Set the y-coordinate of the start position of the ray */
		r.start.y = y; 
		for(x=0;x<40;x++){
			/* Set the x-coordinate of the start position of the ray */
			r.start.x = x;

			/* Check if the ray intersects with the shpere */
			hit = intersectRaySphere(&r, &s);
			if(hit)
				printf("++");
			else
				printf("--");
		}
		/* First row of the screen done, move to next row */
		printf("\n");
	}

}

/**
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