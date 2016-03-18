/*
** pipeit.c for pipeit in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Mar 18 15:22:06 2016 alies_a
** Last update Fri Mar 18 16:14:40 2016 alies_a
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"
#include "my.h"

t_rdr in[] = {
  {&in_simple, '>'},
  {NULL, 0}
};

int	in_simple(const t_cmp *cmp)
{
  int	fd;

  if ((fd = open(cmp->input_file, O_RDONLY)) == -1)
    return (1);
  if (dup2(fd, 0) == -1)
    return (1);
  return (0);
}

int	pipeitin(const t_cmp *cmp)
{
  int	x;

  if (cmp->input_type == '\0')
    return (0);
  x = 0;
  while (in[x].pipe != NULL)
    {
      if (in[x].type == cmp->input_type)
	return ((in[x].pipe)(cmp));
      x += 1;
    }
  return (1);
}
