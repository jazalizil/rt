/*
** fill_mat_and_coord.c for sources in /root/projets/igraph/rt/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Thu Oct 17 19:34:34 2013 jalil dabbech
** Last update Thu Oct 17 23:17:14 2013 jalil dabbech
*/

#include <stdlib.h>
#include <unistd.h>
#include "rt.h"
#include "error.h"

t_materiau	*fill_mat(int *tab)
{
  t_materiau	*mat;

  mat = NULL;
  if (!(mat = malloc(sizeof(t_materiau))))
    return (NULL);
  mat->coef_amb = tab[0];
  mat->coef_dif = tab[1];
  mat->coef_ref = tab[2];
  mat->coef_spec = tab[3];
  mat->opac = tab[4];
  free(tab);
  return (mat);
}

t_v3D		*fill_coord(int *tab)
{
  t_v3D		*coord;

  coord = NULL;
  if (!(coord = malloc(sizeof(t_v3D))))
    return (NULL);
  printf("[%p]\n", tab);
  coord->x = tab[0];
  coord->y = tab[1];
  coord->z = tab[2];
  free(tab);
  return (coord);
}

int		fill_color(t_materiau *mater, int *col, int which)
{
  t_color	*current;

  if (which < 4)
  {
    if (!(current = malloc(sizeof(t_color))))
      return (write(2, MALLOC_ERR, 21));
    current->red = col[0] + which * 5;
    current->green = col[1] + which * 5;
    current->blue = col[2] + which * 5;
    if (which == 0)
      mater->ambiante = *current;
    else if (which == 1)
      mater->diffuse = *current;
    else if (which == 2)
      mater->reflexion = *current;
    else
      mater->specular = *current;
    return (fill_color(mater, col, which++));
  }
  free(col);
  return (0);
}
