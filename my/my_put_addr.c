/*
** my_put_addr.c for my_printf in /home/dabbec_j/projets/pushswap/my_printf
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Dim avr 28 18:42:28 2013 jalil dabbech
** Last update Thu Jun 06 16:41:06 2013 jalil dabbech
*/

#include "my_printf.h"

void    	my_put_addr(unsigned long nb, unsigned int *size)
{
  unsigned long	result;
  unsigned long	divisor;
  unsigned int	size_base;
  char		*base;

  base = "0123456789abcdef";
  size_base = my_strlen(base);
  divisor = 1;
  while ((nb / divisor) >= size_base)
    divisor = divisor * size_base;
  while (divisor > 0)
  {
    result = (nb /divisor) % size_base;
    my_putchar(base[result]);
    *size += 1;
    divisor = divisor / size_base;
  }
}
