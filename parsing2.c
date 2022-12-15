/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 04:21:45 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/15 18:34:28 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief free_array 
 * libere la memoire des liste d'objet
 * @param str 
 */
void	free_array(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free (str[i]);
	free(str);
}

/**
 * @brief color
 * la fonction recupere les données des structure comportant 
 * les element RGB entre range [0-255]
 * @param value 
 * @return unsigned int 
 */
t_rgb	color(char *value)
{
	char	**elem;
	t_rgb	rgb;

	elem = ft_split(value, ',');
	rgb.r = NAN;
	if (!elem)
		return (rgb);
	if (!(elem[0] && elem[1] && elem[2] && !elem[3]))
	{
		free_array(elem);
		return (rgb);
	}
	rgb.r = ft_atoi(elem[0]);
	rgb.g = ft_atoi(elem[1]);
	rgb.b = ft_atoi(elem[2]);
	free_array(elem);
	return (rgb);
}

/**
 * @brief parse_lumen verifie les donner pour la cration de l'objet
 * ratio en en float
 * RGB utilise la fonction color qui verifie les condition de validation.
 * @param values 
 * @return t_object* 
 */
t_object	*parse_lumen(char **values)
{
	t_object	*obj;

	obj = creat_object(OBJ_A);
	if (!obj)
		return (NULL);
	((t_la *) obj->object)->ratio = NAN;
	if (!(values[1] && values[2] && !values[3]))
		return (obj);
	((t_la *) obj->object)->ratio = ft_atof(values[1]);
	((t_la *) obj->object)->rgb = color(values[2]);
	return (obj);
}

/**
 * @brief veteur 3d x y z
 * parsing data vecteur pour les point de vue et les positions.
 * sera utiliser par les structure au nom de view et de pos float.
 * @param value 
 * @return t_v3d 
 */
t_v3d	verteur_3d(char *value)
{
	char	**elem;
	t_v3d	vec;

	elem = ft_split(value, ',');
	vec.x = NAN;
	if (!elem)
		return (vec);
	if (!(elem[0] && elem[1] && elem[2] && !elem[3]))
	{
		free_array(elem);
		return (vec);
	}
	vec.x = ft_atof(elem[0]);
	vec.y = ft_atof(elem[1]);
	vec.z = ft_atof(elem[2]);
	free_array(elem);
	return (vec);
}
