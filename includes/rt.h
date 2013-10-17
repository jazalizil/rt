/*
** rt.h for includes in /root/projets/igraph/rt/includes
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Thu Jul 11 02:35:03 2013 jalil dabbech
** Last update Thu Oct 17 23:17:17 2013 jalil dabbech
*/

#ifndef RT_H_
# define RT_H_
# define WINX 400
# define WINY 400

typedef struct		s_color
{
  int			red;
  int			blue;
  int			green;
}			t_color;

typedef struct		s_image
{
  t_color		color;
  int			bpp;
  int			sizeline;
  int			endian;
  char			*data;
  void			*img;
}			t_image;

typedef struct		s_param
{
  void			*mlx_ptr;
  void			*win_ptr;
  t_image		cmap;
}			t_param;

typedef struct		s_v2D
{
  int			x;
  int			y;
}			t_v2D;

typedef struct		s_v3D
{
  int			x;
  int			y;
  int			z;
}			t_v3D;

typedef struct		s_cam
{
  t_v3D			pos;
  t_v3D			orientation;
  int			foc;
  t_v2D			resolution;
  t_v2D			pitch;
}			t_cam;

typedef struct		s_materiau
{
  t_color		ambiante;
  t_color		diffuse;
  t_color		reflexion;
  t_color		specular;
  int			coef_amb;
  int			coef_dif;
  int			coef_ref;
  int			coef_spec;
  int			opac;
}			t_materiau;

typedef struct		s_obj_list
{
  t_materiau		*materiau;
  char			*type;
  t_v3D			*coord;
  struct s_obj_list	*next;
}			t_obj_list;

typedef struct		s_scinfo
{
  char			*type;
  int			(*fct)(char *, t_v3D *, t_materiau *);
}			t_scinfo;

typedef struct		s_defmat
{
  char			*name;
  t_materiau		materiau;
}			t_defmat;

int			get_scene(t_obj_list **, char *);
int			get_mat(char *, t_v3D *, t_materiau *);
int			get_coord(char *, t_v3D *, t_materiau *);
int			add_to_mater(char *, t_v3D *, t_materiau *);
void			epur_str(char *);
t_materiau		*fill_mat(int *);
t_v3D			*fill_coord(int *);
int			fill_color(t_materiau *, int *, int);

#endif /* !RT_H_ */
