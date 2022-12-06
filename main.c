/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 04:22:20 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/07 04:22:22 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "minirt.h"

int main(int argc, char **argv)
{
	t_object	*scene;
	
	scene = check_open(argc, argv);
	if (!scene)
		return (1);
	return(0);
}