/*
** my_put_unbr.c for my_printf in /home/dabbec_j/projets/my_select/my_printf
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Dim avr 28 18:42:40 2013 jalil dabbech
** Last update Mon Jun 17 15:45:42 2013 jalil dabbech
*/

void	my_putchar(char);

unsigned int	my_upow(unsigned int nb, unsigned int power)
{
  unsigned int	i;
  unsigned int	ret;

  i = 1;
  ret = nb;
  while (i < power)
  {
    ret = ret * nb;
    i = i + 1;
  }
  return (ret);
}

unsigned int	my_uintlen(unsigned int nb)
{
  unsigned int	i;

  i = 0;
  while (nb >= 10)
  {
    nb = nb / 10;
    i = i + 1;
  }
  return (i + 1);
}

void		my_put_unbr(unsigned int nbr, unsigned int *size)
{
  unsigned int	length;
  char		fig;

  length = my_uintlen(nbr);
  while (length > 1)
  {
    fig = nbr / my_upow(10, length - 1) + 48;
    my_putchar(fig);
    *size += 1;
    nbr = nbr % my_upow(10, length - 1);
    length = length - 1;
  }
  my_putchar(nbr + 48);
  *size += 1;
}
