/*
** my_strdup.c for my in /home/dabbec_j/projets/projet_gen/my
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Wed Oct 16 19:49:43 2013 jalil dabbech
** Last update Wed Oct 16 19:55:04 2013 jalil dabbech
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *str)
{
  int	i;
  char	*ret;

  i = 0;
  if (!(ret = malloc(my_strlen(str) + 1)))
    return (ret);
  while (str[i])
  {
    ret[i] = str[i];
    i++;
  }
  ret[i] = 0;
  return (ret);
}

char	*my_strndup(char *str, int st, int end)
{
  int	i;
  char	*ret;

  if (!(ret = malloc(end - st + 1)))
    return (ret);
  i = 0;
  while (st < end)
  {
    ret[i] = str[st];
    st++;
    i++;
  }
  ret[i] = 0;
  return (ret);
}
