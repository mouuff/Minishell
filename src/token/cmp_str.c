/*
** cmp_str.c for str in /home/alies_a/rendu/PSU_2015_minishell2
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Mar 17 10:35:27 2016 alies_a
** Last update Fri Mar 18 10:31:41 2016 alies_a
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int	cmp_str(const t_token *tok, t_cmp **cmp)
{
  char	*buff;
  int	x;

  x = my_array_len((*cmp)->args) - 1;
  buff = ((*cmp)->args)[x];
  if ((((*cmp)->args)[x] = my_strdcpy(((*cmp)->args)[x], tok->str)) == NULL)
    return (1);
  free(buff);
  return (0);
}

int	cmp_default(const t_token *tok, t_cmp **cmp)
{
  int	x;

  if (is_delimiter(tok->str[0]))
    {
      x = my_array_len((*cmp)->args) - 1;
      if (my_strlen(((*cmp)->args)[x]) == 0)
	return (0);
      if (my_array_add(&((*cmp)->args), "") == NULL)
	return (1);
    }
  else
    {
      cmp_str(tok, cmp);
    }
  return (0);
}
