/*
** flag_u.c for my_printf in /home/dabbec_j/projets/pushswap/my_printf
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Dim avr 28 18:26:53 2013 jalil dabbech
** Last update Thu Jun 06 16:40:16 2013 jalil dabbech
*/

#include "my_printf.h"

void		print_unsigned(va_list ap, unsigned int *size)
{
  unsigned int	nbr;

  nbr = va_arg(ap, unsigned int);
  my_put_unbr(nbr, size);
}

void	print_prcent(va_list ap, unsigned int *size)
{
  my_putchar('%');
  *size += 1;
}
