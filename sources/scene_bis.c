/*
** scene_bis.c for sources in /home/dabbec_j/projets/igraph/rt/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Wed Oct 16 20:43:29 2013 jalil dabbech
** Last update Thu Oct 17 20:42:57 2013 jalil dabbech
*/

#include <stdlib.h>
#include "rt.h"
#include "my.h"
#include "error.h"

t_defmat	g_defmat[] =
{
  {"metal", {NULL, NULL, NULL, NULL, 0, 0, 0, 0, 0},
  {"",{}},
  {"",{}},
  {"",{}},
  {"",{}},
};

int		*parse_it(char *info, int size)
{
  int		*ret;
  int		i;
  int		j;
  int		k;
  char		*str;

  i = -1;
  j = 0;
  k = 0;
  if (!(ret = malloc(size * sizeof(int))))
    return (NULL);
  while (info[++i])
    if (info[i] == ' ')
    {
      if (!(str = my_strndup(info, i, j)))
	return (NULL);
      k < size ? ret[k++] = atoi(str) : ;
      j = i;
      free(str);
    }
  if (!(str = my_strndup(info, j, i)))
    return (NULL);
  ret[k] = atoi(str);
  free(str);
  return (ret);
}

int		get_mat(char *info, t_v3D *coord, t_materiau *mater)
{
  int		j;
  int		*mat;

  j = -1;
  if (!info)
    return (write(2, MALLOC_ERR, 21));
  while (++j < 5)
    if (!my_strcmp(info, g_defmat[j]))
    {
      mater = g_defmat[j].materiau;
      return (0);
    }
  if (!(mat = parse_it(info, 5)))
    return (write(2, MALLOC_ERR, 21));
  if (!(mater = fill_mat(mat)))
    return (write(2, MALLOC_ERR, 21));
  free(info);
  return (0);
}

int		get_coord(char *info, t_v3D *coord, t_materiau *mater)
{
  int		*coor;

  if (!info)
    return (write(2, MALLOC_ERR, 21));
  if (!(coor = parse_it(info, 3)))
    return (write(2, MALLOC_ERR, 21));
  if (!(coord = fill_cord(coor)))
    return (write(2, MALLOC_ERR, 21));
  free(info);
  return (0);
}

int		add_to_mater(char *info, t_v3D *coord, t_materiau *mater)
{
  int		i;
  int		j;
  int		k;
  int		*col;

  if (!info)
    return (write(2, MALLOC_ERR, 21));
  if (!(col = parse_it(info, 3)))
    return (write(2, MALLOC_ERR, 21));
  if (fill_color(mater, col, 0))
    return (1);
  free(info);
  return (0);
}
