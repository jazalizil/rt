/*
** my_malloc.c for my in /home/dabbec_j/projets/projet_gen/my
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Dim mai 05 13:33:26 2013 jalil dabbech
** Last update Tue Oct 15 21:49:58 2013 jalil dabbech
*/

#include <stdlib.h>
#include "my.h"

void	*my_malloc(int size, char *when)
{
  void	*ret;

  ret = malloc(size * sizeof(int));
  if (ret == NULL)
  {
    my_putmlkerror("Error malloc in ");
    my_putmlkerror(when);
  }
  return (ret);
}

char	**my_wordtabmalloc(int size, char *when)
{
  char	**ret;

  ret = malloc(size * sizeof(char *));
  if (ret == NULL)
  {
    my_putmlkerror("Error malloc in ");
    my_putmlkerror(when);
  }
  return (ret);
}

int	my_wordtab_size(char **wordtab)
{
  int	i;

  i = 0;
  while (wordtab[i])
    i++;
  return (i);
}

void	my_free_wordtab(char **wordtab, int size)
{
  int	i;

  i = 0;
  while (i < size)
    free(wordtab[i++]);
  free (wordtab);
}
