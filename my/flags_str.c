/*
** flags_str.c for my_printf in /home/dabbec_j/projets/my_select/my_printf
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Dim avr 28 18:27:57 2013 jalil dabbech
** Last update Mon Jun 17 15:44:23 2013 jalil dabbech
*/

#include <stdlib.h>
#include "my_printf.h"

void 		print_str(va_list ap, unsigned int *size)
{
  const	char	*str;

  str = va_arg(ap, const char *);
  if (str == NULL)
  {
    my_putstr("(null)");
    *size += 6;
  }
  else
  {
    my_putstr(str);
    *size += my_strlen(str);
  }
}

void	print_char(va_list ap, unsigned int *size)
{
  char	c;

  c = va_arg(ap, int);
  my_putchar(c);
  *size += 1;
}

void		print_stroctal_bis(const char *str, unsigned int *size)
{
  unsigned int	i;

  i = 0;
  while (str[i])
  {
    size += 1;
    if (str[i] > 32 && str[i] < 127)
      my_putchar(str[i]);
    else
    {
      size += 2;
      if (str[i] < 8)
	my_putstr("\\00");
      else if (str[i] > 8 && str[i] < 32)
      {
	my_putstr("\\0");
	*size -= 1;
      }
      else
	*size -= 3;
      my_printf("%o", str[i]);
    }
    i = i + 1;
  }
}

void		print_stroctal(va_list ap, unsigned int *size)
{
  const char	*str;

  str = va_arg(ap, char *);
  if (str == NULL)
  {
    my_putstr("(null)");
    *size += 6;
  }
  else
    print_stroctal_bis(str, size);
}

void		print_addr(va_list ap, unsigned int *size)
{
  unsigned long	addr;

  addr = va_arg(ap, unsigned long);
  my_putstr("0x");
  *size += 2;
  my_put_addr(addr, size);
}
