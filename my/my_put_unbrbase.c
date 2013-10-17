/*
** my_put_unbrbase.c for my_printf in /home/dabbec_j/projets/pushswap/my_printf
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Dim avr 28 18:43:41 2013 jalil dabbech
** Last update Thu Jun 06 16:41:39 2013 jalil dabbech
*/

#include "my_printf.h"

void    	my_put_unbrbase(unsigned int nb, char *base, unsigned int *size)
{
  unsigned int   result;
  unsigned int   divisor;
  unsigned int   size_base;

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
