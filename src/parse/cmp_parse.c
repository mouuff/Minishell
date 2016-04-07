/*
** cmd_parse.c for cmd parse in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Mar 18 11:15:27 2016 alies_a
** Last update Thu Apr  7 10:30:23 2016 alies_a
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

static t_cmp_parse func[] = {
  {"Missing name for redirect.\n", &parse_redirect},
  {"Ambiguous output redirect.\n", &parse_ambig_out},
  {"Ambiguous input redirect.\n", &parse_ambig_in},
  {"Invalid null command.\n", &parse_empty_args},
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
	  my_puterr(func[x].err);
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
