/*
** my_printf.c for my in /home/dabbec_j/projets/my_select/my
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Dim avr 28 18:36:37 2013 jalil dabbech
** Last update Fri Jun 21 12:00:06 2013 jalil dabbech
*/

#include <stdlib.h>
#include "my_printf.h"

t_flag g_flags[] =
{
  {'d', &print_nbr},
  {'s', &print_str},
  {'c', &print_char},
  {'i', &print_nbr},
  {'o', &print_octal},
  {'b', &print_bin},
  {'x', &print_examin},
  {'X', &print_examaj},
  {'S', &print_stroctal},
  {'u', &print_unsigned},
  {'p', &print_addr},
  {'%', &print_prcent},
  {'\0', NULL}
};

int	which_flag(char c)
{
  int	i;

  i = 0;
  while (g_flags[i].flag != '\0')
  {
    if (g_flags[i].flag == c)
      return (i);
    i = i + 1;
  }
  return (-1);
}

int	many_flags(const char *str)
{
  int	ret;
  int	i;

  ret = 0;
  i = 0;
  while (str[i])
  {
    if (str[i] == '%' && which_flag(str[i + 1]) != -1)
    {
      ret = ret + 1;
      if (str[i + 1] == '%')
	i = i + 1;
    }
    i = i + 1;
  }
  return (ret);
}

int	undid_spec_format(const char *str, int i)
{
  char	non_allowed[] = {43, 45, 35, 48, 42};
  char	other_non_allowed[] = {'h', 'l', 'j', 'z', 't'};
  int	j;

  j = 0;
  while (j < 5)
    if (str[i + 1] == non_allowed[j++])
      return (1);
  if (str[i + 1] == 32 && which_flag(str[i + 1]) != -1)
    return (1);
  j = 0;
  while (j < 5)
    if (str[i + 1] == other_non_allowed[j++] && which_flag(str[i + 2] != -1))
      return (1);
  if (str[i + 1] == 'h' && str[i + 2] == 'h' && which_flag(str[i + 3]) != -1)
    return (1);
  else if (str[i + 1] == 'l' && str[i + 2] == 'l' &&
      which_flag(str[i + 3]) != -1)
    return (1);
  return (0);
}

int	print_no_flag(const char *str, int start, unsigned int *size, int *undo)
{
  int	i;

  i = start;
  while (str[i])
  {
    if ((str[i] != '%') | (which_flag(str[i + 1]) == -1))
    {
      if (!((str[i] == '%') && (which_flag(str[i + 1]) == -1)))
      {
	my_putchar(str[i]);
	*size = *size + 1;
      }
      if (str[i] == '%' && undid_spec_format(str, i) == 1)
	*undo = 1;
      }
    else
      return (i + 1);
    i = i + 1;
  }
  return (-1);
}

int		my_printf(const char *str, ...)
{
  va_list	ap;
  int		flag;
  int		position;
  int		nbr_flags;
  int		undid_it;
  unsigned int	size_ret;

  size_ret = 0;
  undid_it = 0;
  position = print_no_flag(str, 0, &size_ret, &undid_it);
  if (position == -1)
    return ((int)my_strlen(str));
  nbr_flags = many_flags(str);
  va_start(ap, str);
  while (nbr_flags > 0)
  {
    if (undid_it == 1)
      va_arg(ap, void *);
    flag = which_flag(str[position]);
    g_flags[flag].print(ap, &size_ret);
    undid_it = 0;
    position = print_no_flag(str, position + 1, &size_ret, &undid_it);
    nbr_flags -= 1;
  }
  return (size_ret);
}
