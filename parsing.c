/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 04:24:02 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/07 10:00:19 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int   check_file(int argc, char **argv)
{
    int len_file;
    int file;

    if  (argc > 2)
    {
        printf("erreur, contient trop de fichiers !\n");
        return(-1);
    }
    if (argc < 2)
    {
        printf("erreur, aucun fichier transmit\n");
        return(-1);
    }
    len_file = ft_strlen(argv[1]);
    if( len_file < 3 || !ft_strnstr(&argv[1][len_file - 3], ".rt", 3))
    {
        printf("le fichier ne contient pas l'extention .rt\n");
        return(-1);
    }
    file = open(argv[1], O_RDONLY);
    if(file < 0)
        printf("erreur , impossible d'ouvire le fichier\n");
    return(file);
}

t_object    *check_open( int argc, char  **argv)
{
    int file;
    t_object *parse_file;
    char *str;

    parse_file  = NULL;
    file = check_file(argc, argv);
    if (file < 0)
        return NULL;    
    str = get_next_line(file);
    while(str)
    {
        obj_addback(&parse_file, element_file(ft_split(str,' ')));
        free(str);
        str = get_next_line(file);
    }
    free(str);
    return(parse_file);
}

t_object *element_file(char **str)
{
    t_object *element;

    element = NULL;
    if (!str)
        return NULL;
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