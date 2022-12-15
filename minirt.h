/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charleshajjar <charleshajjar@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 04:23:26 by charleshajj       #+#    #+#             */
/*   Updated: 2022/12/15 23:30:39 by charleshajj      ###   ########.fr       */
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
# include "MLX42/include/MLX42/MLX42.h"

# define OBJ_INVALID -1
# define OBJ_A 0
# define OBJ_C 1
# define OBJ_L 2
# define OBJ_SP 3
# define OBJ_PL 4
# define OBJ_CY 5

typedef struct s_ray{
	t_v3d	start;
	t_v3d	dir;
}	t_ray;

typedef struct s_rgb
{
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
}					t_rgb;

typedef struct s_vecteur3d{
	float	x;
	float	y;
	float	z;
}	t_v3d;

typedef struct s_object{
	void			*object;
	int				type;
	struct s_object	*next;
}	t_object;

typedef struct s_lumiere_ambiante{
	float			ratio;
	t_rgb			rgb;
}	t_la;

typedef struct s_camera{
	t_v3d	view;
	t_v3d	pos;
	int		fov;
}	t_cam;

typedef struct s_lumiere{
	t_v3d			pos;
	float			ratio;
	t_rgb			rgb;
}	t_lum;

typedef struct s_sphere{
	t_v3d			pos;
	float			diametre;
	t_rgb			rgb;
}	t_sphere;

typedef struct s_plan{
	t_v3d			view;
	t_v3d			pos;
	t_rgb			rgb;
}	t_plan;

typedef struct s_cylindre{
	t_v3d			view;
	t_v3d			pos;
	float			diametre;
	float			hauteur;
	t_rgb			rgb;
}	t_cylindre;

typedef unsigned char	t_bool;

int				check_file(int arg, char **argv);
t_object		*check_open(int argc, char **argv);
void			obj_addback(t_object **lst, t_object *insert);
t_object		*element_file(char **str);
t_object		*creat_object(int type);
t_object		*malloc_type_object(t_object *object, int type);
void			free_array(char **str);
t_rgb			color(char *value);
t_v3d			verteur_3d(char *value);

t_object		*parse_lumen(char **values);
t_object		*parse_camera(char **values);
t_object		*parse_lumiere(char **values);
t_object		*parse_sphere(char **values);
t_object		*parse_plan(char **values);
t_object		*parse_cylindre(char **values);

t_bool			is_empty(char **str);
void			clear_scene(t_object *scene);
void			msg_error(char *message);

t_bool			check_scene(t_object *scene);
t_bool			check_flag(uint8_t *f);
t_bool			check_cam(t_cam *c, uint8_t *f);
t_bool			check_amb(t_la *a, uint8_t *f);
t_bool			check_lumiere(t_lum *l, uint8_t *f);
t_bool			check_sphere(t_sphere *s);
t_bool			check_plan(t_plan *p);
t_bool			check_cylindre(t_cylindre *p);
t_bool			check_color(t_rgb *c);
t_bool			sphere_intersect(t_ray *r, t_sphere *s);

double			vector_sub(t_v3d v1, t_v3d v2);
double			vector_dot(t_v3d v1, t_v3d v2);

#endif