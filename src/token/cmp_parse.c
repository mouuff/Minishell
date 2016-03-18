/*
** cmd_parse.c for cmd parse in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Mar 18 11:15:27 2016 alies_a
** Last update Fri Mar 18 11:31:40 2016 alies_a
*/

#include <stdlib.h>
#include "mysh.h"

static int	rm_empty_args(char **args)
{
  int		x;
  int		valid;

  valid = 0;
  x = my_array_len(args) - 1;
  while (x > 0)
    {
      if (my_strlen(args[x]) > 0)
	valid = 1;
      if (valid == 0)
	{
	  free(args[x]);
	  args[x] = NULL;
	}
      x -= 1;
    }
  return (0);
}

static int	cmp_parse(t_cmp *cmp)
{
  rm_empty_args(cmp->args);
  return (0);
}

int	cmps_parse(t_cmp *cmp)
{
  while (cmp != NULL)
    {
      cmp_parse(cmp);
      cmp = cmp->next;
    }
  return (0);
}
