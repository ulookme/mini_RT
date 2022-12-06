/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 04:23:26 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/07 08:27:10 by charleshajj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "./Libft/libft.h"

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
#include "MLX42/include/MLX42/MLX42.h"

#define OBJ_A 0
#define OBJ_C 1
#define OBJ_L 2
#define OBJ_SP 3
#define OBJ_PL 4
#define OBJ_CY 5

typedef struct s_vecteur3d{
    float  x;
    float  y;
    float  z; 
}t_v3d;

typedef struct      s_object{
    void*           object;
    int             type;
    struct s_object * next;
}t_object;

typedef struct  s_lumiere_ambiante{
    float   ratio;
    unsigned int RGB;
}t_la;

typedef struct s_camera{
    t_v3d view;
    t_v3d pos;
    int   fov;   
}t_cam;

typedef struct  s_lumiere{
    t_v3d pos;
    float  ratio;  
    unsigned int RGB;
}t_lum;

typedef struct  s_sphere{
    t_v3d pos;
    float  diametre;  
    unsigned int RGB;
}t_sphere;

typedef struct  s_plan{
    t_v3d view;
    t_v3d pos; 
    unsigned int RGB;
}t_plan;

typedef struct  s_cylindre{
    t_v3d view;
    t_v3d pos;
    float  diametre; 
    float  hauteur; 
    unsigned int RGB;
}t_cylindre;

typedef unsigned char   bool_t;

int        check_file(int arg, char **argv);
t_object    *check_open( int argc, char  **argv);
void        obj_addback(t_object **lst, t_object *insert);
t_object    *element_file(char **str);
t_object    *creat_object(int type);
void	    free_array(char **str);
unsigned int color(char *value);
t_object    *parse_lumen(char **values);
t_v3d       verteur_3d(char  *value);
t_object    *parse_camera(char **values);
t_object    *parse_lumiere(char **values);
t_object    *parse_sphere(char ** values);
t_object    *parse_plan(char **values);
t_object    *parse_cylindre(char **values)
bool_t  is_empty(char **str);

#endif