/*
** my_printf.h for includes in /root/projets/igraph/rt/includes
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  mar. avril 23 17:02:03 2013 jalil dabbech
** Last update Thu Oct 17 22:15:29 2013 jalil dabbech
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

#include <stdarg.h>

typedef struct	s_flag
{
  char		flag;
  void		(*print)(va_list, unsigned int *);
} 		t_flag;

void		my_putchar(char);
int		my_printf(const char *, ...);
void		my_put_addr(unsigned long, unsigned int *);
void		my_put_unbrbase(unsigned int, char *, unsigned int *);
unsigned int	my_strlen(const char *);
unsigned int	my_upow(unsigned int, unsigned int);
unsigned int	my_uintlen(unsigned int);
void		my_putstr(const char *);
void		my_put_unbr(unsigned int, unsigned int *);
void		print_nbr(va_list, unsigned int *);
void 		print_str(va_list, unsigned int *);
void		print_char(va_list, unsigned int *);
void		print_octal(va_list, unsigned int *);
void		print_bin(va_list, unsigned int *);
void		print_examin(va_list, unsigned int *);
void		print_examaj(va_list, unsigned int *);
void		print_stroctal(va_list, unsigned int *);
void		print_unsigned(va_list, unsigned int *);
void		print_addr(va_list, unsigned int *);
void		print_prcent(va_list, unsigned int *);

#endif
