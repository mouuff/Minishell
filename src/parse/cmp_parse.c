/*
** cmd_parse.c for cmd parse in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Mar 18 11:15:27 2016 alies_a
** Last update Thu Mar 24 14:31:38 2016 alies_a
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

static int	cmp_parse(t_cmp *cmp)
{
  rm_empty_args(cmp->args);
  return (0);
}

int	cmps_parse(t_cmp *cmp)
{
  int	code;

  code = 0;
  while (cmp != NULL)
    {
      if ((code = cmp_parse(cmp)) < 0)
	return (code);
      cmp = cmp->next;
    }
  return (0);
}
