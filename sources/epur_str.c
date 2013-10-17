/*
** epur_str.c for sources in /home/dabbec_j/projets/igraph/rt/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Thu Oct 17 18:18:06 2013 jalil dabbech
** Last update Thu Oct 17 18:18:08 2013 jalil dabbech
*/

void	epur_str(char *str)
{
  int	space;
  char	*read;
  char	*write;

  space = 1;
  read = str;
  write = str;
  while (*read != '\0')
    {
      if (*read != ' ' || !space)
	*write++ = *read;
      space = *read ==' ';
      read++;
    }
  if (space && (write != str))
    write--;
  *write = '\0';
}
