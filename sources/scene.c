/*
** scene.c for sources in /root/projets/igraph/rt/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Wed Oct 16 18:45:18 2013 jalil dabbech
** Last update Fri Oct 18 01:54:19 2013 jalil dabbech
*/

#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "rt.h"
#include "get_next_line.h"
#include "my.h"
#include "error.h"

t_scinfo	g_scinfo[] =
{
  {"type", NULL},
  {"mat", &get_mat},
  {"origin", &get_coord},
  {"color", &add_to_mater}
};

int		add_to_scene(t_obj_list **scene, t_v3D *coord,
    			     t_materiau *mater, char *type)
{
  printf("%s\n", type);
  printf("OBJET %s :\n--mater: \ncolor_amb = %d, %d, %d\ncolor_dif = %d, %d, %d\n \
      	  color_ref = %d, %d, %d\ncolor_spec = %d, %d, %d\n", type, mater->ambiante.red, \
	  mater->ambiante.green, mater->ambiante.blue, mater->diffuse.red, \
	  mater->diffuse.green, mater->diffuse.blue, mater->reflexion.red, \
	  mater->reflexion.green, mater->reflexion.blue, mater->specular.red, \
	  mater->specular.green, mater->specular.blue);
  printf("--coord:\nx = %d\ny = %d\nz = %d\n", coord->x, coord->y, coord->z);
  return (0);
}

int		fill_info(char *line, t_v3D *coord, t_materiau *mater,
    			  char **type)
{
  char		*which;
  int		i;
  int		j;

  i = -1;
  while (line[++i])
    if (line[i] == '=')
    {
      if (!(which = my_strndup(line, 0, i)))
	return (write(2, MALLOC_ERR, 21));
      j = -1;
      while (++j < 4)
	if (!my_strcmp(which, g_scinfo[j].type))
	{
	  if (j == 0 && !(*type = my_strndup(line, i + 1, my_strlen(line))))
	    return (write(2, MALLOC_ERR, 21));
	  if (j > 0 &&
	      (g_scinfo[j].fct(my_strndup(line, i + 1, my_strlen(line)), &coord,
		               mater)))
	    return (1);
	  if (j == 2)
	    printf("=====[%d]=====\n", coord->x);
	}
      free(which);
    }
  return (0);
}

int		get_info(int fd, t_v3D *coord, t_materiau *mater, char **type)
{
  char		*line;

  while ((line = get_next_line(fd)) && my_strcmp(line, "#endobj"))
  {
    epur_str(line);
    if (fill_info(line, coord, mater, type))
      return (1);
    free(line);
  }
  return (0);
}

int		get_scene(t_obj_list **scene, char *file)
{
  t_v3D		coord;
  t_materiau	mater;
  char		*type;
  int		fd;
  char		*line;

  type = NULL;
  if ((fd = open(file, O_RDONLY)) < 0)
    return (write(2, OPEN_ERR, 25));
  while ((line = get_next_line(fd)))
  {
    epur_str(line);
    if (!my_strcmp(line, "#startobj"))
    {
      if (get_info(fd, &coord, &mater, &type))
	return (1);
      if (add_to_scene(scene, &coord, &mater, type))
	return (1);
    }
    free(line);
  }
  return (0);
}
