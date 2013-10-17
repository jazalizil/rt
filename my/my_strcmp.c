/*
** my_strcmp.c for my_printf in /home/dabbec_j/projets/my_select/my_printf
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Wed May 22 19:01:21 2013 jalil dabbech
** Last update Tue Jun 18 16:23:16 2013 jalil dabbech
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i])
  {
    if (s1[i] == '\0')
      return (0);
    i = i + 1;
  }
  return (s1[i] - s2[i]);
}
