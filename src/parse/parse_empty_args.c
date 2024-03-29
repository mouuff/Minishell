/*
** cmp_empty.c for empty in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Mar 24 14:28:25 2016 alies_a
** Last update Thu Mar 24 18:42:06 2016 alies_a
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int	parse_empty_args(t_cmp *cmp)
{
  char	**args;
  int	x;
  int	valid;
  int	len;

  args = cmp->args;
  valid = 0;
  len = my_array_len(args);
  x = len - 1;
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
  if (my_array_len(args) == 1 && my_strlen(args[0]) == 0)
    return (1);
  return (0);
}
