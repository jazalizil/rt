/*
** my_strlen.c for my_printf in /home/dabbec_j/projets/pushswap/my_printf
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Dim avr 28 18:44:59 2013 jalil dabbech
** Last update Thu Jun 06 16:42:52 2013 jalil dabbech
*/

unsigned int	my_strlen(const char *str)
{
  unsigned int	length;

  length = 0;
  while (*str != '\0')
  {
    length = length + 1;
    str = str + 1;
  }
  return (length);
}
