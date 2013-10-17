/*
** my_putstr.c for my_printf in /home/dabbec_j/projets/pushswap/my_printf
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Dim avr 28 18:44:41 2013 jalil dabbech
** Last update Thu Jun 06 16:42:30 2013 jalil dabbech
*/

#include "my_printf.h"

void	my_putstr(const char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
  {
    my_putchar(str[i]);
    i = i + 1;
  }
}
