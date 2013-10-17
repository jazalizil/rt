/*
** my.h for includes in /home/dabbec_j/projets/igraph/rt/includes
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Tue Jun 18 16:27:41 2013 jalil dabbech
** Last update Wed Oct 16 19:58:56 2013 jalil dabbech
*/

#ifndef MY_H_
# define MY_H_

void	*my_malloc(int, char *);
void	my_putmlkerror(char *);
int	my_strcmp(char *, char *);
void	my_putstrerror(char *, int);
char	**my_wordtabmalloc(int, char *);
void	my_free_wordtab(char **, int);
int	my_getnbr(char *);
char	*my_strdup(char *);
char	*my_strndup(char *, int, int);

#endif /* !MY_H_ */
