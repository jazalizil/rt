/*
** main.c for sources in /root/projets/igraph/rt/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Thu Jul 11 02:34:29 2013 jalil dabbech
** Last update Fri Oct 18 18:47:47 2013 jalil dabbech
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
  int		color[3];

  cmap.data = mlx_get_data_addr(cmap.img, &(cmap.bpp), &(cmap.sizeline),
      			        &(cmap.endian));
  y = -1;
  while (++y < WINY)
  {
    x = -1;
    while (++x < WINX)
    {
      color[0] = ((y > WINY / 3 / 2 && (y % 20 == 0 || x % 20 == 0)) ? 0 : 0x8C);
      color[1] = ((y > WINY / 3 / 2 && (y % 20 == 0 || x % 20 == 0)) ? 0xFF : 0x4F);
      color[2] = ((y > WINY / 3 / 2 && (y % 20 == 0 || x % 20 == 0)) ? 0xFF : 0);
      attrib_color(&cmap, color[0], color[1], color[2]);
      index = x * cmap.bpp / 8 + y * cmap.sizeline;
      cmap.data[index] = cmap.color.blue;
      cmap.data[index + 1] = cmap.color.green;
      cmap.data[index + 2] = cmap.color.red;
    }
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
  draw_plan(param.cmap);
  mlx_key_hook(param.win_ptr, gere_key, (void *)&param);
  mlx_expose_hook(param.win_ptr, gere_expose, (void *)&param);
  mlx_loop(param.mlx_ptr);
  return (0);
}
