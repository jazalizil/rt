/*
** my_get_nbr.c for my in /home/dabbec_j/projets/allum1/my
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Sun May 19 14:22:23 2013 jalil dabbech
** Last update Tue Jul 02 13:25:52 2013 jalil dabbech
*/

int	is_neg(char *str)
{
  int	i;
  int	counter;

  i = 0;
  counter = 0;
  while (str[i] > '9' || str[i] < '0')
    {
      if (str[i] == '-')
        counter = counter + 1;
      i = i + 1;
    }
  if (counter % 2 != 0)
    return (1);
  else
    return (0);
}

int	is_num(char l)
{
  if (l >= '0' && l <= '9')
    return (1);
  else if (l == '+' || l == '-')
    return (2);
  else
    return (0);
}

int	my_getnbr(char *str)
{
  int	i;
  int	nbr;

  nbr = 0;
  i = 0;
  if (!str)
    return (0);
  while (is_num(str[i]) == 2)
    i = i + 1;
  while (is_num(str[i]) == 1)
    {
      nbr = ((nbr * 10) + (str[i] - 48));
      i = i + 1;
    }
  if (is_neg(str) == 1)
    nbr = -nbr;
  return (nbr);
}
