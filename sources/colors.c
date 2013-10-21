/*
** colors.c for sources in /root/projets/igraph/rt/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Mon Oct 21 02:16:51 2013 jalil dabbech
** Last update Mon Oct 21 17:38:34 2013 jalil dabbech
*/

#include <unistd.h>
#include "rt.h"

t_color		*calc_inter(int x, int y, t_obj_list **objects, t_cam *cam)
{
  t_color	*ret;

  while (*objects)
  {
    objects = &((*objects)->next);
  }
  return (ret);
}

t_color		get_color(int x, int y, t_obj_list **objects, t_cam *cam)
{
  static int	coef = 1;
  t_v3D		rayon;
  t_color	*ret;

  if (!(ret = calc_inter(x, y, objects, cam)))
  {
    if (x % (coef * 20) == 0 || y % (k * 20) == 0)
    {
      (*ret).red = 0;
      (*ret).green = 0xFF;
      (*ret).blue = 0xFF;
    }
    else
    {
      (*ret).red = 0x8C;
      (*ret).green = 0x4F;
      (*ret).blue = 0;
    }
  }
  return (*ret);
}
