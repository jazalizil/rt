/*
** get_next_line.c for my in /root/projets/igraph/rt/my
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Lun avr 29 11:21:01 2013 jalil dabbech
** Last update Thu Oct 17 22:54:07 2013 jalil dabbech
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include "get_next_line.h"
#include "my.h"

char	*my_strcpy(char *dest, const char *src)
{
  int	i;

  i = 0;
  while (src[i])
  {
    dest[i] = src[i];
    i++;
  }
  return (dest);
}

void		*my_memcpy(void *dest, const void *src, int n)
{
  char 		*tmp;
  const char 	*tmp2;
  int		i;

  tmp = dest;
  tmp2 = src;
  i = 0;
  while (i < n)
  {
    tmp[i] = tmp2[i];
    i ++;
  }
  return (dest);
}

static char	*add_to_line(char *line, char *buffer, int cur, int *start)
{
  char		*rest_of_line;
  int		old_len;

  old_len = 0;
  if (line)
    old_len = my_strlen(line);
  if (!(rest_of_line = malloc(old_len + cur + 1)))
    return (NULL);
  if (rest_of_line == NULL)
    return (0);
  if (line)
    my_strcpy(rest_of_line, line);
  else
    my_strcpy(rest_of_line, "");
  my_memcpy(rest_of_line + old_len, buffer + *start, cur);
  rest_of_line[old_len + cur] = '\0';
  if (line)
    free(line);
  *start += cur + 1;
  return (rest_of_line);
}

char		*get_next_line(int fd)
{
  int		cur;
  char		*line;
  static char	buffer[SIZE_OF_READ_H_];
  static int	in_buf;
  static int	start;

  line = NULL;
  cur = 0;
  while (42)
  {
    if (start >= in_buf)
    {
      start = 0;
      if (!(in_buf = read(fd, buffer, SIZE_OF_READ_H_)) || in_buf < 0)
	return (line);
      cur = 0;
    }
    if (buffer[start + cur] == '\n')
      return ((line = add_to_line(line, buffer, cur, &start)));
    if (start + cur == in_buf - 1)
      if (!(line = add_to_line(line, buffer, cur + 1, &start)))
	return (NULL);
    cur++;
  }
}
