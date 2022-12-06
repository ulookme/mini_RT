/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 04:21:53 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/07 05:00:24 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool_t  is_empty(char **str)
{
    int i = 0;
    int y;

    while(str && str[i])
    {
        y = 0;
        while(str[i][y])
            if (!ft_isspace(str[i][y++]))
                return (0);
        i++;

    }
    return (1);
}

void    obj_addback(t_object **lst, t_object *insert)
{
    t_object    *cur;

    if (!lst)
        return ;
    cur = *lst;
    if (!cur)
    {
        *lst = insert;
        return ;
    }
    while (cur)
    {
        while (cur->next)
            cur = cur->next;
        cur->next = insert;
    }
}

t_object *parse_camera(char **values)
{
    t_object *obj;
    if (values[1] && values[2] && values[3] && !values[4])
        return NULL;
    obj = creat_object(OBJ_C);
    if(!obj)
        return NULL;
    ((t_cam *) obj->object)->view = verteur_3d(values[1]);
    ((t_cam *) obj->object)->pos = verteur_3d(values[2]);
    ((t_cam *) obj->object)->fov = ft_atoi(values[3]);
    return(obj);
}

t_object *parse_lumiere(char **values)