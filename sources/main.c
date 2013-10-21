/*
** main.c for sources in /root/projets/igraph/rt/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Thu Jul 11 02:34:29 2013 jalil dabbech
** Last update Mon Oct 21 17:38:34 2013 jalil dabbech
*/

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include "rt.h"
#include "my_printf.h"

int		gere_expose(void *p)
{
  t_param	*param;

  param = (t_param *)p;
  mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->cmap.img, 0,
      			  0);
  return (1);
}

int		gere_key(int key)
{
  if (key == 65307)
    exit(EXIT_SUCCESS);
  else if (key == 65362)
    my_printf("Avance\n");
  else if (key == 65364)
    my_printf("Recule\n");
  else if (key == 65361)
    my_printf("Gauche\n");
  else if (key == 65363)
    my_printf("Droite\n");
  else
    my_printf("KEY == [%d]\n", key);
  return (0);
}

int		draw_plan(t_image cmap, t_obj_list **objs, t_cam *cam)
{
  int		index;
  int		x;
  int		y;
  t_v3D		rayons[WINY * WINX];

  cmap.data = mlx_get_data_addr(cmap.img, &(cmap.bpp), &(cmap.sizeline),
      			        &(cmap.endian));
  y = -1;
  x = -1;
  while (WINX < WINY ? (++y < WINY) : (++x < WINX))
  {
    WINX < WINY ? x = -1 : y = -1;
    while (WINX < WINY ? (++y < WINY) : (++x < WINX))
    {
      color[0] = ((y > WINY / 3 / 2 && (y % 20 == 0 || x % 20 == 0)) ? 0 : 0x8C);
      color[1] = ((y > WINY / 3 / 2 && (y % 20 == 0 || x % 20 == 0)) ? 0xFF : 0x4F);
      color[2] = ((y > WINY / 3 / 2 && (y % 20 == 0 || x % 20 == 0)) ? 0xFF : 0);
      cmap.color = get_color(x, y, objs, cam);
      index = x * cmap.bpp / 8 + y * cmap.sizeline;
      cmap.data[index] = cmap.color.blue;
      cmap.data[index + 1] = cmap.color.green;
      cmap.data[index + 2] = cmap.color.red;
    }
  }
  return (0);
}

t_cam		*init_cam()
{
  t_cam		ret;
  t_v3D		pos;
  t_v3D		orientation;

  pos.x = WINX / 2;
  pos.y = WINY / 2;
  pos.z = 200;
  orientation.x = 0;
  orientation.y = 0;
  orientation.z = 0;
  ret.pos = &pos;
  ret.orien = &orientation;
  ret.foc = 1;
  return (&ret);
}

int		main(int ac, char **av)
{
  t_param	param;
  t_obj_list	*objects;
  t_cam		cam;

  scene = NULL;
  if (ac != 2)
    return (write(2, "Usage : ./rt <scene>\n", 21));
  if (get_scene(&objects, av[1]))
    return (1);
  if (!(param.mlx_ptr = mlx_init()))
    return (1);
  cam = init_cam();
  param.win_ptr = mlx_new_window(param.mlx_ptr, WINX, WINY, "JazaRT");
  param.cmap.img = mlx_new_image(param.mlx_ptr, WINX, WINY);
  if (!(draw_plan(param.cmap, &objects, &cam)))
    return (1);
  mlx_key_hook(param.win_ptr, gere_key, (void *)&param);
  mlx_expose_hook(param.win_ptr, gere_expose, (void *)&param);
  mlx_loop(param.mlx_ptr);
  return (0);
}
