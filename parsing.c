/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 04:24:02 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/09 18:03:37 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/**
 * @brief check_file verifie 
 * extention .rt
 * nb de ficher 
 * si vide
 * @param argc 
 * @param argv 
 * @return int 
 */
int	check_file(int argc, char **argv)
{
	int	len_file;
	int	file;

	if (argc > 2)
	{
		printf("erreur, contient trop de fichiers !\n");
		return (-1);
	}
	if (argc < 2)
	{
		printf("erreur, aucun fichier transmit\n");
		return (-1);
	}
	len_file = ft_strlen(argv[1]);
	if (len_file < 3 || !ft_strnstr(&argv[1][len_file - 3], ".rt", 3))
	{
		printf("le fichier ne contient pas l'extention .rt\n");
		return (-1);
	}
	file = open(argv[1], O_RDONLY);
	if (file < 0)
		printf("erreur , impossible d'ouvire le fichier\n");
	return (file);
}

/**
 * @brief check_open utilise check_file si ok
 * get next_line pour read le fichier 
 * recuperation des element avec element file et leur attribue
 * obj_addback verifie les element ajouter ne sont pas NULL
 * @param argc 
 * @param argv 
 * @return t_object* 
 */
t_object	*check_open(int argc, char **argv)
{
	int			file;
	t_object	*parse_file;
	char		*str;

	parse_file = NULL;
	file = check_file(argc, argv);
	if (file < 0)
		return (NULL);
	str = get_next_line(file);
	while (str)
	{
		obj_addback(&parse_file, element_file(ft_split(str, ' ')));
		free(str);
		str = get_next_line(file);
	}
	free(str);
	return (parse_file);
}

/**
 * @brief element file recherche les element
 * recuperation  des lettrespour la creation des objets
 * @param str 
 * @return t_object* 
 */
t_object	*element_file(char **str)
{
	t_object	*element;

	element = NULL;
	if (!str)
		return (NULL);
	else if (!ft_strncmp(str[0], "A", 2))
		element = parse_lumen(str);
	else if (!ft_strncmp(str[0], "C", 2))
		element = parse_camera(str);
	else if (!ft_strncmp(str[0], "L", 2))
		element = parse_lumiere(str);
	else if (!ft_strncmp(str[0], "sp", 3))
		element = parse_cylindre(str);
	else if (!ft_strncmp(str[0], "pl", 3))
		element = parse_plan(str);
	else if (!ft_strncmp(str[0], "cy", 3))
		element = parse_cylindre(str);
	else if (!is_empty(str))
		element = creat_object(OBJ_INVALID);
	return (element);
}

/**
 * @brief creation des objects type
 * utilise  la fonction malloc_type_object pour le type
 * @param type 
 * @return t_object* 
 */
t_object	*creat_object(int type)
{
	t_object	*object;

	object = malloc(sizeof(t_object));
	if (!object)
		return (NULL);
	object->type = type;
	object->object = NULL;
	object->next = NULL;
	if (malloc_type_object(object, object->type))
		return (object);
	free(object);
	return (NULL);
}

/**
 * @brief malloc_type_object recupere le numero du type 
 * et cree l'object avec la structure de liste qui lui est propre
 * utiliser dans create_object()
 * @param object 
 * @param type 
 * @return t_object* 
 */
t_object	*malloc_type_object(t_object *object, int type)
{
	if (type == OBJ_A)
		object->object = malloc(sizeof(t_la));
	if (type == OBJ_C)
		object->object = malloc(sizeof(t_cam));
	if (type == OBJ_L)
		object->object = malloc(sizeof(t_lum));
	if (type == OBJ_SP)
		object->object = malloc(sizeof(t_sphere));
	if (type == OBJ_PL)
		object->object = malloc(sizeof(t_plan));
	if (type == OBJ_CY)
		object->object = malloc(sizeof(t_cylindre));
	if (type == OBJ_INVALID)
		return (object);
	if (object->object != NULL)
		return (object);
	return (NULL);
}
