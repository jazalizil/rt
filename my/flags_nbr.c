/*
** flags_nbr.c for my_printf in /home/dabbec_j/projets/pushswap/my_printf
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Dim avr 28 18:27:08 2013 jalil dabbech
** Last update Thu Jun 06 16:40:31 2013 jalil dabbech
*/

#include "my_printf.h"

void	print_nbr(va_list ap, unsigned int *size)
{
  int	nbr;
  int	length;
  char	fig;

  nbr = va_arg(ap, int);
  if (nbr < 0)
  {
    nbr = -nbr;
    my_putchar('-');
    *size += 1;
  }
  length = my_uintlen(nbr);
  while (length > 1)
  {
    fig = nbr / my_upow(10, length - 1) + 48;
    my_putchar(fig);
    *size += 1;
    nbr = nbr % my_upow(10, length - 1);
    length = length - 1;
  }
  my_putchar(48 + nbr);
  *size += 1;
}

void		print_octal(va_list ap, unsigned int *size)
{
  unsigned int	nbr;

  nbr = va_arg(ap, unsigned int);
  my_put_unbrbase(nbr, "01234567", size);
}

void		print_bin(va_list ap, unsigned int *size)
{
  unsigned int	nbr;

  nbr = va_arg(ap, unsigned int);
  my_put_unbrbase(nbr, "01", size);
}

void		print_examin(va_list ap, unsigned int *size)
{
  unsigned int	nbr;

  nbr = va_arg(ap, unsigned int);
  my_put_unbrbase(nbr, "0123456789abcdef", size);
}

void		print_examaj(va_list ap, unsigned int *size)
{
  unsigned int	nbr;

  nbr = va_arg(ap, unsigned int);
  my_put_unbrbase(nbr, "0123456789ABCDEF", size);
}
