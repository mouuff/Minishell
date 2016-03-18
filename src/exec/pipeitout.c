/*
** pipeit.c for pipeit in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Mar 18 15:22:06 2016 alies_a
** Last update Fri Mar 18 16:18:09 2016 alies_a
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"
#include "my.h"

t_rdr out[] = {
  {&out_simple, '>'},
  {NULL, 0}
};

int	out_simple(const t_cmp *cmp)
{
  int	fd;

  if ((fd = open(cmp->output_file, O_WRONLY | O_CREAT,
		 0644)) == -1)
    return (1);
  if (dup2(fd, 1) == -1)
    return (1);
  return (0);
}

int	pipeitout(const t_cmp *cmp)
{
  int	x;

  if (cmp->output_type == '\0')
    return (0);
  x = 0;
  while (out[x].pipe != NULL)
    {
      if (out[x].type == cmp->output_type)
	return ((out[x].pipe)(cmp));
      x += 1;
    }
  return (1);
}
