/*
** my_putchar.c for my_printf in /home/dabbec_j/projets/pushswap/my_printf
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Dim avr 28 18:44:05 2013 jalil dabbech
** Last update Thu Jun 06 16:41:56 2013 jalil dabbech
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
