/*
** pipeit.c for pipeit in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Mar 22 14:39:02 2016 alies_a
** Last update Tue Mar 22 19:50:11 2016 alies_a
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"

t_rdr rdr[] = {
  {&out_simple, '>'},
  {&in_simple, '<'},
  {NULL, 0},
};

int	in_simple(const t_cmp *cmp)
{
  int	fd;

  if ((fd = open((cmp->rd)[IN].file, O_RDONLY)) == -1)
    return (1);
  if (dup2(fd, 0) == -1)
    return (1);
  return (0);
}

int	out_simple(const t_cmp *cmp)
{
  int	fd;

  if ((fd = open((cmp->rd)[OUT].file, O_WRONLY | O_CREAT, 0644)) == -1)
    return (1);
  if (dup2(fd, 1) == -1)
    return (1);
  return (0);
}

int	pipeit(const t_cmp *cmp)
{
  int	x;
  int	res;

  res = 0;
  x = 0;
  while (rdr[x].pipe != NULL)
    {
      if (rdr[x].type == cmp->rd[OUT].type ||
	  rdr[x].type == cmp->rd[IN].type)
	res = (rdr[x].pipe(cmp) ? 1 : res);
      x += 1;
    }
  return (res);
}
