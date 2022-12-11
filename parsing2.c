/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 04:21:45 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/11 19:11:16 by charleshajj      ###   ########.fr       */
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
unsigned int	color(char *value)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(value, ',');
	if (!rgb)
		return (0);
	if (!(rgb[0] && rgb[1] && rgb[2] && !rgb[3]))
	{
		free_array(rgb);
		return (0);
	}
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_array(rgb);
	if ((r <= 255 && r >= 0) && (g <= 255 && g >= 0) && (b <= 255 && b >= 0))
		return ((r << 24) + (g << 16) + (b << 8) + 0xFF);
	return (0);
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
