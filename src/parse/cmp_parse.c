/*
** cmd_parse.c for cmd parse in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Mar 18 11:15:27 2016 alies_a
** Last update Thu Mar 24 15:02:54 2016 alies_a
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

static t_cmp_parse func[] = {
  {"", &rm_empty_args},
  {NULL, NULL}
};

static int	cmp_parse(t_cmp *cmp)
{
  int		x;

  x = 0;
  while (func[x].parse != NULL)
    {
      if (func[x].parse(cmp))
	{
	  my_putstr(func[x].err);
	  return (1);
	}
      x += 1;
    }
  return (0);
}

int	cmps_parse(t_cmp *cmp)
{
  while (cmp != NULL)
    {
      if (cmp_parse(cmp))
	return (1);
      cmp = cmp->next;
    }
  return (0);
}
