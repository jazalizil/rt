/*
** main.c for sources in /root/projets/igraph/rt/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Thu Jul 11 02:34:29 2013 jalil dabbech
** Last update Thu Oct 17 22:06:48 2013 jalil dabbech
*/

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include "rt.h"
#include "my_printf.h"

void		draw_cmap(t_image);

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

void	attrib_color(t_image *cmap, int red, int green, int blue)
{
  cmap->color.red = red;
  cmap->color.green = green;
  cmap->color.blue = blue;
}

void		draw_cmap(t_image cmap)
{
  int		index;
  int		x;
  int		y;
  t_v3D		rayons[WINY + WINX];
  int		i;

  cmap.data = mlx_get_data_addr(cmap.img, &(cmap.bpp), &(cmap.sizeline),
      &(cmap.endian));
  attrib_color(&cmap, 0xFF, 0xFF, 0xFF);
  y = 0;
  i = 0;
  while (y < WINY)
  {
    x = 0;
    while (x < WINX)
    {
      index = x * cmap.bpp / 8 + y * cmap.sizeline;
      cmap.data[index] = cmap.color.blue;
      cmap.data[index + 1] = cmap.color.green;
      cmap.data[index + 2] = cmap.color.red;
      x++;
      i++;
    }
    y++;
  }
}

int		main(int ac, char **av)
{
  t_param	param;
  t_obj_list	*scene;

  scene = NULL;
  if (ac != 2)
    return (write(2, "Usage : ./rt <scene>\n", 21));
  if (get_scene(&scene, av[1]))
    return (1);
  if (!(param.mlx_ptr = mlx_init()))
    return (1);
  param.win_ptr = mlx_new_window(param.mlx_ptr, WINX, WINY, "JazaRT");
  param.cmap.img = mlx_new_image(param.mlx_ptr, WINX, WINY);
  draw_cmap(param.cmap);
  mlx_key_hook(param.win_ptr, gere_key, (void *)&param);
  mlx_expose_hook(param.win_ptr, gere_expose, (void *)&param);
  mlx_loop(param.mlx_ptr);
  return (0);
}
