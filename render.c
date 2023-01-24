/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:13:12 by cdescour          #+#    #+#             */
/*   Updated: 2023/01/16 11:55:13 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	render(t_object *scene)
{	
	Creer une liste des cameras.
	Pour chacunes des cameras:
		Creer un tableau (IMG_SIZE_X * IMG_SIZE_Y) contenant les variables du rendu.
		Pour chacun des points:
			trouver l'element le plus proche devant
			indiquer sa position, l'orientation de sa facette, sa couleur, son id,
			la luminosite ambiante.
			Pour chacune des lumieres:
		   		verifier si il est possible d'augmenter la luminausite ambiante.
		Creer le tableau de rendu de la camera.
	enregistrer les rendus finaux.`
}
